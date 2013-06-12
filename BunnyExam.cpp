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
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
//#define SZ(vec) ((int)(vec).size())
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
#define Two(x) ((1)<<(x))
vector<int> edge[10];
int color[10];
int neib[10];
bool DFS(int n,int k) {
  int v=-1;
  for(int i=0;i<n;i++)if(color[i]==0) {
    if(v==-1||neib[v]<neib[i])v=i;
  }
  if(v==-1)return true;
  int mk=0;
  for(int i=0;i<edge[v].size();i++) if(color[edge[v][i]]) {
    mk|=Two(color[edge[v][i]]-1);
  }
  for(int i=0;i<edge[v].size();i++)neib[edge[v][i]]++;
  for(int i=0;i<k;i++)if(0==(mk&Two(i))) {
    color[v]=i+1;
    if(DFS(n,k))return true;
    color[v]=0;
  }
  for(int i=0;i<edge[v].size();i++)neib[edge[v][i]]--;
  return false;
}
class BunnyExam {
	public:
	 double getExpected(int m, int k, vector <int> link) {
		 debug("Start calculation.");
     const int n=link.size()>>1;
     double ans=1.0*m/k;
     if(k==1) return m==1?1.0:-1.0;
     if(k==2) {
       for(int i=1;i<link.size();i+=2) {
         if(1&(link[i]^link[i-1]))return -1.0;
       }
       return ans;
     }
     for(int i=0;i<n;i++) {
       if(abs(link[2*i]-link[2*i+1])==1)return -1.0;
       for(int j=i+1;j<n;j++) {
         bool ok=false;
         for(int a=0;a<2;a++)for(int b=0;b<2;b++)if(abs(link[2*i+a]-link[2*j+b])==1)ok=true;
         if(ok)edge[i].push_back(j),edge[j].push_back(i);
       }
     }
     return (k>n||DFS(n,k))?ans:-1.0;
	}
};
