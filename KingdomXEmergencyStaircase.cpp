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
//#define NDEBUG
#include <cassert>
#include <limits>
#include <cstdarg>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Make_vector(vec,...) do{typedef typeof(vec) _T;const _T::value_type _tmp[]={ __VA_ARGS__ };vec=_T(_tmp,_tmp+sizeof(_tmp)/sizeof(_tmp[0]));}while(0)

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
class point2D
{
	public:
	T _x,_y;
	T x()const{return _x;};
	T& x(){return _x;};
	T y()const{return _y;};
	T& y(){return _y;};
	point2D(){};
	point2D(T x,T y):_x(x),_y(y){};
	point2D(T x):_x(x),_y(0){};
	point2D(const point2D& other):_x(other._x),_y(other._y){};
	const point2D& operator=(const point2D<T>& other){_x=other._x,_y=other._y;return *this;};
	bool operator==(const point2D<T>& other)const{return _x==other._x&&_y==other._y;};
	double length()const {return sqrt(1.0*_x*_x+1.0*_y*_y);};
	double dnorm()const {return 1.0*_x*_x+1.0*_y*_y;};
	T norm()const
	{
		return	_x*_x+_y*_y;
	};
	bool operator<(const point2D& other)const
	{
		return x()<other.x()||(x()==other.x()&&y()<other.y());
	}
	point2D operator+=(const point2D& other)
	{
		_x+=other._x;
		_y+=other._y;
		return *this;
	};
	point2D operator+(const point2D& other)const
	{
		point2D res=*this;
		res+=other;
		return res;
	};
	
	point2D operator-=(const point2D& other)
	{
		_x-=other._x;
		_y-=other._y;
		return *this;
	};
	point2D operator-(const point2D& other)const
	{
		point2D res=*this;
		res-=other;
		return res;
	};

	point2D operator*=(const point2D& other)
	{
		point2D res=(*this)*other;
		*this=res;
		return *this;
	};
	point2D operator*(const point2D& other)const
	{
		point2D res;
		res._x=_x*other._x-_y*other._y;
		res._y=_x*other._y+_y*other._x;
		return res;
	};
	point2D conjugate()const
	{
		return point2D(_x,-_y);
	}
	point2D negate()const
	{
		return point2D(-_x,-_y);
	}
	point2D<double> operator/(const point2D<T>& other)const
	{
		assert(other.dnorm()>0.0);
		point2D<double> res=*this;
		res*=other.conjugate();
		res._x/=other.dnorm();
		res._y/=other.dnorm();
		return res;
	}
	point2D<double> operator/=(const point2D<T>& other)
	{
		*this=(*this)/other;
		return *this;
	}
	point2D<double> operator/(const T& other)
	{
		assert(fabs(1.0*other)>0.0);
		point2D res=*this;
		res._x/=other;
		res._y/=other;
		return res;
	}
	point2D<double> operator/=(T& other)
	{
		*this=(*this)/other;
		return *this;
	}
};
template<typename T>
ostream& operator<<(ostream& out,const point2D<T>& other)
{
	out<<"("<<other.x()<<","<<other.y()<<")";
	return out;
}
typedef point2D<int> point;
// Some functions about lines and segments
template<typename T>
T cross(const point2D<T>& p1,const point2D<T>& p2)
{
	return p1.x()*p2.y()-p1.y()*p2.x();
}
//check intersection of two lines
//Return false if there are infinite intersections
template<typename T>
bool linesIntersection(point2D<T> p1,point2D<T> p2,point2D<T> p3,
			point2D<T> p4,point2D<int>& p)
{
	if(abs(cross(p1-p2,p3-p4))==0)return false;
	int a=cross(p3-p1,p3-p4);
	int b=cross(p2-p1,p3-p4);
	int g=__gcd(abs(a),abs(b));a/=g;b/=g;
	p.x()=p1.x()+(p2.x()-p1.x())*a/b;
	assert((p2.x()-p1.x())*a%b==0);
	assert((p2.y()-p1.y())*a%b==0);
	p.y()=p1.y()+(p2.y()-p1.y())*a/b;
	return true;
}
//Use line start-->end to cut convex
//The half plane of the left side of start-->end is kept
vector<point2D<int> > cut_convex(const vector<point2D<int> >& convex,
			point2D<int> start,point2D<int> end)
{
	vector<point2D<int> > ret;
	const int n=convex.size();
	assert(n>=3);
	vector<int> inside(n,0);
	for(int idx=0;idx<n;idx++)
		inside[idx]=(cross(end-start,convex[idx]-start)>0)?1:0;
//	if(*max_element(inside.begin(),inside.end())==0)return ret;
//	if(*min_element(inside.begin(),inside.end())==1)return convex;
	point2D<int> inter;
	for(int i=0,pre=0,next=0;i<n;i++)
	{
		next=(pre+1)%n;
		if(inside[pre]!=inside[next])
		{
			bool cnt=linesIntersection(start,end,convex[pre],convex[next],inter);
			assert(cnt);
			ret.push_back(inter);
		}
		if(inside[next])ret.push_back(convex[next]);
		pre=next;
	}
	return ret;
}

