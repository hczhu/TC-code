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
//LDRU
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool visited[1001][1001];
bool cut[1001][1001][4];
int hash[1000];
void add_cut(int x1,int y1,int x2,int y2)
{
	cerr<<"add "<<x1<<" "<<y1<<"--"<<x2<<"--"<<y2<<endl;
	if(x1==x2)
	{
		if(y1>y2)swap(y1,y2);
		if(x1)cut[x1-1][y1][2]=true;
		cut[x1][y1][0]=true;
	}
	else if(y1==y2)
	{
		if(x1>x2)swap(x1,x2);
		if(y1)cut[x1][y1-1][1]=true;
		cut[x1][y1][3]=true;
	}
	else assert(0);
}
class CuttingGlass {
	public:
	int pieces(int W, int H, int x, int y, vector <string> program) 
	{
		hash['L']=0;
		hash['D']=1;
		hash['R']=2;
		hash['U']=3;
		string all=accumulate(program.begin(),program.end(),string(""));
		for(int i=0;i<all.length();i++)
		{
			int d=hash[all[i]];
			int nx=x+dir[d][0];
			int ny=y+dir[d][1];
			assert(nx>=0&&nx<=W);
			assert(ny>=0&&ny<=H);
			add_cut(x,y,nx,ny);
			x=nx;y=ny;
		}
		debug(cut[49][50][3]);
		debug(cut[50][49][0]);
		debug(cut[48][49][2]);
		debug(cut[49][48][1]);
		int ans=0;
		for(int i=0;i<W;i++)
		for(int j=0;j<H;j++)
		{
			if(visited[i][j])continue;
			cerr<<i<<" "<<j<<endl;
			hline();
			ans++;
			queue<int> qq;
			qq.push((i<<10)^j);
			visited[i][j]=true;
			int cnt=0;
			while(qq.size())
			{
				cnt++;
				int x=qq.front()>>10;
				int y=qq.front()&0x3ff;
				qq.pop();
				for(int d=0;d<4;d++)
				{
					if(cut[x][y][d])continue;
					int nx=x+dir[d][0];
					int ny=y+dir[d][1];
					if(nx<0||nx>=W||ny<0||ny>=H||visited[nx][ny])continue;
					qq.push((nx<<10)^ny);
					visited[nx][ny]=true;
				}
			}
			debug(cnt);
		}
		return ans;
	}
};
