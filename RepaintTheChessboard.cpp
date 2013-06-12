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
//#define NDEBUG
#include <assert.h>
using namespace std;
typedef long long int llint;
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
#define PB(x) push_back((x))
#define SORT(x) sort(x.begin(),x.end())
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
	#define print(x)  cerr<<(x)<<endl;
#else
    #define debug(x)
    #define hline()
	#define print(x)
#endif
int sum[100][100];
int solve(int n,int m,vector<string> color,int a,int b)
{
	int re=a*b;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		char want=((i+j)&1)?'B':'W';
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(want==color[i-1][j-1]?0:1);
		if(i>=a&&j>=b)re=min(re,sum[i][j]-sum[i-a][j]-sum[i][j-b]+sum[i-a][j-b]);
	}
	return re;
}
class  RepaintTheChessboard
{
	public:
	int minimumChanges(vector <string> board)
	{
		const int n=board.size();
		const int m=board[0].length();
		int re=solve(n,m,board,8,8);
		debug(re);
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			board[i][j]=(board[i][j]=='B'?'W':'B');
		re=min(re,solve(n,m,board,8,8));
		return re;
	};
	
};
