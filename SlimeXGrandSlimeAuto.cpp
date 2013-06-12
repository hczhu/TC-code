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
#include <cassert>
#include <limits>
#include <cstdarg>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
/*********************************
 Tips
 * Binary search
 * Ternary search
 * Bitwise tricks
 * Bipartite matching
 * Graph algorithms
 * DP
 * Subset DP
 * Greedy algorithms
 * Network flow
 * Construct the solution directly
 * Be careful to the input constraints
 * Corner cases.
**********************************/
//****************************************************
template<int S,class comparator>
class binaryHeap
{
	int heap[S],hpos[S];
	int hs;
	const comparator *cmpLess;
public:
	binaryHeap():hs(0),cmpLess(NULL){};
	void set_cmp(const comparator& cmp){cmpLess=&cmp;};
	void adjustUp(int key)
	{
		int pos=hpos[key];
		assert(pos>=0&&pos<hs);
		assert(heap[pos]==key);
		while(pos&&(*cmpLess)(key,heap[(pos-1)>>1]))
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
			if(mm+1<hs&&(*cmpLess)(heap[mm+1],heap[mm]))mm++;
			if((*cmpLess)(key,heap[mm]))break;
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

template<int N,int M,typename flow_type=int,typename cost_type=int>
class min_cost_flow_solver_t
{
public:
cost_type cost[M*2],cap[2*M];
cost_type mindis[N],label[N];
flow_type flow[2*M];

int head[2*M],tail[2*M];
int edge[N+1],star[M*2];
int cnt[N+1];
int pre[N];
int visited[N];

bool operator()(int a,int b)const{return mindis[a]<mindis[b];};

int m,n;

binaryHeap<N,min_cost_flow_solver_t<N,M,flow_type,cost_type> > heap;

min_cost_flow_solver_t():m(0){heap.set_cmp(*this);};
void clear()
{
	m=0;
	n=0;
}
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
			cost_type t=mindis[v]+cost[e]+label[v]-label[u];
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
void preprocess(int n,int m)
{
	memset(cnt,0,sizeof(int)*(1+n));
	memset(flow,0,sizeof(flow_type)*m);
	memset(label,0,sizeof(cost_type)*m);
	for(int i=0;i<m;i++)cnt[head[i]+1]++;
	for(int i=0;i<n;i++)cnt[i+1]+=cnt[i],edge[i]=cnt[i];
	edge[n]=cnt[n];
	for(int i=0;i<m;i++)star[--cnt[head[i]+1]]=i;
}
int add_one_edge(int _head,int _tail,int _cap,int _cost)
{
	assert(m<2*M);
	if(m==2*M)return -1;
	head[m]=_head;tail[m]=_tail;cap[m]=_cap;cost[m++]=_cost;
	head[m]=_tail;tail[m]=_head;cap[m]=0;cost[m++]=-_cost;
	n=max(n,_head+1);
	n=max(n,_tail+1);
	assert(n<=N);
	return 0;
}
cost_type minCostFlow(int s,int t,flow_type& flowUpper)
{
	assert(s<n);
	assert(t<n);
	debug(n);
	cost_type re=0;
	preprocess(n,m);
	memset(visited,0,sizeof(int)*n);
        int ff=0;
	flow_type sum=0;
	while(flowUpper>sum)
	{
        //printf("sum=%d\n",sum);
        if(!Dijkstra(n,s,t,ff))break;
		flow_type add=flowUpper-sum;
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
min_cost_flow_solver_t<102,102*102> solver;
const int N=50;
const int inf=1000000000;
int dis1[N][N],dis2[N][N];
int cost[N][N];
class SlimeXGrandSlimeAuto {
  public:
   int travel(vector <int> car, vector <int> dist, vector <string> road, int walk, int drive) {
     debug("Start calculation.");
     const int n=road.size();
     for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        dis1[i][j]=dis2[i][j]=inf;
     for(int i=0;i<n;i++)dis1[i][i]=dis2[i][i]=0;
     for(int i=0;i<n;i++)
       for(int j=0;j<n;j++) {
         if(road[i][j]!='.') {
           int x=road[i][j]-'0'+1;
           if(islower(road[i][j]))x=road[i][j]-'a'+11;
           else if(isupper(road[i][j]))x=road[i][j]-'A'+37;
           dis1[j][i]=dis1[i][j]=walk*x;
           dis2[i][j]=dis2[j][i]=drive*x;
         }
       }
     for(int k=0;k<n;k++)
       for(int i=0;i<n;i++)
         for(int j=0;j<n;j++) {
           dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
           dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
         }
     for(int i=0;i<n;i++,cerr<<endl)
       for(int j=0;j<n;j++)
         cerr<<dis1[i][j]<<" ";
      debug("hline");
      for(int i=0;i<n;i++,cerr<<endl)
       for(int j=0;j<n;j++)
         cerr<<dis2[i][j]<<" ";
 
     const int ll=car.size();
     const int rr=dist.size();
     int ans=0;
     const int U=10000000;
     for(int i=0;i<car.size();i++) {
       int cur=0;
       for(int j=0;j<rr;j++) {
         int next=dist[j];
         if(i==0)ans+=dis1[cur][next];
         cost[i][j]=-min(0,dis1[cur][car[i]]+dis2[car[i]][next]-dis1[cur][next]);
         cur=next;
         cerr<<i<<","<<j<<"="<<cost[i][j]<<endl;
         solver.add_one_edge(i,j+ll,1,U-cost[i][j]);
       }
     }
     const int s=ll+rr;
     const int t=s+1;
     for(int i=0;i<ll;i++) {
       solver.add_one_edge(s,i,1,0);
     }
     for(int i=0;i<rr;i++) {
       solver.add_one_edge(i+ll,t,1,0);
     }
     debug(ans);
     int f=min(ll,rr);
     ans-=U*f-solver.minCostFlow(s,t,f);
     return ans;
  }
};
/*
int main() {
  int car[]={1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  int dist[]={1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  string road[]={".f", "f."};
  SlimeXGrandSlimeAuto slim;
  cout<<slim.travel(vector<int>(car,car+sizeof(car)/sizeof(car[0])),
          vector<int>(dist,dist+sizeof(dist)/sizeof(dist[0])),vector<string>(road,road+2),35,11)<<endl;
  return 0;
}
*/
