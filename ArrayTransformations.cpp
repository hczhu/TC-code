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

namespace MinCostFlow
{
const int N=300;
const int M=N*N;
int cost[M*2],flow[M*2],cap[2*M],head[2*M],tail[2*M];
int edge[N+1],star[M*2];
int cnt[N+1];
int label[N];
int mindis[N];
int pre[N];
int visited[N];
//****************************************************
//Heap
template<int S,bool (*cmpLess)(int ,int )>
class binaryHeap
{
	int heap[S],hpos[S];
	int hs;
public:
	binaryHeap<S,cmpLess>(){hs=0;};
	void adjustUp(int key)
	{
		int pos=hpos[key];
		assert(pos>=0&&pos<hs);
		assert(heap[pos]==key);
		while(pos&&cmpLess(key,heap[(pos-1)>>1]))
		{
			heap[pos]=heap[(pos-1)>>1];
			hpos[heap[pos]]=pos;
			pos=(pos-1)>>1;
		}
		heap[pos]=key;
		hpos[key]=pos;
	}
	void adjustDown(int key)
	{
		int pos=hpos[key],mm;
		assert(pos>=0&&pos<hs);
		assert(heap[pos]==key);
		while((pos<<1)+1<hs)
		{
			mm=1+(pos<<1);
			if(mm+1<hs&&cmpLess(heap[mm+1],heap[mm]))mm++;
			if(cmpLess(key,heap[mm]))break;
			heap[pos]=heap[mm];
			hpos[heap[pos]]=pos;
			pos=mm;
		}
		heap[pos]=key;
		hpos[key]=pos;
	}
	int popHeap()
	{
		int re=heap[0];
		hs--;
		if(hs)
		{
			heap[0]=heap[hs];
			hpos[heap[0]]=0;
			adjustDown(heap[0]);
		}
		return re;
	}
	void removeHeap(int key)
	{
		int pos=hpos[key];
		assert(pos>=0&&pos<hs);
		assert(heap[pos]==key);
		heap[pos]=heap[hs-1];
		hpos[heap[pos]]=pos;
		hs--;
		if(hs)
		{
			adjustUp(heap[pos]);
			adjustDown(heap[pos],hs);
		}
	}
	void pushHeap(int key)
	{
		heap[hs]=key;
		hpos[key]=hs;
		hs++;
		adjustUp(key);
	}
	int size(){return hs;};
	void clear(){hs=0;};
};
//**************************************************


bool cmpLess(int a,int b){return mindis[a]<mindis[b];};
binaryHeap<N,cmpLess> heap;
bool Dijkstra(int n,int s,int t,int& ff)
{
	visited[s]=1;
	mindis[s]=0;
	int top=0;
	heap.clear();
	heap.pushHeap(s);
	ff+=2;
	int cnt=0;
	for(;heap.size();)
	{
		int v=heap.popHeap();
		cnt++;
		for(int p=edge[v];p<edge[v+1];p++)
		{
			cnt++;
			int e=star[p];
			assert(flow[e]<=cap[e]);
			if(flow[e]==cap[e])continue;
			int u=tail[e];
			if(visited[u]==1+ff)continue;
			assert(v==head[e]);
			assert(cost[e]+label[v]-label[u]>=0);
			int t=mindis[v]+cost[e]+label[v]-label[u];
			if(ff>visited[u])
			{
				visited[u]=ff;
				mindis[u]=t;
				pre[u]=e;
				heap.pushHeap(u);
			}
			else if(visited[u]==ff&&t<mindis[u])
			{
				mindis[u]=t;
				pre[u]=e;
				heap.adjustUp(u);
			}
		}
		label[v]+=mindis[v];
		visited[v]=ff+1;
	}
	return visited[t]>=ff;
}
void preprocess(int n,int m,int aa[],int bb[],int cc[],int cp[])
{
	memset(cnt,0,sizeof(int)*(1+n));
	for(int i=0;i<m;i++)
	{
		head[i<<1]=aa[i],tail[i<<1]=bb[i];cost[i<<1]=cc[i];cap[i<<1]=cp[i];
		head[(i<<1)^1]=bb[i],tail[(i<<1)^1]=aa[i];cost[(i<<1)^1]=-cc[i];cap[(i<<1)^1]=0;
	}
	m<<=1;
	memset(flow,0,sizeof(int)*m);
	memset(label,0,sizeof(int)*m);
	for(int i=0;i<m;i++)
		cnt[head[i]+1]++;
	for(int i=0;i<n;i++)
		cnt[i+1]+=cnt[i],edge[i]=cnt[i];
	edge[n]=cnt[n];
	for(int i=0;i<m;i++)
		star[--cnt[head[i]+1]]=i;
}
int minCostFlow(int n,int m,int s,int t,int aa[],int bb[],int cc[],int cp[],int& flowUpper)
{
	int re=0;
	preprocess(n,m,aa,bb,cc,cp);
	memset(visited,0,sizeof(int)*n);
    int ff=0;
	int sum=0;
	while(flowUpper>sum)
	{
        //printf("sum=%d\n",sum);
        if(!Dijkstra(n,s,t,ff))return re;
		int add=flowUpper;
		for(int v=t;v!=s;)
		{
			int e=pre[v];
			add=min(add,cap[e]-flow[e]);
			v=head[e];
		}
		assert(add>0);
		for(int v=t;v!=s;)
		{
			int e=pre[v];
			flow[e]+=add;
			flow[e^1]-=add;
			re+=cost[e]*add;
			v=head[e];
			assert(cost[e]+label[head[e]]-label[tail[e]]==0);
		}
		sum+=add;
	}
	flowUpper=sum;
	return re;
}
};
const int M=2000;
int head[M],tail[M],cost[M],cap[M];
bool checkByCostFlow(vector<int>& need,int opup,int costup)
{
	const int n=need.size();
	const int s1=n+1;
	const int s=s1+1;
	const int t1=s+1;
	const int t=t1+1;
	int top=0;
	head[top]=s,tail[top]=s1,cost[top]=0,cap[top++]=opup;
	head[top]=t1,tail[top]=t,cost[top]=0,cap[top++]=opup;
	head[top]=t,tail[top]=s,cost[top]=0,cap[top++]=opup;

	for(int i=0;i<=n;i++)
		head[top]=s1,tail[top]=i,cost[top]=0,cap[top++]=opup,
		head[top]=i,tail[top]=t1,cost[top]=0,cap[top++]=opup;
	for(int i=0;i<n;i++)
		head[top]=i,tail[top]=i+1,cost[top]=1,cap[top++]=costup;
	const int ss=t+1;
	const int tt=ss+1;
	for(int i=0;i<n;i++)
		head[top]=i,tail[top]=tt,cost[top]=0,cap[top++]=need[i],
		head[top]=ss,tail[top]=i+1,cost[top]=0,cap[top++]=need[i];
	int sum=accumulate(need.begin(),need.end(),0);
	int f=sum;
	int extra=MinCostFlow::minCostFlow(tt+1,top,ss,tt,head,tail,cost,cap,f);
	debug(extra);
	debug(f);
	return sum+extra<=costup;
}

bool checkByGreedy(vector<int>& need,int opup,int costup)
{
	int sum=accumulate(need.begin(),need.end(),0);
}

bool feasible(vector<int>& all,int opup,int costup)
{
	opup=min(opup,costup);
	int sum=accumulate(all.begin(),all.end(),0);
	if(sum>costup)return false;
	if(*max_element(all.begin(),all.end())>opup)return false;
	if(sum<=costup&&sum<=opup)return true;
	return checkByCostFlow(all,opup,costup);
}

class ArrayTransformations {
	public:
	int minimalValue(vector <string> sarray, int opup, int costup) 
	{
		vector<int> array=parse<int>(accumulate(sarray.begin(),sarray.end(),string("")));
		debug(array.size());
		int low=0,high=*max_element(array.begin(),array.end());
		while(low<high)
		{
			int mid=(low+high)>>1;
			vector<int> del=array;
			for(int i=0;i<del.size();i++)
				del[i]=max(0,del[i]-mid);
			cerr<<"Check "<<mid<<endl;
			if(feasible(del,opup,costup))high=mid;
			else low=mid+1;
		}
		return low;
	}
};
