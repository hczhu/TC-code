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
const int N=10;
#define two(x) ((1)<<(x))
int step[1<<N][8][8];
int dp[1<<N];
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int getDis(int r1,int c1,int r2,int c2)
{
	int d=min(abs(r1-r2),abs(c1-c2));
	return abs(r1-r2)+abs(c1-c2)-d;
}

class PawnsAndKings {
	public:
	int minNumberOfMoves(vector <string> board) 
	{
		const int n=board.size();
		const int m=board[0].length();
		int pr[10],pc[10],ptop=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(board[i][j]=='P')
				pr[ptop]=i,pc[ptop++]=j;
		debug(ptop);
		for(int mk=1;mk<two(ptop);mk++)
		for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
		{
			int& res=step[mk][r][c];
			res=1000000;
			for(int i=0;i<ptop;i++)
			{
				if(two(i)&mk)
					res=min(res,getDis(r,c,pr[i],pc[i])+step[mk^two(i)][pr[i]][pc[i]]);
			}
			//cerr<<mk<<" "<<r<<" "<<c<<"="<<step[mk][r][c]<<endl;
		}
		for(int i=1;i<two(ptop);i++)dp[i]=1000000;
		for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
		{
			if(board[r][c]!='K')continue;
			for(int mk=two(ptop)-1;mk;mk--)
			for(int sub=mk;sub;sub=(sub-1)&mk)
				dp[mk]=min(dp[mk],dp[mk^sub]+step[sub][r][c]);
		}
		return dp[two(ptop)-1];
	}
};


// Powered by FileEdit
