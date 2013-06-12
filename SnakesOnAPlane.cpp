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
const int N=300;
int n,m;




inline int node(int r,int c)
{
	return r*m+c;
}
int cap[N][N],flow[N][N];
bool visited[N];
bool DFS(int v,int n,int des)
{
	visited[v]=true;
	if(v==des)return true;
	for(int i=0;i<n;i++)
	{
		if(visited[i]||flow[v][i]==cap[v][i])
			continue;
		if(DFS(i,n,des))
		{
			flow[v][i]++;
			flow[i][v]--;
			assert(flow[v][i]<=cap[v][i]);
			assert(flow[i][v]<=cap[i][v]);
			return true;
		}
	}
	return false;
}
bool augment(int s,int t,int n)
{
	memset(visited,false,sizeof(bool)*n);
	return DFS(s,n,t);
}
vector<string> grid;
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
inline bool valid(int r,int c)
{
	return r>=0&&r<n&&c>=0&&c<m&&grid[r][c]=='.';
}
typedef long long int llint;
map<llint,int> mem[12][12];
const char cell[][5]={"1010","0101","1100","0110","0011","1001","0000"};
const int inf=1000000;
inline llint hash(string& code)
{
	llint res=0;
	for(int i=0;i<m;i++)res<<=3,res^=code[i];
	return res;
}
int DP(int r,int c,string code)
{
	if(c==m)c=0,r++;
	if(r==n)return 0;
	if(grid[r][c]=='#')
	{
		if(r>0&&cell[code[c]][3]=='1')return inf;
		if(c>0&&cell[code[c-1]][2]=='1')return inf;
		code[c]=6;
		return DP(r,c+1,code);
	}
	const llint xx=hash(code);
	if(mem[r][c].count(xx))return mem[r][c][xx];
	int res=inf;
	const char old=code[c];
	for(int i=0;i<6;i++)
	{
		if(r>0&&cell[code[c]][3]!=cell[i][1])continue;
		if(c>0&&cell[code[c-1]][2]!=cell[i][0])continue;
		int edge=0;
		if(r==0&&cell[i][1]=='1')edge++;
		if(r==n-1&&cell[i][3]=='1')edge++;
		if(c==0&&cell[i][0]=='1')edge++;
		if(c==m-1&&cell[i][2]=='1')edge++;
		if(edge>1)continue;
		code[c]=i;
		res=min(res,DP(r,c+1,code)+edge);
		code[c]=old;
	}
	mem[r][c][xx]=res;
	return res;
}
class SnakesOnAPlane {
	public:
	int snakes(vector <string> grid) 
	{

		::grid=grid;
		const int n=grid.size();
		const int m=grid[0].length();
		::n=n;::m=m;

		int ret=DP(0,0,string(m,'0'));
		debug(ret);
		if(ret==inf)return -1;
		assert(0==(ret&1));
		return ret/2;

		const int s=node(n-1,m-1)+1;
		const int t=s+1;
		const int dummy1=t+1;
		const int dummy2=dummy1+1;
		const int all=dummy2+1;
		debug(s);
		debug(t);
		debug(all);
		int out=0,in=0;
		for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
		{
			if(grid[r][c]!='.')continue;
			if((r+c)&1)cap[s][node(r,c)]+=2,out+=2;
			else cap[node(r,c)][t]+=2,in+=2;
			if(r==0||r==n-1||c==0||c==m-1)
			{
				if(1&(r+c))cap[node(r,c)][dummy1]++;
				else cap[dummy2][node(r,c)]++;
			}
			if(0==((r+c)&1))continue;
			for(int d=0;d<4;d++)
				if(valid(r+dir[d][0],c+dir[d][1]))
					cap[node(r,c)][node(r+dir[d][0],c+dir[d][1])]++;
		}
		debug(out);
		debug(in);
		if(out>in)cap[dummy1][t]+=out-in;
		else cap[s][dummy2]+=in-out;
		int want=max(out,in);
		int res=0;
		while(augment(s,t,all))want--;
		debug(want);
		if(flow[dummy1][t]+flow[s][dummy2]!=cap[dummy1][t]+cap[s][dummy2])
			return -1;
		assert(0==((flow[dummy1][t]+flow[s][dummy2])&1));
		res+=(flow[dummy1][t]+flow[s][dummy2])>>1;
		debug(res);
		while(want)
		{
			cap[dummy1][dummy2]++;
			if(!augment(s,t,all))return -1;
			want--;
			res++;
		}
		return res;
	}
};


// Powered by FileEdit
