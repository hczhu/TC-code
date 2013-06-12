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
//INT_MAX INT_MIN
#include <limits.h>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
#define BCNT(x) __builtin_popcount(x)
#define Low(x) ((((x)^((x)-1))&x))
#define Two(x)  ((1)<<(x))

int cache[14][14][1<<14];
const int mod=1000000007;
int son[14][14],stop[14];
int sum[14];
int edge[14];
int hash[1<<14];
typedef long long int llint;
#define Mul(x,y) ((llint)(x)*(llint)(y)%(mod))
int DP(int v,int r,int mk,int k) {
  if(stop[v]==0||k==stop[v]) {
    assert(mk==Two(r));
    return 1;
  }
  int & res=cache[v][r][mk];
  if(cache[v][r][mk])return res-1;
  res=0;
  assert(k<stop[v]);
  int u=son[v][k];
  assert((mk&Two(r)));
  mk^=Two(r);
  for(int sub=mk;sub;sub=(sub-1)&mk) {
    if(BCNT(sub)!=sum[u]) continue;
    for(int t=sub&edge[r];t;t=(t-1)&t) {
      int ur=hash[Low(t)];
      res+=Mul(DP(v,r,(mk^Two(r))^sub,k+1),DP(u,ur,sub,0));
      res%=mod;
    }
  }
  res++;
  return res-1;
}
int DFS(int v,int p,vector<string>& tree) {
  int& res=sum[v];
  stop[v]=0;
  res=1;
  Rep(i,SZ(tree[v])) if(tree[v][i]=='Y'&&p!=i){
    son[v][stop[v]++]=i;
    res+=DFS(i,v,tree);
  }
  return res;
}
class GameWithGraphAndTree {
	public:
	 int calc(vector <string> graph, vector <string> tree) {
     /*
     graph=vector<string>(14,string(14,'Y'));
     tree=vector<string>(14,string(14,'N'));
     Rep(i,13) {
      int r=rand()%(i+1);
      tree[i+1][r]=tree[r][i+1]='Y';
     }*/
		 debug("Start calculation.");
     Rep(i,14)hash[Two(i)]=i;
     const int n=SZ(graph);
     Rep(i,n)Rep(j,n)if(graph[i][j]=='Y')edge[i]^=Two(j);
     DFS(0,-1,tree);
     Rep(i,n)cerr<<i<<"#: stop[i]="<<stop[i]<<" sum[i]="<<sum[i]<<endl;
     int ans=0;
     Rep(i,n) {
       ans+=DP(0,i,Two(n)-1,0);
       ans%=mod;
     }
     return ans;
	}
};
/*
int main() {
  int n;
  cin>>n;
  vector<string> graph(n,string(n,'Y'));
  vector<string> tree(n,string(n,'N'));
  Rep(i,n)graph[i][i]='N';
  Rep(i,n-1) {
    int r=rand()%(i+1);
    tree[i+1][r]=tree[r][i+1]='Y';
  }
  GameWithGraphAndTree game;
  cout<<game.calc(graph,tree)<<endl;
  return 0;
}
*/