typedef long long int llint;
llint mem_open[11][101][2];

int width;
string ll,rr;
int cost[100];
const llint inf=100000000000000000LL;
string get_string(const string& build,int y1,int y2) {
	assert(y1<y2);
	assert(0==(y1&1));
	assert(0==(y2&1));
	string res((y2-y1)/2-1,'N');
	assert(0==(y1&1));
	assert(0==(y2&1));
	for(int y=y1+2;y<y2;y+=2) {
		res[(y-y1)/2-1]=(y/2-1<build.length())?build[(y/2-1)]:'N';
	}
	return res;
}
inline void get_lrp(const point& bot,point& lp,point& rp) {
	lp=bot+point(-bot.x(),bot.x());
	rp=bot+point(width-bot.x(),width-bot.x());
}

void normalize(vector<point>& poly) {
	assert(poly[0].x()==poly[1].x());
	assert(poly[0].y()<poly[1].y());

	for(int i=1;i<poly.size();i++) {
		poly[i]-=poly[0];
	}
	poly[0]=point(0,0);
}
bool isGood(const vector<point>& poly) {
	if(poly.empty())return false;
	assert(poly.size()>=3);
	assert(!(poly[0]==poly.back()));
	for(int i=1;i<poly.size();i++)assert(!(poly[i]==poly[i-1]));
	int zero=0;
	for(int i=0;i<poly.size();i++)if(0==poly[i].x())zero++;
	assert(zero<=2);
	return true;
}
string get_string(vector<point>& poly,const string& ext) {
	//debug(poly.size());
	int pos=-1;
	poly.push_back(poly[0]);
	for(int i=1;i<poly.size();i++) {
		if(poly[i].x()==0&&poly[i-1].x()==0) {
			pos=i-1;
			break;
		}
	}
	poly.pop_back();
	if(pos==-1)return "";
	rotate(poly.begin(),poly.begin()+pos,poly.end());
	if(poly[0].y()>poly[1].y()) {
		reverse(poly.begin(),poly.end());
		rotate(poly.begin(),poly.end()-2,poly.end());
	}
	string res;
	assert(0==(poly[0].y()&1));
	assert(0==(poly[1].y()&1));
	for(int y=poly[0].y()+2;y<poly[1].y();y+=2) {
		assert(y/2-1<ext.length());
		res.push_back(ext[y/2-1]);
	}
	return res;
}
void print_poly(const vector<point>& poly) {
	debug(poly.size());
	for(int i=0;i<poly.size();i++) cerr<<poly[i]<<" ";cerr<<endl;
}
map<pair<vector<point>,string >, llint > mem_close;
int get_add(vector<point>& poly1,int C,int dy) {
	poly1.push_back(poly1[0]);
	for(int i=1;i<poly1.size();i++) {
		if(cross(point(dy,-1),poly1[i]-poly1[i-1])==0&&
			C==cross(poly1[i],point(-dy,1))) {
			poly1.pop_back();
			return abs(poly1[i].x()-poly1[i-1].x());
		}
	}
	assert(0);
}
llint dp_close(vector<point>& poly,const string& ext) {
	const string& ex=ext;
	if(ext.find('Y')==string::npos)return 0;
	cerr<<"Gonna solve close: "<<ex<<"#";
	for(int i=0;i<poly.size();i++) {
		cerr<<poly[i]<<" ";
	}cerr<<endl;
	assert(2*ext.length()+2==poly[1].y()-poly[0].y());
	normalize(poly);
	//debug("normalize");
	//print_poly(poly);
	assert(poly[0]==point(0,0)&&poly[1].x()==0);
	if(mem_close.count(make_pair(poly,ex)))return mem_close[make_pair(poly,ex)];
	llint res=inf;
	res=inf;
	//cut the polygon
	// x+dy*y=C
	for(int dy=-1;dy<=1;dy+=2) {
		int low=1000000,high=-1000000;
		for(int i=0;i<poly.size();i++) {
			low=min(low,poly[i].x()+dy*poly[i].y());
			high=max(high,poly[i].x()+dy*poly[i].y());
		}
		for(int C=low+1;C<high;C++) {
			if(C&1)continue;
			vector<point> poly1,poly2;
			poly1=cut_convex(poly,point(0,C/dy),point(C,0));
			poly2=cut_convex(poly,point(C,0),point(0,C/dy));
			if(!isGood(poly1)||!isGood(poly2))continue;
			
			string ext1=get_string(poly1,ext);
			string ext2=get_string(poly2,ext);
			int add=get_add(poly1,C,dy);
			assert(add);
			res=min(res,cost[add]+dp_close(poly1,ext1)+dp_close(poly2,ext2));
		}
	}
	mem_close[make_pair(poly,ex)]=res;
	return res;
}
llint dp_open(point bot,string ll=::ll,string rr=::rr) {
	point lp,rp;
	get_lrp(bot,lp,rp);
	if(string::npos==ll.substr(min(lp.y()/2,(int)ll.length())).find('Y')&&
		string::npos==rr.substr(min((int)rr.length(),rp.y()/2)).find('Y'))return 0;
	llint& res=mem_open[bot.x()][bot.y()][ll==::ll?0:1];
	if(res!=-1)return res;
	res=inf;
	for(int cc=0;cc<2;cc++) {
	for(int x=0;x<bot.x();x++) {
		point nbot=bot+point(x-bot.x(),bot.x()-x);
		point nlp,nrp,lp,rp;
		get_lrp(bot,lp,rp);
		get_lrp(nbot,nlp,nrp);
		vector<point> poly;
		Make_vector(poly,rp,nrp,nbot,bot);
		if(rp==bot)poly.pop_back();
		res=min(res,dp_close(poly,get_string(rr,rp.y(),nrp.y()))+dp_open(nbot,ll,rr)+cost[width-x]);
	}
	swap(ll, rr);
	bot.x()=width-bot.x();
	}
	return res;
}

