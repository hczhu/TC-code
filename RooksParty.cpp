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
const llint mod=1000000009;
llint com[901][901];
template<typename T,int N>
void init_bino(T com[N][N],bool take_mod=false,long long int mod=1000000000000000000LL)
{
	if(take_mod)
	{
		assert(mod>0);
		com[0][0]=1%mod;
		for(int i=1;i<N;i++)
		{
			com[i][0]=com[i][i]=1%mod;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
		}
	}
	else
	{
		com[0][0]=1;
		for(int i=1;i<N;i++)
		{
			com[i][0]=com[i][i]=1;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j]);
		}
	}
}

llint ff[31][31][901],dp[31][31][31];
class RooksParty {
	public:
	int countArrangements(int n, int m, vector <int> counts) 
	{
		init_bino(com,true,mod);
		for(int i=0;i<31;i++)ff[0][i][0]=1;

		for(int i=1;i<=30;i++)
		for(int j=1;j<=30;j++)
		for(int k=1;k<=900;k++)
		{
			llint& s=ff[i][j][k];
			for(int a=1;a<=k&&a<=j;a++)
			{
				s+=ff[i-1][j][k-a]*com[j][a];
				s%=mod;
			}
		}
		debug(ff[2][2][2]);
		debug(ff[2][2][3]);
		debug(ff[2][2][4]);
		debug(ff[3][3][4]);
		debug(ff[3][3][3]);

		for(int i=30;i;i--)
		for(int j=30;j;j--)
		for(int k=900;k;k--)
		{
			llint& s=ff[i][j][k];
			for(int a=1;a<j;a++)
			{
				if(a&1)
				{
					s+=(mod-ff[i][j-a][k])*com[j][a];
				}
				else
				{
					s+=ff[i][j-a][k]*com[j][a];
				}
				s%=mod;
			}
		}
		debug(ff[2][2][2]);
		debug(ff[2][2][3]);
		debug(ff[2][2][4]);
		debug(ff[3][3][4]);
		debug(ff[3][3][3]);
		llint ans=0;
		dp[n][m][0]=1;
		for(int i=0;i<counts.size();i++)
		{
			const int p=counts[i];
			for(int r=1;r<=n;r++)
			for(int c=1;c<=m;c++)
			{
				const llint add=dp[r][c][i];
				if(0==add)continue;
				for(int a=1;a<=r;a++)
				for(int b=1;b<=c;b++)
				{
					llint t=com[r][a]*com[c][b]%mod;
					t=t*ff[a][b][p]%mod;
					t=t*add%mod;
		//			cerr<<a<<" "<<b<<" "<<p<<"="<<ff[a][b][p]<<endl;;
					dp[r-a][c-b][i+1]+=t;
					dp[r-a][c-b][i+1]%=mod;
				}
			}
		}
		for(int r=0;r<=n;r++)
		for(int c=0;c<=m;c++)ans+=dp[r][c][counts.size()];
		ans%=mod;
		return ans;
	}
};

/*
int main()
{
	RooksParty rook;
	vector<int> all;
	for(int i=0;i<10;i++)all.push_back(30);
	cout<<rook.countArrangements(30,30,all)<<endl;
	return 0;
}
*/
