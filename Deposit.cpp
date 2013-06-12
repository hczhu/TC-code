#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <cstring>
#include <complex>
#include <numeric>
#include <functional>
#define NDEBUG
#include <cassert>
#include <limits>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<b;++i)
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
#define SZ(vec) ((int)(vec).size())
//#define All(vec) (vec).begin(),(vec).end()
/*********************************
 Tips
 * Binary search
 * Ternary search
 * Bitwise tricks
 * Bipartite matching
 * Graph algorithms
 * DP
 * Subset DP
 * Greedy algorithms
 * Network flow
 * Construct the solution directly
 * Be careful to the input constraints
 * Corner cases.
**********************************/
template<typename T>
class point2D : public complex<T> {
  public:
  point2D(const T& x=T(),const T& y=T()):complex<T>(x,y){};
  point2D(const complex<T>& comp):complex<T>(comp){};
  point2D operator=(const complex<T>& comp){
    complex<T>::real()=comp.real();
    complex<T>::imag()=comp.imag();
    return *this;
  };
  T& x() {
    return complex<T>::real();
  }
  T& y() {
    return complex<T>::imag();
  }
};

typedef point2D<double> dpoint2D ;
typedef dpoint2D dpoint;
template<typename T>
int lineSegmentIntersection(point2D<T> p1,point2D<T> p2,
		double a,double b,double c,dpoint2D& inter)
{
  const double EPS=1e-20;
	double de=1.0*(p2.x()-p1.x())*a+1.0*(p2.y()-p1.y())*b;
	double no=-c-a*p1.x()-b*p1.y();
	if(fabs(de)<EPS)return fabs(no)<EPS?2:0;
	double t=no/de;
	if(t<-EPS||t>1.0+EPS)return 0;
	inter.x()=t*(p2.x()-p1.x())+p1.x();
	inter.y()=t*(p2.y()-p1.y())+p1.y();
	return 1;
}
//Convert line form from (p1,p2) to a*x+b*y+c=0
template<typename T,typename A>
void convert(point2D<T> p1,point2D<T> p2,A& a,A& b,A& c)
{
	a=((A)p2.y()-(A)p1.y());
	b=((A)p1.x()-(A)p2.x());
	c=(A)p1.y()*((A)p2.x()-p1.x())-(A)p1.x()*((A)p2.y()-p1.y());
}
typedef point2D<int> point;
typedef pair<dpoint,dpoint> ppt;
void cut_segments(queue<ppt>& seg,double ka,double kb,double kc) {
  dpoint cut;
  for(int k=seg.size();k--;) {
    ppt one=seg.front();seg.pop();
    //debug(one.first);
    //debug(one.second);
    int res=lineSegmentIntersection(one.first,one.second,ka,kb,kc,cut);
    if(res==1) {
      if(norm(cut-one.first)>1e-15)
        seg.push(ppt(one.first,cut));
      if(norm(cut-one.second)>1e-15)
        seg.push(ppt(one.second,cut));
    }
    else {
      seg.push(one);
    }
  }
}
class Deposit {
	public:
	 double successProbability(vector <int> siteX, vector <int> siteY, vector <int> depositX, vector <int> depositY) {
		 debug("Start calculation.");
     vector<point> outer,inner;

     queue<ppt> seg;
     Rep(i,SZ(depositX)) {
       inner.push_back(point(depositX[i],depositY[i]));
     }
     Rep(i,SZ(siteX)) {
       outer.push_back(point(siteX[i],siteY[i]));
     }
     outer.push_back(outer[0]);
     For(i,1,SZ(outer)) {
       dpoint2D a(outer[i].x(),outer[i].y());
       dpoint2D b(outer[i-1].x(),outer[i-1].y());
       seg.push(ppt(a,(a+b)/2.0));
       seg.push(ppt(b,(a+b)/2.0));
     }
     debug(seg.size());
     outer.pop_back();
     For(i,0,SZ(outer))Rep(j,SZ(outer)) {
      dpoint2D a(outer[i].x(),outer[i].y());
      dpoint2D b(outer[j].x(),outer[j].y());
      dpoint mid((a+b)/2.0);
      double ka,kb,kc;
      convert(mid,dpoint((mid+(a-b)*dpoint(0,1))),ka,kb,kc);
      cut_segments(seg,ka,kb,kc);
      debug(i);
      debug(seg.size());
     }
     Rep(i,SZ(outer))Rep(j,SZ(inner)) {
       dpoint2D a(outer[i].x(),outer[i].y());
       dpoint2D b(inner[j].x(),inner[j].y());
       double ka,kb,kc;
       convert(a,b,ka,kb,kc);
       cut_segments(seg,ka,kb,kc);
       debug(i);debug(j);debug(seg.size());
     }
     double tot=0.0,good=0.0;
     inner.push_back(inner[0]);
     while(!seg.empty()) {
       ppt pp=seg.front();seg.pop();
       tot+=sqrt(norm(((pp.first-pp.second))));
       dpoint mid=(pp.first+pp.second)/2.0;
       int further=0;
       Rep(i,SZ(outer)) {
         if(norm((dpoint(outer[further].x(),outer[further].y())-mid))<
             norm(dpoint(outer[i].x(),outer[i].y())-mid)) further=i;
       }
       //cerr<<pp.first<<"--"<<pp.second<<" to "<<outer[further]<<endl;
       double ka,kb,kc;
       convert(mid,dpoint(outer[further].x(),outer[further].y()),ka,kb,kc);
       dpoint tmp;
       For(i,1,SZ(inner)) {
         if(lineSegmentIntersection(inner[i],inner[i-1],ka,kb,kc,tmp)) {
           good+=sqrt(norm(pp.first-pp.second));
           debug("good one");
           break;
         }
       }
     }
     return good/tot;
	}
};
