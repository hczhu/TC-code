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
//*******************************************
bool visited[100][100];
int dis[100][100];
class MazeMaker {
//Review your code before submission!!!!
	public:
	int longestPath(vector <string> maze, int r, int c, vector <int> mr, vector <int> mc) {
		const int n=maze.size();
		const int m=maze[0].length();
		queue<int> qq;
		qq.push((r<<8)^c);
		visited[r][c]=true;
		while(!qq.empty())
		{
			r=qq.front()>>8;
			c=qq.front()&0xff;
			qq.pop();
			for(int i=0;i<mr.size();i++)
			{
				int nr=r+mr[i];
				int nc=c+mc[i];
				if(nr<0||nr>=n||nc<0||nc>=m||visited[nr][nc]||maze[nr][nc]!='.')
					continue;
				dis[nr][nc]=dis[r][c]+1;
				visited[nr][nc]=true;
				qq.push((nr<<8)^nc);
			}
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(maze[i][j]=='.'&&!visited[i][j])
				return -1;
		int res=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(maze[i][j]=='.')res=max(res,dis[i][j]);
		return res;
	}
};