class KingdomXEmergencyStaircase {
	public:
	 long long determineCost(string leftBuilding, string rightBuilding, vector <int> cost) {
		 debug("Start calculation.");
		 ll=leftBuilding;
		 rr=rightBuilding;
		 for(int i=0;i<cost.size();i++)::cost[i+1]=cost[i];
		 width=cost.size();
		 debug(width);
		 llint ans=inf;
		 //debug(dp_open(point(1,7)));
		 for(int cc=0;cc<2;cc++) {
			swap(ll,rr);
		 	memset(mem_open,0xff,sizeof(mem_open));
			mem_close.clear();
		 	vector<point> poly;
			llint t=dp_open(point(0,0))+::cost[width],adder=0;
			if(string::npos!=get_string(rr,0,width).find('Y')) {
				string ext=get_string(rr,0,width);
				int Y=ext.find('Y')*2+2;
				llint add=0,best=inf;
				for(int y=0;y<=Y;y+=2) {
					add=::cost[width-(width+y)/2];
					Make_vector(poly,point(width,y),point(width,width),point((width+y)/2,(width+y)/2));
					add+=dp_close(poly,ext.substr(y/2));
					best=min(best,add);
				}
				adder=best;
			}
			ans=min(ans,t+adder);
		 }
		 return ans;
	}
};







/*
int main() {

	KingdomXEmergencyStaircase king;
	vector<int> cost;
	typedef typeof(cost) T;
	T::value_type aa=100;
	Make_vector(cost,16292054, 99861481, 150330815, 129488601, 14959603, 15658648, 15669441, 14985100);
	llint t;
	cout<<(t=king.determineCost("Y", "YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",cost))<<endl;
	llint ans=177057809LL;
	debug(ans-t);
	return 0;
}
*/
