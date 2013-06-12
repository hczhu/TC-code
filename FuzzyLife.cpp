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
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int lay[100][100],cnt[100][100];
int aa[100][100],bb[100][100];
char status(char ch,int neb)
{
	if(ch=='1'&&(neb<2||neb>3))return '0';
	if(ch=='0'&&neb==3)return '1';
	return ch;
}
class FuzzyLife {
	public:
	int survivingCells(vector <string> grid) 
	{
		const int n=grid.size();
		const int m=grid[0].length();
		memset(lay,'0',sizeof(lay));
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			lay[i+1][j+1]=grid[i][j];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(lay[i][j]!='1')continue;
			for(int d=0;d<8;d++)
				cnt[i+dir[d][0]][j+dir[d][1]]++;
		}
		for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
		{
			int live=cnt[i][j];
			bool que=false;
			int r=-1,c=-1;
		#define Good(v,n) (v>=0&&v<n)
			for(int d=0;d<8;d++)
			{
				if(Good(i+dir[d][0],n+2)&&Good(j+dir[d][1],m+2)&&lay[i+dir[d][0]][j+dir[d][1]]=='?')
				{
					assert(-1==r&&-1==c);
					r=i+dir[d][0];
					c=j+dir[d][1];
					que=true;
				}
			}
			if(que)
			{
				if(status(lay[i][j],live+1)=='1')aa[r][c]++;
				if(status(lay[i][j],live)=='1')bb[r][c]++;
			}
			else if(status(lay[i][j],live)=='1')ans++;
		}
		debug(ans);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{

			if(lay[i][j]!='?')continue;
			if(status('1',cnt[i][j])=='1')aa[i][j]++;
			if(status('0',cnt[i][j])=='1')bb[i][j]++;
			ans+=max(aa[i][j],bb[i][j]);
			cerr<<i<<" "<<j<<"="<<aa[i][j]<<" "<<bb[i][j]<<endl;
		}
		return ans;
	}
};
