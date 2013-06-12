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
typedef complex<int> point;
#define x() real()
#define y() imag()
bool operator<=(const point& a,const point& b)
{
	return make_pair(a.x(),a.y())<=make_pair(b.x(),b.y());
}
const int N=200;
int cross(point a,point b)
{
	return a.x()*b.y()-a.y()*b.x();
}
bool valid(point p,int n,int m)
{
	return p.x()>=0&&p.x()<n&&p.y()>=0&&p.y()<m;
}
llint movecount(point a,point b,point c,int n,int m)
{
	if(cross(a-b,c-b)==0)return 0;
	int x1=min(a.x(),min(b.x(),c.x()));
	int x2=max(a.x(),max(b.x(),c.x()));
	int y1=min(a.y(),min(b.y(),c.y()));
	int y2=max(a.y(),max(b.y(),c.y()));
	//cerr<<"###"<<a<<" "<<b<<" "<<c<<endl;
	if(x2-x1>=n||y2-y1>=m)return 0;
	return (n-x2+x1)*(m-y2+y1);
}


vector<point> square[N*N*2+1];
class IsoscelesTriangles {
	public:
	long long count(int n, int m) 
	{
		for(int x=0;x<n;x++)
		for(int y=0;y<m;y++)
		{
			square[x*x+y*y].push_back(point(x,y));
			if(x)square[x*x+y*y].push_back(point(-x,y));
			if(y)square[x*x+y*y].push_back(point(x,-y));
			if(x&&y)square[x*x+y*y].push_back(point(-x,-y));
		}
		llint res=0;
		point a=point(0,0),b,c;
		for(int s=1;s<=(n-1)*(n-1)+(m-1)*(m-1);s++)
		{
			for(int i=0;i<square[s].size();i++)
			for(int j=i+1;j<square[s].size();j++)
				res+=movecount(a,square[s][i],square[s][j],n,m);
		}
		return res;
	}
};
/*
int main()
{
	int n,m;
	cin>>n>>m;
	IsoscelesTriangles ii;
	cout<<ii.count(n,m)<<endl;
	return 0;

}
*/


// Powered by FileEdit
