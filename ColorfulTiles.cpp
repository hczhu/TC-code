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
int hash[1000];
int grid1[100][100];
int grid2[100][100];
llint dp[100][3000];
int get_diff(int col,int x,int y,int n,int grid[100][100])
{
//	assert(n>=2);
	int res=0;
	for(int i=0;i<n;i+=2)
	{
		if(grid[i][col]!=x)res++;
		if(i+1<n&&grid[i+1][col]!=y)res++;
	}
	return res;
}
llint opt[100][4][3000];
llint DP(int n,int m,int a1,int b1,int a2,int b2,int K,int grid[100][100])
{
	
	int a[2]={a1,a2};
	int b[2]={b1,b2};
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=m;i++)
	{
		int x=a[i&1],y=b[i&1];
		int d1=get_diff(i-1,x,y,n,grid);
		int d2=get_diff(i-1,y,x,n,grid);
		for(int j=0;j<=K;j++)
		{
			dp[i][j]=0;
			if(j>=d1)dp[i][j]+=dp[i-1][j-d1];
			if(j>=d2)dp[i][j]+=dp[i-1][j-d2];
			dp[i][j]%=mod;
		}
	}
	llint ans=0;
	for(int i=0;i<=K;i++)ans+=dp[m][i];
	debug(ans);
	return ans%mod;
}
class ColorfulTiles {
	public:
	int theCount(vector <string> room, int K) 
	{
		int n=room.size();
		int m=room[0].length();
		hash['R']=0;
		hash['G']=1;
		hash['B']=2;
		hash['Y']=3;
		if(n==1&&m==1)return K==0?1:4;
		if(n==1)
		{
			for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				grid1[i][j]=hash[room[j][i]],
				grid2[j][i]=hash[room[j][i]];
			swap(n,m);
		}
		else
		{
			for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				grid1[i][j]=hash[room[i][j]],
				grid2[j][i]=hash[room[i][j]];
		}
		if(m==1)
		{
			llint ans=0;
			for(int i=0;i<4;i++)
				opt[1][i][i==grid1[0][0]?0:1]=1;
			for(int i=2;i<=n;i++)
			for(int x=0;x<=K;x++)
			{
				for(int j=0;j<4;j++)
				{
					int d=0;
					if(j!=grid1[i-1][0])d=1;
					if(x<d)continue;
					for(int k=0;k<4;k++)
						if(k!=j)opt[i][j][x]+=opt[i-1][k][x-d];
					opt[i][j][x]%=mod;
				}
			}
			for(int i=0;i<=K;i++)
			for(int j=0;j<4;j++)
				ans+=opt[n][j][i];
			ans%=mod;
			return ans;

		}
		llint ans=0;
		ans+=DP(n,m,0,1,2,3,K,grid1);
		ans+=DP(n,m,0,2,1,3,K,grid1);
		ans+=DP(n,m,0,3,1,2,K,grid1);
		ans+=DP(n,m,1,2,0,3,K,grid1);
		ans+=DP(n,m,1,3,0,2,K,grid1);
		ans+=DP(n,m,2,3,0,1,K,grid1);
		swap(n,m);
		ans+=DP(n,m,0,1,2,3,K,grid2);
		ans+=DP(n,m,0,2,1,3,K,grid2);
		ans+=DP(n,m,0,3,1,2,K,grid2);
		ans+=DP(n,m,1,2,0,3,K,grid2);
		ans+=DP(n,m,1,3,0,2,K,grid2);
		ans+=DP(n,m,2,3,0,1,K,grid2);
		swap(n,m);
		ans%=mod;
		int small[2][2];
		int aa[]={0,1,2,3};
		do
		{
			small[0][0]=aa[0];
			small[0][1]=aa[1];
			small[1][0]=aa[2];
			small[1][1]=aa[3];
			int sum=0;
			for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(grid1[i][j]!=small[i%2][j%2])sum++;
			if(sum<=K)ans+=mod-1;
		}while(next_permutation(aa,aa+4));
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
