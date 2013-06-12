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
#define two(x)  ((1)<<(x))
int dp[30][30][1<<10];

class FourBlocks {
	public:
	int maxScore(vector <string> grid) 
	{
		memset(dp,0xff,sizeof(dp));
		dp[0][0][0]=0;
		const int n=grid.size();
		const int m=grid[0].length();
		for(int j=0;j<m;j++)
		for(int i=0;i<n;i++)
		{
			for(int mk=0;mk<two(n);mk++)
			{
				if(dp[i][j][mk]<0)continue;
				if(grid[i][j]=='1'&&(mk&two(i)))continue;
				//cerr<<i<<" "<<j<<" "<<mk<<"="<<dp[i][j][mk]<<endl;
				const int add=dp[i][j][mk];
				if(grid[i][j]=='1'||0==(mk&two(i)))dp[i+1][j][mk]=max(dp[i+1][j][mk],add+1);
				if(mk&two(i))dp[i+1][j][mk^two(i)]=max(dp[i+1][j][mk^two(i)],add);
				if(0==(mk&two(i))&&i+1<n&&0==(mk&two(i+1))&&grid[i][j]=='.'&&grid[i+1][j]=='.')
					dp[i+2][j][mk^two(i)^two(i+1)]=max(dp[i+2][j][mk^two(i)^two(i+1)],add+16);
			}
			for(int mk=0;mk<two(n);mk++)
				dp[0][j+1][mk]=max(dp[0][j+1][mk],dp[n][j][mk]);
		}
		return dp[0][m][0];
	}
};
