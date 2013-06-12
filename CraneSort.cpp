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

int edge[5][5];
bool visited[5];
void DFS(int v,vector<int>& node)
{
	node.push_back(v);
	visited[v]=true;
	for(int i=0;i<5;i++)
		if(!visited[i]&&edge[v][i]+edge[i][v])
			DFS(i,node);
}
int getAns()
{
	memset(visited,false,sizeof(visited));
	vector<int> node;
	int res=0;
	for(int i=0;i<5;i++)
	{
		node.clear();
		if(visited[i])continue;
		DFS(i,node);
		if(node.size()==1)continue;
		int extra=1;
		for(int j=0;j<node.size();j++)
		{
			res+=accumulate(edge[node[j]],edge[node[j]]+5,0);
			if(node[j]==4)extra=0;
		}
		res+=extra;
	}
	//debug(res);
	return res;
}

void constructEdge(string text,string pattern,int shift)
{
	const int n=pattern.length();
	memset(edge,0,sizeof(edge));
	for(int i=0;i<n;i++)
	{
		int a=pattern[i]-'A',b;
		if(i+shift<0||i+shift>=n)b=4;
		else b=text[i+shift]-'A';
		if(a==b)continue;
		edge[a][b]++;
	}
}

class CraneSort 
{
	public:
	int moves(string container) 
	{
		int cnt[4];
		memset(cnt,0,sizeof(cnt));
		const int n=container.size();
		for(int i=0;i<n;i++)cnt[container[i]-'A']++;
		int myindex[4]={0,1,2,3};
		int res=n;
		do
		{
			string pattern;
			for(int i=0;i<4;i++)
			for(int j=0;j<cnt[myindex[i]];j++)
				pattern.push_back('A'+myindex[i]);
			for(int s=-n;s<=n;s++)
			{
				constructEdge(container,pattern,s);
				res=min(res,getAns());
			}
			//debug(pattern);
		}while(next_permutation(myindex,myindex+4));
		return res;
	}
};
