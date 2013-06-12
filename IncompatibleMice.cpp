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

const int N=50;
int n,m;
const int inf=6000;
vector<string> grid;
bool valid(int r,int c)
{
	return r>=0&&r<n&&c>=0&&c<m&&grid[r][c]!='#';
}
int visited[N][N];
int dis[6][N][N];

void BFS(int r,int c,int dis[][N])
{
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)dis[i][j]=inf;
	static int ff=0;
	ff++;
	visited[r][c]=ff;
	queue<int> qq;
	qq.push((r<<8)^c);
	dis[r][c]=0;
	while(qq.size())
	{
		int r=qq.front()>>8;
		int c=qq.front()&0xff;
		qq.pop();
		for(int dr=-1;dr<=1;dr++)
		for(int dc=-1;dc<=1;dc++)
		{
			if(dr*dc)continue;
			int nr=r+dr;
			int nc=c+dc;
			if(valid(nr,nc)&&visited[nr][nc]!=ff)
			{
				visited[nr][nc]=ff;
				dis[nr][nc]=dis[r][c]+1;
				qq.push((nr<<8)^nc);
			}
		}
	}
}
void searchZero(int dis[][N],int& r,int& c)
{
	for(r=0;r<n;r++)
	for(c=0;c<m;c++)
		if(0==dis[r][c])return;
}
const int S=2500;
//  s1-->dis1  dis2-->t1
// The time of mouce 1 minus the time of mouce 2
void forbid(int dis1[][N],int dis2[N][N],int dis3[][N],int dis4[][N],bool have[])
{
	int r,c;

	searchZero(dis2,r,c);
	const int d1=dis1[r][c];
	searchZero(dis4,r,c);
	const int d2=dis3[r][c];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		assert(dis1[i][j]+dis2[i][j]>=d1);
		assert(dis3[i][j]+dis4[i][j]>=d2);
		if(dis1[i][j]+dis2[i][j]==d1&&dis3[i][j]+dis4[i][j]==d2)
			//res.insert(dis3[i][j]-dis1[i][j]);
		{
			debug(dis3[i][j]-dis1[i][j]);
			have[(dis3[i][j]-dis1[i][j])+S]=true;
		}
		int r=i,c=j;
		for(int dr=-1;dr<=1;dr++)
		for(int dc=-1;dc<=1;dc++)
		{
			if(dr*dc)continue;
			int nr=r+dr;
			int nc=c+dc;
			if(!valid(nr,nc))continue;
			if(dis1[r][c]+1+dis2[nr][nc]!=d1)continue;
			if(dis3[nr][nc]+1+dis4[r][c]!=d2)continue;
			//res.insert(dis3[nr][nc]-dis1[r][c]);
			debug(dis3[nr][nc]-dis1[r][c]);
			have[dis3[nr][nc]-dis1[r][c]+S]=true;
		}
	}
}


bool have[3][3][inf];
class IncompatibleMice {
	public:
	int totalTime(vector <string> maze) {
		int ans=100000000;
		grid=maze;
		n=maze.size();
		m=maze[0].length();
		for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
		{
			if(islower(maze[r][c]))
				BFS(r,c,dis[maze[r][c]-'a']);
			else if(isupper(maze[r][c]))
				BFS(r,c,dis[maze[r][c]-'A'+3]);
		}
		int want[3];
		for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
			if(isupper(maze[r][c])&&
					(want[maze[r][c]-'A']=dis[maze[r][c]-'A'][r][c])>=inf)
				return -1;
		debug(want[0]);
		debug(want[1]);
		debug(want[2]);

		for(int i=0;i<3;i++)
		for(int j=i+1;j<3;j++)
		{
			cerr<<i<<" VS "<<j<<endl;
			forbid(dis[i],dis[i+3],dis[j],dis[j+3],have[i][j]);	
		}
		const int a=0;
		for(int b=-5000;b<=5000;b++)
		{
			if(a-b+S<0||a-b+S>=inf||!have[0][1][a-b+S])
			{
				int low=min(0,b);
				int high=max(want[0],b+want[1]);
				for(int c=low;;c++)
				{
					if(a-c+S>=0&&a-c+S<inf&&have[0][2][a-c+S])continue;
					if(b-c+S>=0&&b-c+S<inf&&have[1][2][b-c+S])continue;
					ans=min(ans,max(high,c+want[2])-min(low,c));
					break;
				}
				for(int c=low;;c--)
				{
					if(a-c+S>=0&&a-c+S<inf&&have[0][2][a-c+S])continue;
					if(b-c+S>=0&&b-c+S<inf&&have[1][2][b-c+S])continue;
					ans=min(ans,max(high,c+want[2])-min(low,c));
					break;
				}
			}
		}
		return ans;
	}
};


// Powered by FileEdit
