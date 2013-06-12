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
#define Two(x)  ((1)<<(x))
vector<int> x,y;
int dp[51][1<<16];
int pre[51][1<<9];
int next[51][1<<9];
const int inf=10000;
const int L=16;
int DP(int k,int mk)
{
  int& res=dp[k][mk];
  if(res>=0)return res;
  res=inf;
  if(k==x.size()) {
    for(int i=0;i<8&&i<k;i++) {
      if(y[k-i-1]>pre[k-i-1][(mk>>i)&(Two(9)-1)]+next[k-i-1][(mk&(Two(i+1)-1))<<(9-(i+1))])
        return (res=inf);
    }
    return (res=0);
  }
  int nmk=(mk<<1)&(Two(16)-1);
  if(k-8<0||y[k-8]<=pre[k-8][mk>>7]+next[k-8][nmk&(Two(9)-1)]) {
    res=min(res,DP(k+1,nmk));
  }
  nmk^=1;
  if(k-8<0||y[k-8]<=pre[k-8][mk>>7]+next[k-8][nmk&(Two(9)-1)]) {
    res=min(res,DP(k+1,nmk)+1);
  }
	return res;
}
class Bribes {
	public:
	int minBribes(vector <int> x, vector <int> y) 
	{
		::x=x;
		::y=y;
    const int n=x.size();
    for(int i=0;i<n;i++)
    for(int mk=0;mk<Two(9);mk++) {
      for(int j=0;j<9&&j<=i;j++)if((mk&Two(j)))pre[i][mk]+=x[i-j]>>j;
      for(int j=7;i+8-j<n&&j>=0;j--)if(mk&Two(j))next[i][mk]+=x[i+8-j]>>(8-j);
    }
    memset(dp,0xff,sizeof(dp));
		int ans=DP(0,0);
		if(ans>x.size())return -1;
		return ans;
	}
};
