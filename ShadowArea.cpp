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
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
typedef long long int llint;
typedef int ptype;
typedef complex<ptype> point;
typedef complex<double> dcomp;
const double EPS=1e-10;
#define x() real()
#define y() imag()
int sigcross(llint x1,llint y1,llint x2,llint y2,llint x3,llint y3)
{
	llint re=(llint)(x1-x3)*(y2-y3)-(llint)(y1-y3)*(x2-x3);
	if(re<0)return -1;
	if(re>0)return 1;
	return 0;
}
template<typename T>
llint llcross(complex<T> p1,complex<T> p2)
{
	return (llint)p1.x()*(llint)p2.y()-(llint)p2.x()*(llint)p1.y();
}
template<typename T>
int sigcross(complex<T> p1,complex<T> p2)
{
	llint re=llcross(p1,p2);
	if(re<0)return -1;
	if(re>0)return 1;
	return 0;
}
template<typename T>
double dcross(complex<T> p1,complex<T> p2)
{
	return 1.0*p1.x()*p2.y()-p2.x()*p1.y();
}
template<typename T>
bool linesIntersection
(complex<T> p1,complex<T> p2,complex<T> p3,
			complex<T> p4,complex<double>& p)
{
	if(fabs(dcross(p1-p2,p3-p4))<EPS)return false;
	double t=dcross(p3-p1,p3-p4)/dcross(p2-p1,p3-p4);
	p.x()=1.0*p1.x()+1.0*(p2.x()-p1.x())*t;
	p.y()=1.0*p1.y()+1.0*(p2.y()-p1.y())*t;
	return true;
}

//The two segments must have only one intersection
//Find the intersection of two segments (p1,p2) and (p3,p4)
//Return 0: no intersection.
//Return 1: one intersection.
//Return 2: infinite intersection. overlap.

template<typename T>
int segmentsIntersection
(complex<T> p1,complex<T> p2,complex<T> p3,complex<T> p4,complex<double>& inter)
{
	if(sigcross(p3-p1,p2-p1)*sigcross(p2-p1,p4-p1)<0)return 0;
	if(sigcross(p1-p3,p4-p3)*sigcross(p4-p3,p2-p3)<0)return 0;
	if(sigcross(p2-p1,p3-p1)==0&&sigcross(p2-p1,p4-p1)==0)
	{
		if(p1.x()==p2.x())
		{
			if(p1.y()>p2.y())swap(p1,p2);
			if(p3.y()>p4.y())swap(p3,p4);
			int ly=max(p1.y(),p3.y());
			int hy=min(p2.y(),p4.y());
			if(ly>hy)return 0;
			if(ly<hy)return 2;
			inter=p2;
			return 1;
		}
		else
		{
			if(p1.x()>p2.x())swap(p1,p2);
			if(p3.x()>p4.x())swap(p3,p4);
			int lx=max(p1.x(),p3.x());
			int hx=min(p2.x(),p4.x());
			if(lx>hx)return 0;
			if(lx<hx)return 2;
			inter=p2;
			return 1;
		}
	}
	linesIntersection(p1,p2,p3,p4,inter);
	return 1;
}
point base;
bool cmpAngle(const point& p1,const point& p2)
{
	return atan2(p1.y()-base.y(),p1.x()-base.x())<
		atan2(p2.y()-base.y(),p2.x()-base.x());
}

class ShadowArea {
	public:
	double area(vector <string> room) 
	{
		const int n=room.size();
		const int m=room[0].length();
		point light;
		vector<point> cut,begin,end;
		double all=n*m;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int x=2*i,y=2*j;
			if(room[i][j]=='*')light.x()=x+1,light.y()=y+1;
			else if(room[i][j]=='#')
			{
				all-=1.0;
				cut.push_back(point(x,y));
				cut.push_back(point(x+2,y));
				cut.push_back(point(x,y+2));
				cut.push_back(point(x+2,y+2));
				begin.push_back(point(x,y)),end.push_back(point(x+2,y));
				begin.push_back(point(x+2,y)),end.push_back(point(x+2,y+2));
				begin.push_back(point(x+2,y+2)),end.push_back(point(x,y+2));
				begin.push_back(point(x,y+2)),end.push_back(point(x,y));
			}
		}
		begin.push_back(point(0,0)),end.push_back(point(0,2*m));
		begin.push_back(point(0,2*m)),end.push_back(point(2*n,2*m));
		begin.push_back(point(2*n,2*m)),end.push_back(point(2*n,0));
		begin.push_back(point(2*n,0)),end.push_back(point(0,0));
		
		cut.push_back(point(0,0));
		cut.push_back(point(2*n,0));
		cut.push_back(point(2*n,2*m));
		cut.push_back(point(0,2*m));

		debug(cut.size());
		debug(begin.size());
		base=light;
		debug(light);
		sort(cut.begin(),cut.end(),cmpAngle);
		cut.push_back(cut[0]);
		vector<point> origin=cut;
		for(int i=0;i<cut.size();i++)
		{
			int kk=1;
			assert(cut[i]!=light);
			if(cut[i].x()-light.x())kk=5100/abs(cut[i].x()-light.x());
			else if(cut[i].y()-light.y())kk=5100/abs(cut[i].y()-light.y());
			cut[i]=cut[i]+kk*(cut[i]-light);
		}
		double sum=0.0;
		dcomp dlight(light.x(),light.y());
		for(int i=1;i<cut.size();i++)
		{
			if(0==llcross(cut[i-1]-light,cut[i]-light))
				continue;
			hline();
			cerr<<origin[i-1]<<"---"<<origin[i]<<endl;
			double cover=2*n*2*m;
			bool found=false;
			for(int j=0;j<begin.size();j++)
			{
				dcomp inter1,inter2;
				if(1==segmentsIntersection(light,cut[i-1],begin[j],end[j],inter1)&&
					1==segmentsIntersection(light,cut[i],begin[j],end[j],inter2))
				{
					double s=fabs(dcross(inter1-dlight,inter2-dlight))/2;
					cerr<<inter1<<" "<<inter2<<" "<<dlight<<"="<<s<<endl;
					cover=min(cover,s);
					found=true;
				}
			}
			sum+=cover;
			cerr<<i<<" "<<cover<<endl;
			assert(found);
		}
		sum/=4;
		return all-sum;
	}
};
/*
int main()
{
	ShadowArea ss;
	string s;
	vector<string> room;
	while(cin>>s)
	{
		room.push_back(s);
	}
	cout<<ss.area(room)<<endl;
	return 0;
}
*/


// Powered by FileEdit
