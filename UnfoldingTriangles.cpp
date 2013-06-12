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


int black[100][100],white[100][100];
class UnfoldingTriangles {
	public:
	int solve(vector <string> grid, int up) 
	{
		const int n=grid.size();
		const int m=grid[0].length();
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			black[i][j+1]=black[i][j];
			if(grid[i][j]=='#')black[i][j+1]++;
			white[i][j+1]=white[i][j];
			if(grid[i][j]=='.')white[i][j+1]++;
		}
		int res=-1;
		for(int sum=0;sum<=n-1+m-1;sum++)
		for(int r1=0;r1<n;r1++)
		{
			const int col=sum-r1;
			if(col<0||col>=m)continue;
			for(int r2=r1;r2<n&&sum-r2>=0&&grid[r2][sum-r2]=='/';r2++)
			{
				bool ok=true;
				for(int r=r1;r<=r2;r++)
					if(col+1<m&&grid[r][col+1]=='#')ok=false;
				for(int c=sum-r2;c<=col;c++)
					if(r2+1<n&&grid[r2+1][c]=='#')ok=false;
				int hole=0;
				for(int r=r1;r<=r2;r++)
				{
					if(white[r][col+1]>white[r][sum-r+1])ok=false;
					int b=black[r][col+1]-black[r][sum-r+1];
					hole+=col-sum+r-b;
				}
				cerr<<r1<<" "<<col<<" "<<" "<<r2<<" "<<sum-r2<<" "<<ok<<" "<<hole<<endl;
				if(ok&&hole<=up)res=max(res,(r2+1-r1)*(r2-r1+2)/2);
			}
		}
		return res;
	}
};
