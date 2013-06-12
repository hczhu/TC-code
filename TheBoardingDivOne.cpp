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
typedef long long int llint;
bool exist[1<<18];
llint dp[1<<18];
int have[20];
int cap;
int can;
llint DP(int mk,int pos,int n)
{
	if(pos==n)return 1;
	if(exist[mk])return dp[mk];
	llint& res=dp[mk];
	res=0;
	exist[mk]=true;
	int low=0,high=n-1;
	if(have[pos]>=0)low=high=have[pos];
	for(int x=low;x<=high;x++)
	{
		if(0==(two(x)&can)&&(x!=have[pos]))continue;
		if(two(x)&mk)continue;
		int cnt=1;
		for(int i=0;i<x;i++)if(two(i)&mk)cnt++;
		if(cnt*74+pos+x+1>cap)continue;
		res+=DP(mk^two(x),pos+1,n);
	}
	cerr<<mk<<" "<<pos<<"="<<res<<endl;
	return res;
}
class TheBoardingDivOne {
	public:
	long long find(vector <int> pattern, int boardingTime) 
	{
		cap=boardingTime;
		const int n=pattern.size();
		for(int i=0;i<n;i++)have[i]=pattern[i]-1;
		reverse(have,have+n);
		can=two(n)-1;
		for(int i=0;i<n;i++)
			if(have[i]>=0)can^=two(have[i]);
		return DP(0,0,n);
	}
};
int main()
{
	TheBoardingDivOne the;
	int n;
	cin>>n;
	vector<int> all(n);
	for(int i=0;i<n;i++)cin>>all[i];
	int t;
	cin>>t;
	cout<<the.find(all,t)<<endl;
	return 0;
}
