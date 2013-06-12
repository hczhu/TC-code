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
struct Node
{
	int r,c,d;
	int v;
	Node(int x,int y,int z,int v1):r(x),c(y),d(z),v(v1){};
	bool operator<(const Node& other)const
	{
		return v>other.v;
	};
};
#define two(x)  ((1)<<(x))
int dis[25][13][1<<13];
int len[25][25];
// A small heap
priority_queue<Node> heap;

class ThirteenHard {
	public:
	int calcTime(vector <string> city) 
	{
		const int n=city.size();
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(city[i][j]=='#')len[i][j]=-1;
			else if(islower(city[i][j]))len[i][j]=27+city[i][j]-'a';
			else len[i][j]=1+city[i][j]-'A';
		}
		heap.push(Node(0,0,1,0));
		memset(dis,0x11,sizeof(dis));
		dis[0][0][1]=0;
		while(!heap.empty())
		{
			Node cur=heap.top();heap.pop();
			int v=cur.r;
			int s=cur.c;
			int mk=cur.d;
			if(cur.v>dis[v][s][mk])continue;
			if(v==n-1)return dis[v][s][mk];
			const int add=dis[v][s][mk];
			for(int u=0;u<n;u++)
			{
				if(len[v][u]==-1)continue;
				int ns=(s+len[v][u])%13;
				if(mk&two(ns))continue;
				int nmk=mk^two(ns);
				if(dis[u][ns][nmk]>add+len[v][u])
				{
					dis[u][ns][nmk]=add+len[v][u];
					heap.push(Node(u,ns,nmk,dis[u][ns][nmk]));
				}
			}
		}

		return -1;
	}
};
