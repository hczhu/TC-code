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
class CarrotBoxes {
	public:
	 double theProbability(vector <string> edge) {
		 debug("Start calculation.");
     const int n=edge.size();
     for(int k=0;k<n;k++)
       for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
           if(edge[i][k]=='Y'&&edge[k][j]=='Y')edge[i][j]='Y';
     vector<bool> used(n);
     vector<int> scc,node;
     for(int i=0;i<n;i++) {
       if(used[i])continue;
       debug(i);
       int cnt=0;
       bool indeg=false;
       for(int j=0;j<n;j++) {
         if(edge[i][j]=='Y'&&edge[j][i]=='Y') {
           cnt++;
           used[j]=true;
         }
         else if(edge[j][i]=='Y')indeg=true;
       }
       if(!indeg) {
         node.push_back(i);
         scc.push_back(cnt);
       }
       debug(cnt);
       debug(indeg);
     }
     int ans=scc.size();
     for(int i=0;i<scc.size();i++) {
       if(scc[i]>1)continue;
       vector<int> reach(n,0);
       for(int j=0;j<scc.size();j++) {
         if(j==i)continue;
         int v=node[j];
         for(int x=0;x<n;x++)if(edge[v][x]=='Y')reach[x]++;
       }
       reach[node[i]]++;
       if(find(reach.begin(),reach.end(),0)==reach.end()) {
         debug(i);
         debug(node[i]);
         return 1.0*(n-ans+1)/n;
       }
     }
     return 1.0*(n-ans)/n;
	}
};
