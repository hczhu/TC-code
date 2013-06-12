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
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
 
 
 
#define two(x)  ((1)<<(x))
int dp[1<<15][50];
int hash[1<<15]; 
#define low(x) ((((x)^((x)-1))&x))
class KiwiJuice {
  public:
  int theProfit(int C, vector <int> bottle, vector <int> price) 
  {
    const int n=bottle.size();
	for(int i=0;i<n;i++)hash[two(i)]=i;
    for(int mk=0;mk<two(n);mk++)
	{
		for(int r=0;r<=C;r++)
   	 	{
			int& res=dp[mk][r];
			if(mk==0)
			{
				res=price[r];
				continue;
			}
			for(int s=mk;s;s^=low(s))
			{
				int i=hash[low(s)];
				if(0==(two(i)&mk))continue;
				int rem=r+bottle[i];
				res=max(res,(rem>C?price[C]+dp[two(i)^mk][rem-C]:price[0]+dp[two(i)^mk][rem]));
				res=max(res,price[r]+dp[two(i)^mk][bottle[i]]);
			}
		//	cerr<<mk<<" "<<r<<"="<<res<<endl;
    	}
	}
	int res=0;
	for(int i=0;i<n;i++)
		res=max(res,dp[two(n)-1-two(i)][bottle[i]]);
	return res;
  }
};
