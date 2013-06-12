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




template<typename T>
struct trait_t {};
template<> struct trait_t<int>{const static int inf=1000000000;};
template<> struct trait_t<long long int>{const static long long int inf=1000000000000000000LL;};

template<int N,typename Cost,Cost INF=trait_t<Cost>::inf>
struct bipartite_maximum_weighted_matching
{
Cost llabel[N],rlabel[N];
Cost (*weight)[N];
int rpred[N];
Cost delta[N];
int lpred[N];
int rmatch[N],lmatch[N];
int qq[N];
bool lset[N];
void augment(int s,int v,int u)
{
	rmatch[u]=v;
	int a,b;
	while(v!=s)
	{
		a=lmatch[v];lmatch[v]=u;
		b=lpred[v];
		assert(rmatch[a]==v);
		rmatch[a]=b;
		v=b;u=a;
	}
	lmatch[v]=u;
}
bool BFS(const int s,int n,int m)
{
	int head=0,tail=0;
	memset(lset,false,sizeof(bool)*n);
	for(int i=0;i<m;i++)delta[i]=INF;
	qq[tail++]=s;lset[s]=true;
	for(;;)
	{
		while(head<tail)
		{
			int v=qq[head++];
			for(int u=0;u<m;u++)
			{
				Cost t=llabel[v]+rlabel[u]-weight[v][u];
				assert(t>=0);
				if(t<delta[u])delta[u]=t,rpred[u]=v;
				if(t)continue;
				if(rmatch[u]==-1)
				{
					augment(s,v,u);
					return true;
				}
				if(lset[rmatch[u]])continue;
				lset[rmatch[u]]=true;
				lpred[rmatch[u]]=v;
				qq[tail++]=rmatch[u];
			}
		}
		Cost del=INF;
		for(int i=0;i<m;i++)
			if(delta[i]&&del>delta[i])del=delta[i];
		assert(del>0&&del<INF);
		for(int i=0;i<n;i++)
			if(lset[i])llabel[i]-=del;
		for(int i=0;i<m;i++)
		{
			assert(delta[i]<INF&&delta[i]>=0);
			if(delta[i]==0)rlabel[i]+=del;
			else 
			{
				delta[i]-=del;
				if(delta[i]==0)qq[tail++]=i;
			}
		}
		for(int i=head;i<tail;i++)
		{
			if(rmatch[qq[i]]==-1)
			{
				augment(s,rpred[qq[i]],qq[i]);
				return true;
			}
			int v=rmatch[qq[i]];
			lset[v]=true;
			lpred[v]=rpred[qq[i]];
			qq[i]=v;
		}
	}
	return false;
}
Cost match(int n,int m,Cost cost[][N])
{
	assert(n<=m);
	weight=cost;
	memset(rmatch,0xff,sizeof(int)*m);
	memset(lmatch,0xff,sizeof(int)*n);
	memset(rlabel,0,sizeof(rlabel[0])*m);
	for(int i=0;i<n;i++)
		llabel[i]=*max_element(weight[i],weight[i]+m);
	for(int i=0;i<n;i++)
		BFS(i,n,m);
	Cost re=0;
	for(int i=0;i<n;i++)
		re+=weight[i][lmatch[i]];
	return re;
}
};
bipartite_maximum_weighted_matching<100,int> solver;
bool con[100][100];
int cap[100][100];
int low[100];
int flag[100];
vector<int> st;
vector<vector<int> > cycle;
void DFS(int v,int n,int& ff,int pp)
{
	ff++;
	low[v]=flag[v]=ff;
	st.push_back(v);
	for(int u=0;u<n;u++)
	{
		if(!con[v][u]||u==pp)continue;
		if(flag[u]==0)
		{
			DFS(u,n,ff,v);
			low[v]=min(low[v],low[u]);
		}
		else 
		{
			bool ok=low[u]<low[v];
			low[v]=min(low[v],low[u]);
			if(!ok)continue;
			cerr<<"cycle at "<<u<<endl;
			vector<int> cc;
			cc.push_back(u);
			for(int i=st.size()-1;st[i]!=u;i--)cc.push_back(st[i]);
			debug(cc.size());
			for(int i=0;i<cc.size();i++)cerr<<cc[i]<<"--";cerr<<endl;
			cycle.push_back(cc);
		}
	}
	st.pop_back();
}

int cost[100][100];
int solve_cycle(vector<int>& cycle,int m)
{
	const int n=cycle.size();
	assert(n>1);
	cycle.push_back(cycle[0]);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)cost[i][j]=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
	{
		int a=cycle[i],b=cycle[i+1];
		int x=cycle[j+1],y=cycle[j];
		assert(con[a][b]);
		assert(con[x][y]);
		if(cap[a][b]+cap[x][y]<m)
		{
			cost[i][j]=m-cap[a][b]-cap[x][y];
		}
	}
	return solver.match(n,n,cost);
}
class SpaceshipEvacuation {
public:
	int additionalCabins(int n, vector <string> all, int m) 
	{
		for(int i=0;i<all.size();i++)
		{
			istringstream in(all[i]);
			int a,b,c,d;
			in>>a>>b>>c>>d;
			con[a][b]=con[b][a]=true;
			cap[a][b]=c;
			cap[b][a]=d;
		}
		int ff=0;
		DFS(0,n,ff,-1);
		if(*min_element(flag,flag+n)==0)return -1;
		for(int i=0;i<n;i++)cerr<<i<<"="<<low[i]<<endl;
		int ans=0;
		for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
		{
			if(!con[a][b])continue;
			if(low[a]>=low[b])continue;
			cerr<<"cut edge "<<a<<"-->"<<b<<endl;
			ans+=max(0,m-cap[b][a]);
			debug(ans);
		}
		for(int i=0;i<cycle.size();i++)
		{
			assert(low[cycle[i][0]]==flag[cycle[i][0]]);
			ans+=solve_cycle(cycle[i],m);
			debug(ans);
		}
		return ans;
	}
};
