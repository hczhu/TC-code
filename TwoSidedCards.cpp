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
const llint mod=1000000007;

llint dp[51][51];
llint cycle[100][100],line[100][100];
bool used[100];
class TwoSidedCards {
	public:
	int theCount(vector <int> taro, vector <int> hanako) 
	{
		const int n=taro.size();
		for(int i=0;i<=n;i++)
			cycle[i][0]=1,line[i][0]=i;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			line[i][j]=0;
			for(int k=1;k<i;k++)
			{
				line[i][j]+=k*line[i-k-1][j-1];
				line[i][j]%=mod;
			}
		}
		for(int i=1;i<=n;i++)
			cycle[i][1]=i*(i-1);
		for(int i=2;i<=n;i++)
		for(int j=2;j<=i;j++)
		{
			for(int a=0;a+1<i;a++)
			for(int b=a?i-1:i-2;b>a;b--)
			{
				if(a+1==b)continue;
				cycle[i][j]+=(i-1-b+a)*line[b-a-1][j-2];
				cycle[i][j]%=mod;
			}
		}

		vector<int> all;
		for(int i=0;i<n;i++)
		{
			if(used[taro[i]])continue;
			used[taro[i]]=true;
			int cnt=1;
			for(int j=hanako[i];!used[j];)
			{
				used[j]=true;
				cnt++;
				int pos=(find(taro.begin(),taro.end(),j)-taro.begin());
				assert(pos<n);
				j=hanako[pos];
			}
			debug(cnt);
			if(cnt==1)continue;
			all.push_back(cnt);
		}
		debug(all.size());
		dp[0][0]=1;
		for(int i=1;i<=all.size();i++)
		{
			dp[i][0]=1;
			for(int j=1;j<=n;j++)
			for(int k=0;k<=j;k++)
				dp[i][j]+=dp[i-1][j-k]*cycle[all[i-1]][k]%mod,dp[i][j]%=mod;
		}
		assert(dp[all.size()][n/2+1]==0);
		vector<llint> fact(n+1);
		fact[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(i&1)fact[0]*=i;
			else fact[0]*=i>>1;
			fact[0]%=mod;
		}
		for(int i=1;i<=n;i++)fact[i]=(fact[i-1]<<1)%mod;
		debug(fact[0]);
		debug(fact[1]);
		debug(fact[2]);
		llint ans=0;
		for(int i=0;i<=n/2;i++)
		{
			llint t=dp[all.size()][i]*fact[n/2-i];
			debug(i);
			debug(dp[all.size()][i]);
			debug(fact[n/2-i]);
			debug(t);
			ans+=t;
		}
		ans%=mod;
		return ans;
	}
};
/*
int main()
{
	return 0;
}
*/
