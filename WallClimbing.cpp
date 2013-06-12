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
const double EPS=1e-10;
typedef long long int llint;
typedef double ptype;
typedef complex<ptype> point;
typedef complex<double> dcomp;
#define x() real()
#define y() imag()
const double PI=acos(-1.0);
double mysqrt(double v)
{
	if(v<EPS)return 0.0;
	return sqrt(v);
}
template<typename T>
double dcross(complex<T> p1,complex<T> p2)
{
	return 1.0*p1.x()*p2.y()-p2.x()*p1.y();
}
template<typename T>
double length(complex<T> p)
{
	return sqrt(1.0*p.x()*p.x()+1.0*p.y()*p.y());
}

//Find one intersection of two circles. Return the upper intersection point if x1<x2
template<typename T>
bool circlesIntersection
	( complex<T> p1,T r1,complex<T> p2,T r2,complex<double>& inter)
{
	double dx = p2.x() - p1.x();
	double dy = p2.y() - p1.y();
	double d = mysqrt(dx*dx + dy*dy);
	if(d>r1+r2+EPS||d+EPS<fabs(r1-r2))return false;
	//circle overlap
	if(d<EPS)return false;
	double e = (r1*r1 - r2*r2 + d*d)/(2*d);
	double f = mysqrt(r1*r1 - e*e);
	inter=complex<double>(1.0*p1.x() + (e*dx - f*dy)/d,1.0*p1.y() + (f*dx + e*dy)/d);
	return true;
}

//check intersection of two lines
//Return false if there are infinite intersections
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

bool in_circle(point p,point center,double r)
{
	return length(p-center)<r+EPS;
}

// Find a circle going through the given three points
// Return false if there are an infinite number of such circles or no such circle
bool circle_on_points3(point a,point b,point c,point& center,double& radius)
{
	point ab0=(a+b)/2.0;
	point ab1=(a-b)*point(0.0,1)+ab0;
	
	point ac0=(a+c)/=2.0;
	point ac1=(a-c)*point(0.0,1)+ac0;
	if(!linesIntersection(ab0,ab1,ac0,ac1,center))return false;
	radius=length(center-a);
	return true;
}

bool circle_cover_all_points(point center,double radius,vector<point> all)
{
	for(int i=0;i<all.size();i++)
		if(!in_circle(all[i],center,radius))return false;
	return true;
}

// Find minimum cirlce covering all points
double minimum_cover_circle(vector<point> all,point& center)
{
	const int n=all.size();
	if(n==1)
	{
		center=all[0];
		return 0.0;
	}
	double res=1e30;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		double d=length(all[i]-all[j])/2.0;
		if(d<res&&circle_cover_all_points((all[i]+all[j])/2.0,d,all))
			res=d,center=(all[i]+all[j])/2.0;
		for(int k=j+1;k<n;k++)
		{
			point tmp;
			if(!circle_on_points3(all[i],all[j],all[k],tmp,d))continue;
			if(d<res&&circle_cover_all_points(tmp,d,all))res=d,center=tmp;
		}
	}
	return res;
}
bool check(vector<point> center,double arm,point p)
{
	for(int i=0;i<center.size();i++)
	{
		if(!in_circle(p,center[i],arm))return false;
	}
	return true;
}
void lower_upper(vector<point> all,double arm,double& lower,double& upper)
{
	lower=1e30;
	upper=-1e30;
	point tmp;
	for(int i=0;i<all.size();i++)
	{
		if(check(all,arm,all[i]-point(0.0,arm)))lower=min(lower,all[i].y()-arm);
		if(check(all,arm,all[i]+point(0.0,arm)))upper=max(upper,all[i].y()+arm);
		for(int j=i+1;j<all.size();j++)
		{
			if(circlesIntersection(all[j],arm,all[i],arm,tmp)&&check(all,arm,tmp))
				lower=min(lower,tmp.y()),upper=max(upper,tmp.y());
			if(circlesIntersection(all[i],arm,all[j],arm,tmp)&&check(all,arm,tmp))
				lower=min(lower,tmp.y()),upper=max(upper,tmp.y());
		}
	}
}



bool can[16][16][16][16];
bool visited[16][16][16];
double lower[16][16][16];
double upper[16][16][16];

void DFS(vector<int> hold,double arm,int n,double& ans)
{
	ans=max(ans,upper[hold[0]][hold[1]][hold[2]]+arm);
	visited[hold[0]][hold[1]][hold[2]]=true;
	for(int i=0;i<n;i++)
	{
		if(i==hold[0]||i==hold[1]||i==hold[2])
			continue;
		vector<int> next=hold;
		next.push_back(i);
		sort(next.begin(),next.end());
		if(!can[next[0]][next[1]][next[2]][next[3]])
			continue;
		for(int j=0;j<4;j++)
		{
			vector<int> tmp=next;
			tmp.erase(tmp.begin()+j);
			if(!visited[tmp[0]][tmp[1]][tmp[2]])
				DFS(tmp,arm,n,ans);
		}
	}
}


class WallClimbing {
//Review your code before submission!!!!
	public:
	double maxHeight(vector <int> holdx, vector <int> holdy, int arm) 
	{
		const int n=holdx.size();
		vector<point> all;
		for(int i=0;i<n;i++)all.push_back(point(holdx[i],holdy[i]));
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
		for(int c=b+1;c<n;c++)
		{
			vector<point> all4;
			all4.push_back(all[a]);
			all4.push_back(all[b]);
			all4.push_back(all[c]);
			lower_upper(all4,arm,lower[a][b][c],upper[a][b][c]);
			cerr<<a<<" "<<b<<" "<<c<<" = "<<lower[a][b][c]<<" "<<upper[a][b][c]<<endl;
			for(int d=c+1;d<n;d++)
			{
				point tmp;
				all4.push_back(all[d]);
				can[a][b][c][d]=minimum_cover_circle(all4,tmp)<EPS+arm;
				if(can[a][b][c][d])cerr<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
				all4.pop_back();
			}
		}
		double ans=2.0*arm;
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
		for(int c=b+1;c<n;c++)
		{
			//debug(lower[a][b][c]);
			if(lower[a][b][c]<arm+EPS)
			{
				vector<int> hold;
				hold.push_back(a);
				hold.push_back(b);
				hold.push_back(c);
				cerr<<"DFS "<<a<<" "<<b<<" "<<c<<endl;
				if(!visited[a][b][c])DFS(hold,arm,n,ans);
			}
		}
		return ans;
	}
};
