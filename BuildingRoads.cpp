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
#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
const int N=60;
const int M=100;
int flag[N][N];
int dis[M][M];
const int inf=1000000000;
bool used[M];
int tag[N][N];
bool hash[1000];
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int get_cost(char ch)
{
	if(ch>='a'&&ch<='z')return ch-'a'+1;
	if(ch>='A'&&ch<='Z')return (ch-'A'+1)*100;
	if(ch>='1'&&ch<='9')return (ch-'0')*10000;
	if(ch=='0')return 100000;
	assert(hash[ch]);
	return 0;
}
void DFS(const vector<string>& grid,int r,int c,int v)
{
	tag[r][c]=v;
	for(int d=0;d<4;d++)
	{
		int nr=r+dir[d][0];
		int nc=c+dir[d][1];
		if(nr<0||nr>=grid.size()||nc<0||nc>=grid[0].length())continue;
		if(tag[nr][nc]==v)continue;
		if(flag[nr][nc]!=-1&&flag[nr][nc]!=v)dis[v][flag[nr][nc]]=get_cost(grid[nr][nc]);
		if(flag[nr][nc]!=v&&flag[nr][nc]!=-1)continue;
		DFS(grid,nr,nc,v);
	}
}
#define two(x)  ((1)<<(x))
bool exist[M][256];
int dp[M][256];
int cities[8];
int mylog2[256];
int DP(int v,int mk,int n)
{
	if(mk==0)return 0;
	if(mylog2[mk]!=-1)return dis[v][cities[mylog2[mk]]];
	if(exist[v][mk])return dp[v][mk];
	exist[v][mk]=true;
	int& ret=dp[v][mk];
	ret=inf;
	for(int sub=(mk-1)&mk;sub;sub=(sub-1)&mk)
	for(int u=0;u<n;u++)
	{
		int t=DP(u,sub,n)+DP(u,mk^sub,n)+dis[v][u];
		ret=min(ret,t);
	}
	//cerr<<v<<" "<<mk<<"="<<ret<<endl;
	return ret;
}
class BuildingRoads {
	public:
	int destroyRocks(vector <string> field) 
	{
		const int n=field.size();
		const int m=field[0].length();
		map<char,int> mem;
		const vector<string>& grid=field;
		int top=0;
		hash['!']=hash['@']=hash['#']=hash['$']=true;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]=='.')flag[i][j]=-1;
			else if(hash[grid[i][j]])flag[i][j]=top++;
			else if(mem.find(grid[i][j])!=mem.end())flag[i][j]=mem[grid[i][j]];
			else mem[grid[i][j]]=flag[i][j]=top++;
		}
		for(int i=0;i<n;i++,cerr<<endl)
		for(int j=0;j<m;j++)cerr<<flag[i][j]<<" ";

		for(int i=0;i<top;i++)
		for(int j=i+1;j<top;j++)
			dis[i][j]=dis[j][i]=inf;

		memset(tag,0xff,sizeof(tag));
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(flag[i][j]==-1)continue;
			if(used[flag[i][j]])continue;
			used[flag[i][j]]=true;
			DFS(grid,i,j,flag[i][j]);
		}
		hline();
		debug(top);
		for(int i=0;i<top;i++,cerr<<endl)
		for(int j=0;j<top;j++)cerr<<dis[i][j]<<" ";
		
		for(int k=0;k<top;k++)
		for(int i=0;i<top;i++)
		for(int j=0;j<top;j++)
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		
		hline();
		for(int i=0;i<top;i++,cerr<<endl)
		for(int j=0;j<top;j++)cerr<<dis[i][j]<<" ";

		const char city[]="!@#$";
		vector<pair<int,int> > pp;
		for(int c=0;c<4;c++)
		{
			vector<int> have;
			for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(grid[i][j]==city[c])
					have.push_back(flag[i][j]);
			}
			assert(have.size()==0||have.size()==2);
			if(have.empty())continue;
			pp.push_back(make_pair(have[0],have[1]));
		}
		debug(pp.size());
		for(int i=0;i<pp.size();i++)cities[2*i]=pp[i].first,cities[2*i+1]=pp[i].second;
		memset(mylog2,0xff,sizeof(mylog2));
		int cm=pp.size();
		for(int i=0;i<2*cm;i++)mylog2[two(i)]=i;
		int dp[16];
		dp[0]=0;
		for(int mk=1;mk<two(cm);mk++)
		{
			int cmk=0;
			int idx=0;
			for(int i=0;i<cm;i++)
			{
				if(mk&two(i))
				{
					idx=2*i;
					cmk^=two(2*i);
					cmk^=two(2*i+1);
				}
			}
			cmk^=two(idx);
			dp[mk]=DP(cities[idx],cmk,top);
			for(int sub=(mk-1)&mk;sub;sub=(sub-1)&mk)
				dp[mk]=min(dp[mk],dp[sub]+dp[mk^sub]);
		}
		return dp[two(cm)-1];
	}
};
