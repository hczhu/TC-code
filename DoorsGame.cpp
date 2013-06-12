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
#define two(x)  ((1)<<(x))
bool exist[2][1<<16];
int dp[2][1<<16];
int DFS(int mk,int a,int b,int idx)
{
	if((a&mk)==a&&(b&mk)==b)return 0;
	if((a&mk)==a)return 1;
	if((b&mk)==b)return -1;
	if(exist[idx][mk])return dp[idx][mk];
	exist[idx][mk]=true;
	int& ret=dp[idx][mk];
	const int inf=10000000;
	int win=inf,lose=-inf,draw=-1;
	for(int i=0;i<16;i++)
	{
		if(two(i)&mk)continue;
		int rec=DFS(two(i)^mk,b,a,idx^1);
		if(rec<0)win=min(win,-rec+1);
		else if(rec==0)draw=0;
		else lose=max(lose,rec+1);
	}
	if(win<inf)ret=win;
	else if(draw==0)ret=0;
	else ret=-lose;
	cerr<<mk<<" "<<idx<<"="<<ret<<endl;
	return ret;
}
class DoorsGame {
	public:
	int determineOutcome(string doors, int trophy) 
	{
		int a=0,b=0;
		for(int i=0;i<trophy;i++)
			a|=two(doors[i]-'A');
		for(int i=trophy;i<doors.length();i++)
			b|=two(doors[i]-'A');
		int ans= DFS(0,a,b,0);
		if(ans>0)ans--;
		else if(ans<0)ans++;
		return ans;
	}
};
