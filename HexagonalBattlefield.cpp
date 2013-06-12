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

const int N=15;
typedef long long int llint;
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
const llint mod=2000000011;
bool petr[100][100];
int bx[N],ex[N];
int forbid[N];
int stack[1<<20];
llint dp1[1<<N],dp2[1<<N];

void DFS1(int pos,const int mk,int n,int next,int& top)
{
	if(pos==n)
	{
		stack[top++]=next;
		return;
	}
	if(mk&two(pos))DFS1(pos+1,mk,n,next,top);
	else
	{
		if(pos+1<n&&0==(two(pos+1)&mk))DFS1(pos+2,mk,n,next,top);
		if(0==(next&two(pos)))DFS1(pos+1,mk,n,next^two(pos),top);
		if(0==(next&two(pos+1)))DFS1(pos+1,mk,n,next^two(pos+1),top);
	}
}

void DFS2(int pos,const int mk,int n,int next,int& top)
{
	if(pos==n)
	{
		stack[top++]=next;
		return;
	}
	if(mk&two(pos))DFS2(pos+1,mk,n,next,top);
	else
	{
		if(pos+1<n&&0==(two(pos+1)&mk))DFS2(pos+2,mk,n,next,top);
		if(pos<n-1&&0==(next&two(pos)))DFS2(pos+1,mk,n,next^two(pos),top);
		if(pos&&0==(next&two(pos-1)))DFS2(pos+1,mk,n,next^two(pos-1),top);
	}
}

class HexagonalBattlefield {
	public:
	int countArrangements(vector <int> X, vector <int> Y, int n) 
	{
		for(int y=n-1;y>-n;y--)
		{
			if(y>=0)bx[y+n-1]=y-(n-1),ex[y+n-1]=n-1;
			else bx[y+n-1]=-(n-1),ex[y+n-1]=y+n-1;
			cerr<<y<<" "<<bx[y+n-1]<<"-->"<<ex[y+n-1]<<endl;
		}
		for(int i=0;i<X.size();i++)petr[N+X[i]][N+Y[i]]=true;
		for(int y=-(n-1);y<n;y++)
		for(int x=bx[y+n-1];x<=ex[y+n-1];x++)
			if(petr[x+N][y+N])forbid[y+n-1]^=two(x-bx[y+n-1]);
		for(int y=-(n-1);y<n;y++)cerr<<y<<" "<<forbid[y+n-1]<<endl;
		llint *pre=dp1,*next=dp2;
		pre[0]=1;
		for(int y=n-1;y>=-n+1;y--)
		{
			int m=ex[y+n-1]-bx[y+n-1]+1;
			int m1=y>0?m+1:m-1;
			if(m1<1)m1=1;
			debug(m);
			debug(forbid[y+n-1]);
			memset(next,0,sizeof(llint)*two(m1));
			for(int mk=0;mk<two(m);mk++)
			{
				if(mk&forbid[y+n-1])continue;
				llint add=pre[mk]%mod;
				if(add==0)continue;
				int top=0;
				if(y>0)DFS1(0,mk^forbid[y+n-1],m,0,top);
				else DFS2(0,mk^forbid[y+n-1],m,0,top);
				for(int i=0;i<top;i++)next[stack[i]]+=add;
			}
			swap(pre,next);
		}
		llint ans=pre[0]%mod;
		return ans;
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> X,Y;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		X.push_back(x);
		Y.push_back(y);
	}
	HexagonalBattlefield hh;
	cout<<hh.countArrangements(X,Y,n)<<endl;
	return 0;
}
