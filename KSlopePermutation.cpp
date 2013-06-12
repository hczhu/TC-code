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

const int N=21;
llint dp[N][N][N];
bool exist[N][N][N];
llint DP(int x,int s,int a,int b,int n,int k,int f)
{
	if(x==n)return s==k?1:0;
	if(x==f)return DP(x+1,s+(f?1:0),0,a+b,n,k,f);
	if(exist[x][s][a])return dp[x][s][a];
	llint& res=dp[x][s][a];
	exist[x][s][a]=true;
	res=0;
	for(int i=0;i<b;i++)res+=DP(x+1,s,a+i,b-1-i,n,k,f);
	for(int i=0;i<a;i++)res+=DP(x+1,s+1,i,b+a-1-i,n,k,f);
	cerr<<x<<" "<<s<<" "<<a<<" "<<b<<" "<<res<<endl;
	return res;
}
class KSlopePermutation {
//Review your code before submission!!!!
	public:
	long long getCount(int n, int k, int f) 
	{
		return DP(0,0,0,n-1,n,k,f);
	}
};
/*
int main()
{
	int n,k,f;
	cin>>n>>k>>f;
	KSlopePermutation ks;
	cout<<ks.getCount(n,k,f)<<endl;
	return 0;
}
*/
