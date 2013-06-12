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
#define x() real()
#define y() imag()
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
bool pointCmp(const complex<T>& p1,const complex<T>& p2)
{
	return p1.x()<p2.x()||(p1.x()==p2.x()&&p1.y()<p2.y());
}

// nocolinear=true means remove all points on the edges of convex hull.
vector<point> convexHull(const vector<point>& all,bool nocolinear=true)
{
	//sort(all.begin(),all.end(),pointCmp<ptype>);
	vector<int>  qq;
	qq.push_back(0);
	int cut=1;
	if(nocolinear)cut=0;
	for(int i=1;i<all.size();i++)
	{
		while(qq.size()>=2&&sigcross(all[i]-all[qq.back()],
					all[qq.back()]-all[qq[qq.size()-2]])>=cut)
			qq.pop_back();
		qq.push_back(i);
	}
	vector<point> res;
	for(int i=0;i<qq.size();i++)res.push_back(all[qq[i]]);
	qq.clear();
	qq.push_back(all.size()-1);
	for(int i=all.size()-2;i>=0;i--)
	{
		while(qq.size()>=2&&sigcross(all[i]-all[qq.back()],
									all[qq.back()]-all[qq[qq.size()-2]])>=cut)
			qq.pop_back();
		qq.push_back(i);
	}
	for(int i=1;i+1<qq.size();i++)res.push_back(all[qq[i]]);
	return res;
}
bool pointInConvex(const vector<point>& convex,point p)
{
	const int n=convex.size();
	for(int i=0;i<n;i++)
		if(sigcross(p-convex[i],convex[(i+1)%n]-convex[i])*
				sigcross(convex[(i+1)%n]-convex[i],convex[(i+2)%n]-convex[i])>0)
			return false;
	return true;
}
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
const int N=15;
vector<int> convex[1<<N]; 
int bufa[1<<N],bufb[1<<N];
class AlmostConvexPolygons {
	public:
	int count(vector <int> x, vector <int> y) 
	{
		const int n=x.size();
		vector<point> all;
		for(int i=0;i<n;i++)all.push_back(point(x[i],y[i]));
		sort(all.begin(),all.end(),pointCmp<int>);
		map<pair<int,int>,int>  flag;
		for(int i=0;i<n;i++)flag[make_pair(all[i].x(),all[i].y())]=i;
		for(int i=0;i<n;i++)cerr<<all[i]<<endl;
		int res=0;
		for(int mk=1;mk<two(n);mk++)
		{
			vector<point> sub;
			for(int i=0;i<n;i++)
				if(mk&two(i))sub.push_back(all[i]);
			if(sub.size()<3)continue;
			vector<point> tmp=convexHull(sub);
			if(tmp.size()==sub.size())
			{
				res++;
				for(int i=0;i<tmp.size();i++)
					convex[mk].push_back(flag[make_pair(tmp[i].x(),tmp[i].y())]);
			}
		}
		set<vector<int> >  mem;
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
		{
			int sa=0,sb=0;
			for(int i=0;i<n;i++)
			{
				if(i==a||i==b)continue;
				if(sigcross(all[b]-all[a],all[i]-all[a])>0)sa^=two(i);
				else sb^=two(i);
			}
			int ta=0,tb=0;
			for(int s=sa;s;s--,s&=sa)
				if(!convex[s^two(a)^two(b)].empty())
					bufa[ta++]=s;
			for(int s=sb;s;s--,s&=sb)
				if(!convex[s^two(a)^two(b)].empty())
					bufb[tb++]=s;
			hline();
			debug(a);
			debug(b);
			for(int x=0;x<ta;x++)
			for(int y=0;y<tb;y++)
			{
				int mk=bufa[x]^bufb[y]^two(a)^two(b);
				if(convex[mk].size())continue;
				debug(bufa[x]);
				debug(bufb[y]);
				vector<int>&  ll=convex[bufa[x]^two(a)^two(b)];
				vector<int>&  rr=convex[bufb[y]^two(a)^two(b)];
				vector<int> almost;
				bool f=true;
				for(int i=0;i<ll.size();i++)
				{
					almost.push_back(ll[i]);
					if(f&&(ll[i]==a||ll[i]==b))
					{
						f=false;
						rotate(rr.begin(),find(rr.begin(),rr.end(),ll[i]),rr.end());
						assert(rr.back()+ll[i]==a+b);
						for(int j=1;j+1<rr.size();j++)almost.push_back(rr[j]);
					}
				}
				rotate(almost.begin(),min_element(almost.begin(),almost.end()),almost.end());
				mem.insert(almost);
				debug(almost.size());
			}
		}
		return res+mem.size();
	}
};
