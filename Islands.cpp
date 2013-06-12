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
char grid[200][200];
bool hash[256][256];
class Islands {
	public:
	int beachLength(vector <string> kingdom) 
	{
		hash['#']['.']=hash['.']['#']=true;
		const int n=kingdom.size();
		const int m=kingdom[0].length();
		for(int i=0;i<n;i++)
		{
			int add=i&1;
			for(int j=0;j<m;j++)
				grid[i][2*j+add]=kingdom[i][j];
		}
		int res=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<2*m+1;j++)
		{
			for(int x=-1;x<=1;x++)
			for(int y=-2;y<=2;y++)
			{
				if(abs(x)+abs(y)!=2)continue;
				int r=i+x;
				int c=j+y;
				if(r>=0&&c>=0&&hash[grid[i][j]][grid[r][c]])res++;
			}
		}
		debug(res);
		res>>=1;
		return res;
	}
};
