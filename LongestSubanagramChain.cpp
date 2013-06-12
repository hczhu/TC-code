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
#include <memory.h>
#include <algorithm>
using namespace std;
namespace MaxflowDinic
{
const int N=100000;
const int M=1000000;
int begin[N],edge[2*M];
int etop[N],rtop[N];
int redge[2*M];
int cnt[N+1];
int flow[M*2];
char color[N];
int pre[N],qq[N];
int aa[2*M],bb[2*M],cap[2*M];

void forwardStar(int n,int m)
{
	memset(cnt,0,sizeof(int)*(n+1));
	for(int i=0;i<m;i++)cnt[1+aa[i]]++;
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	for(int i=0;i<n;i++)
		begin[i]=cnt[i],etop[i]=cnt[i+1];
	for(int i=0;i<m;i++)
		edge[--cnt[aa[i]+1]]=i;
}
bool layerNetwork(int n,int s,int t)
{
	memcpy(rtop,begin,sizeof(int)*n);
	memset(color,0,sizeof(char)*n);
	int head=0,tail=0;
	qq[tail++]=t;color[t]=1;
	for(;head<tail;)
	{
		if(color[s])break;
		int tt=tail;
		while(head<tt)
		{
			int v=qq[head++];
			for(int p=begin[v];p<etop[v];p++)
			{
				int ind=edge[p];
				int u=bb[ind];
				if(color[u]==2)continue;
				ind^=1;
				if(flow[ind]<cap[ind])
				{
					redge[rtop[u]++]=ind;
					if(color[u]==0)color[u]=1,qq[tail++]=u;
				}
			}
		}
		for(int i=head;i<tail;i++)color[qq[i]]=2;
	}
	return color[s]!=0;
}
#define MAX 1000000000
int blockFlow(int n,int s,int t)
{
	int v=s,f=MAX,re=0;
	pre[s]=-1;
	for(;;)
	{
		if(v==t)
		{
			f=MAX;
			while(v!=s)
			{
				int ind=pre[v];
				v=aa[ind];
				f=min(f,cap[ind]-flow[ind]);
			}
			re+=f;v=t;
			while(v!=s)
			{
				int ind=pre[v];
				flow[ind]+=f;flow[ind^1]-=f;
				v=aa[ind];
				if(flow[ind]==cap[ind])rtop[v]--;
			}
			continue;
		}
		if(rtop[v]>begin[v])
		{
			int ind=redge[rtop[v]-1];
			v=bb[ind];pre[v]=ind;
		}
		else
		{
			if(v==s)break;
			v=aa[pre[v]];
			rtop[v]--;
		}
	}
	return re;
}
int maxflow(int n,int m ,int s,int t,int head[],int tail[],int up[])
{
	for(int i=0;i<m;i++)
		aa[i<<1]=head[i],bb[i<<1]=tail[i],cap[i<<1]=up[i],
		aa[(i<<1)^1]=tail[i],bb[(i<<1)^1]=head[i],cap[(i<<1)^1]=0;
	m<<=1;
	memset(flow,0,sizeof(int)*m);
	forwardStar(n,m);
	int re=0;
	while(layerNetwork(n,s,t))
		re+=blockFlow(n,s,t);
	return re;
}

vector<int> head,tail,up;
void clear(){head.clear();tail.clear();up.clear();}
void add_edge(int a,int b,int c)
{
//	cerr<<a<<"-->"<<b<<endl;
	head.push_back(a);
	tail.push_back(b);
	up.push_back(c);
}
int maxflow(int s,int t)
{
	int m=head.size();
	int n=max(s,t);
	for(int i=0;i<m;i++)
		aa[i<<1]=head[i],bb[i<<1]=tail[i],cap[i<<1]=up[i],
		aa[(i<<1)^1]=tail[i],bb[(i<<1)^1]=head[i],cap[(i<<1)^1]=0,
		n=max(n,head[i]),n=max(n,tail[i]);
	n++;
	m<<=1;
	memset(flow,0,sizeof(int)*m);
	forwardStar(n,m);
	int re=0;
	while(layerNetwork(n,s,t))
		re+=blockFlow(n,s,t);
	return re;
}
};
//namespace MaxflowDinic


class LongestSubanagramChain {
//Review your code before submission!!!!
	public:
	int getLength(vector <string> B) 
	{
		vector<vector<int> > flag(B.size());
		int top=0;
		for(int i=0;i<flag.size();i++)
		for(int j=0;j<B[i].length();j++)
			flag[i].push_back(top++);
		for(int i=0;i<top;i++)
			MaxflowDinic::add_edge(2*i,2*i+1,1);
		const int s=top*2;
		const int t=s+1;
		const int n=B.size();
		for(int i=0;i<flag[0].size();i++)MaxflowDinic::add_edge(s,2*flag[0][i],1);
		for(int i=0;i<flag[n-1].size();i++)MaxflowDinic::add_edge(2*flag[n-1][i]+1,t,1);

		for(int i=1;i<n;i++)
		for(int j=0;j<flag[i-1].size();j++)
		for(int k=0;k<flag[i].size();k++)
			if(B[i-1][j]<=B[i][k])MaxflowDinic::add_edge(2*flag[i-1][j]+1,2*flag[i][k],1);
		int ans=MaxflowDinic::maxflow(s,t);
		return ans;
	}
};
