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

//*******************************************
#define two(x)  ((1)<<(x))
struct Node
{
	double prob;
	int r,c,dan;
	int mask;
	Node(double p,int rr,int cc,int dd,int mm):prob(p),r(rr),c(cc),dan(dd),mask(mm){};
	bool operator<(const Node& other)const
	{
		return prob<other.prob;
	};
};
// A small heap
priority_queue<Node> heap;
#define Valid(r,c) ((r)<n&&(r)>=0&&(c)<m&&(c)>=0)
#define Index(node) node.r][node.c][node.dan][node.mask
double dis[50][50][8][1<<7];
bool inqq[50][50][8][1<<7];
bool visited[50][50][8][1<<7];
vector<string> maze;
vector<int> trap;
double DP(const Node start)
{
	Node node=start;
	const int n=maze.size();
	const int m=maze[0].length();
	const int color=trap.size();
	if(visited[Index(node)])return dis[Index(node)];
	visited[Index(node)]=true;
	double& ans=dis[Index(node)];
	queue<Node> qq;
	qq.push(node);
	inqq[Index(node)]=true;
	const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
	stack<Node> st;
	while(qq.size())
	{
		Node node=qq.front();qq.pop();
		st.push(node);
		if(maze[node.r][node.c]=='!')ans=1.0;
		for(int i=0;i<4;i++)
		{
			int nr=dir[i][0]+node.r;
			int nc=dir[i][1]+node.c;
			if(!Valid(nr,nc))continue;
			if('#'==maze[nr][nc])continue;
			if(isalpha(maze[nr][nc])&&maze[nr][nc]-'A'==node.dan)continue;
			// safe move
			if(!isalpha(maze[nr][nc])||(two(maze[nr][nc]-'A')&node.mask))
			{
				Node move(node.prob,nr,nc,node.dan,node.mask);
				if(!inqq[Index(move)])
				{
					inqq[Index(move)]=true;
					qq.push(move);
				}
				else ans=max(ans,dis[Index(move)]);
			}
			else
			{
				assert(isalpha(maze[nr][nc]));
				int idx=maze[nr][nc]-'A';
				assert(0==(node.mask&two(idx)));
				// bad happen
				if(node.dan==color)
				{
					Node move(node.prob*trap[idx]/100,nr,nc,idx,node.mask);
					double t=DP(move)*trap[idx]/100;
					move.mask^=two(idx);
					move.dan=color;
					t+=DP(move)*(100-trap[idx])/100;
					ans=max(ans,t);
				}
				else
				{
					Node move(node.prob*trap[idx]/100,nr,nc,node.dan,node.mask^two(idx));
					ans=max(ans,DP(move)*(100-trap[idx])/100);
				}
			}
		}
	}
end:
	hline();
	while(st.size())
	{
		dis[Index(st.top())]=ans;
		visited[Index(st.top())]=true;
		node=st.top();
		//cerr<<node.r<<" "<<node.c<<" "<<node.dan<<" "<<node.mask<<"="<<ans<<endl;
		st.pop();
	}
	return ans;
}
class ColorfulMaze {
//Review your code before submission!!!!
	public:
	double getProbability(vector <string> maze, vector <int> trap) 
	{
		::maze=maze;
		::trap=trap;
		const double eps=1e-12;
		const int n=maze.size();
		const int m=maze[0].length();
		const int color=trap.size();
		for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
		{
			if(maze[r][c]=='$')
			{
				return DP(Node(1.0,r,c,color,0));
			}
		}
		return 0.0;
	}
};

