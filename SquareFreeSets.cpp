#line 67 "SquareFreeSets.cpp"
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

const int mod=1000000007;
const int small[]={2,3,5,7,11,13,17,19};
const int P=8;
vector<int> prime;
int com[501][501];
bool isPrime(int n)
{
	for(int t=2;t*t<=n;t++)
		if(0==(n%t))return false;
	return true;
}
int dp[9][10];
typedef long long int llint;
int modMult(llint a,llint b,llint mod)
{
	return a*b%mod;
}
int DP(vector<int> num,int up,int k)
{
	sort(num.begin(),num.end());
	reverse(num.begin(),num.end());
	const int n=num.size();
	vector<int> bound(n);
	for(int i=0;i<n;i++)
		for(bound[i]=0;bound[i]<prime.size()&&prime[bound[i]]*num[i]<=up;bound[i]++);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	for(int j=0;j<=i;j++)
	{
		int t=dp[i][j];
		if(0==t)continue;
		dp[i+1][j]+=t;
		dp[i+1][j]%=mod;
		if(bound[i]>j)
		{
			dp[i+1][j+1]+=modMult(t,bound[i]-j,mod);
			dp[i+1][j+1]%=mod;
		}
	}
	int res=0;
	for(int i=0;i<=n&&i<=prime.size();i++)
	{
		int t=dp[n][i];
		for(int j=0;j+n<=k&&j+i<=prime.size();j++)
		{
			int tt=modMult(t,com[prime.size()-i][j],mod);
			res+=tt;
			res%=mod;
		}
	}
	if(n==0)res=(res+mod-1)%mod;
	debug(res);
	return res;
}
void DFS(vector<int> num,int pos,int& ans,int n,int k)
{
	if(pos==P||small[pos]>n)
	{
		ans+=DP(num,n,k);
		ans%=mod;
		return;
	}
	DFS(num,pos+1,ans,n,k);
	if(num.size()<k)
	{
		num.push_back(small[pos]);
		DFS(num,pos+1,ans,n,k);
		num.pop_back();
	}
	for(int i=0;i<num.size();i++)
	{
		if(num[i]*small[pos]<=n)
		{
			num[i]*=small[pos];
			DFS(num,pos+1,ans,n,k);
			num[i]/=small[pos];
		}
	}
}
class SquareFreeSets 
{
	public:
	int countPerfect(int n, int k) 
	{
		for(int t=20;t<=n;t++)
			if(isPrime(t))prime.push_back(t);
		debug(prime.size());
		com[0][0]=1;
		for(int i=1;i<=prime.size();i++)
		{
			com[i][0]=com[i][i]=1;
			for(int j=1;j<i;j++)
				com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
		}
		int ans=0;
		vector<int> num;
		DFS(num,0,ans,n,k);
		return ans;
	}
};


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
