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
#include <stack>
#include <stdarg.h>
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
const int N=1000000;
int point[1000000];
int next[1000000];
int st[N];
int get_root(int a)
{
	int top=0;
	while(next[a]!=-1)
	{
		st[top++]=a;
		a=next[a];
	}
	while(top--)
	{
		next[st[top]]=a;
	}
	return a;
}
bool used[1000000];
int getNext(int a)
{
	if(next[a]==-1)return a;
	return next[a]=getNext(next[a]);
}
void generate_all(llint p,llint mod,llint a,llint b,llint c)
{
	memset(next,0xff,sizeof(int)*mod);
	for(llint n=0;n<p;n++)
	{
		llint pos=(a*n*n + b*n + c)%mod;
		pos=getNext(pos);
/*		while(used[pos])
		{
			pos++;
			if(pos==n)pos=0;
		}*/
//		pos=get_root(pos);
		point[n]=pos;
		used[pos]=true;
//		next[pos]=(pos+1)%mod;
	}
}
class RightTriangle {
	public:
	long long triangleCount(int places, int points, int a, int b, int c) 
	{
		generate_all(points,places,a,b,c);
		debug("here");
		const int n=places;
		const int m=points;
//		for(int i=0;i<m;i++)cerr<<point[i]<<" ";cerr<<endl;
		if(n&1)return 0;
		set<int> mem;
		llint res=0;
		for(int i=0;i<m;i++)
		{
			int a=(n/2+point[i])%n;
			if(mem.count(a))res+=m-2;
			mem.insert(point[i]);
		}
		return res;
	}
};
int main()
{
	RightTriangle oo;
	cout<<oo.triangleCount(1000000,100000,0,0,0)<<endl;
	return 0;
}
