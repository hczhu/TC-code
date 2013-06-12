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
vector<int> edge[200];
typedef long long int llint;
llint solve(const vector<vector<int> >& edge,int n,int m) {
  llint ans=1;
  vector<bool> visited(n+m,false);
  for(int i=n;i<n+m;i++) {
    if(visited[i])continue;
    queue<int> qq;
    qq.push(i);visited[i]=true;
    llint cnt=0,total=0;
    while(qq.size()) {
      int v=qq.front();qq.pop();
      if(v>=n)cnt++;
      total++;
      for(int j=0;j<edge[v].size();j++) {
        if(!visited[edge[v][j]]) {
          visited[edge[v][j]]=true;
          qq.push(edge[v][j]);
        }
      }
    }
    debug(i);
    debug(cnt);
    debug(total);
    if(cnt*2>total)return 0;
    if(cnt*2<total) {
      assert(cnt*2+1==total);
      ans*=(total-cnt);
    }
  }
  debug(ans);
  return ans;
}
class OneDimensionalBalls {
	public:
	 long long countValidGuesses(vector <int> pic1, vector <int> pic2) {
     pic1.swap(pic2);
		 debug("Start calculation.");
     const int n=pic1.size();
     const int m=pic2.size();
     llint ans=0;
     set<int> mem;
     mem.insert(0);
     for(int i=0;i<n;i++)for(int j=0;j<m;j++) {
       int d=abs(pic2[j]-pic1[i]);
       if(mem.count(d))continue;
       mem.insert(d);
       vector<vector<int> > edge(n+m);
       for(int a=0;a<n;a++)for(int b=0;b<m;b++) {
         if(abs(pic1[a]-pic2[b])==d) {
           edge[a].push_back(b+n);
           edge[b+n].push_back(a);
         }
       }
       cerr<<"---------------------"<<endl;
       debug(d);
       ans+=solve(edge,n,m);
     }
     return ans;
	}
};
