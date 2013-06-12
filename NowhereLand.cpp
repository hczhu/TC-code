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

#define N 100
#define M (N*N)
namespace MaxflowDinic
{
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
};

int head[M],tail[M],up[M];
template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}
bool have[100][100],can[100][100];


void addEdge(int a,int b,int c,int& top)
{
	head[top]=a,tail[top]=b,up[top++]=c;
	head[top]=b,tail[top]=a,up[top++]=c;
}
class NowhereLand {
	public:
	int placeGuards(vector <string> city, int k, vector <string> guard, vector <string> agen) 
	{
		const int n=city.size();
		int res=0;
		for(int i=0;i<n;i++)
		{
			vector<int> tmp=parse<int>(guard[i]);
			for(int j=0;j<tmp.size();j++)have[i][tmp[j]]=true;
			tmp=parse<int>(agen[i]);
			for(int j=0;j<tmp.size();j++)can[i][tmp[j]]=true;
		}
		const int inf=1000000;
		for(int ind=0;ind<k;ind++)
		{
			const int s=n;
			const int t=s+1;
			int top=0;
			for(int i=0;i<n;i++)
			for(int j=ind;j<=ind;j++)
			{
				if(have[i][j])addEdge(s,i,inf,top);
				else if(!can[i][j])addEdge(t,i,inf,top);
			}
			debug(ind);
			debug(top);
			for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(city[i][j]=='1')
					addEdge(i,j,1,top);
			debug(top);
			res+=MaxflowDinic::maxflow(t+1,top,s,t,head,tail,up);
			debug(res);
		}
		return res;
	}
};
