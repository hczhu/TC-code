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
//*******************************************
typedef long long int llint;
const int N=1000;
llint dp1[1001][2001],dp2[1001][2001];
class TheMoviesLevelThreeDivOne {
//Review your code before submission!!!!
	public:

	void clear(llint (*dp)[2001],int low,int up)
	{
		for(int i=0;i<=up;i++)
		for(int j=low;j<=up;j++)
			dp[i][j-low]=0;
	}
	long long count_bad(vector <int> xx, vector <int> yy) 
	{	
		llint (*pre)[2001]=dp1;
		llint (*next)[2001]=dp2;
		int low=-accumulate(xx.begin(),xx.end(),0);
		int up=accumulate(yy.begin(),yy.end(),0);
		debug(low);
		debug(up);
		const int n=xx.size();
		clear(pre,low,up);
		pre[0][-low]=1;
		for(int k=0;k<n;k++)
		{
			hline();
			debug(k);
			clear(next,low,up);
			int x=xx[k],y=yy[k];
			for(int a=0;a<=up;a++)
			for(int b=low;b<=up;b++)
			{
				llint add=pre[a][b-low];
				if(add==0)continue;
				int na,nb;
				na=max(0,a-x);nb=b-x;
				next[na][nb-low]+=add;
				na=max(a,b+y);nb=b+y-x;
				next[na][nb-low]+=add;
			}
			swap(pre,next);
			/*
			for(int a=0;a<=up;a++)
			for(int b=low;b<=up;b++)
			{
				int add=pre[a][b-low];
				if(add==0)continue;
				cerr<<a<<" "<<b<<"="<<add<<endl;
			}*/

		}
		llint ret=0;
		for(int i=1;i<=up;i++)
		for(int j=low;j<=up;j++)
			ret+=pre[i][j-low];
		debug(ret);
		return ret;

	}
	long long find(vector <int> xx, vector <int> yy) 
	{
	/*	while(xx.size()<50)
			xx.push_back(10+(rand()%11)),
			yy.push_back(10+(rand()%11));*/
		llint ret=((llint)1)<<xx.size();
		ret-=count_bad(xx,yy)+count_bad(yy,xx);
		return ret;
	}
};

