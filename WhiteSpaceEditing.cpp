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
#define Back(str) (str)[(str).length()-1]
#define SZ(vec) ((int)(vec).size())
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
class WhiteSpaceEditing {
  int dp[51][51][52];
	public:
	 int getMinimum(vector <int> lines) {
     const int inf=100000000;
		 debug("Start calculation.");
     vector<int> dist=lines;
     dist.push_back(0);
     const int n=SZ(lines);
     const int m=n+1;
     for(int a=0;a<n;a++)
       for(int i=0;i<m;i++)
         dp[a][a][i]=abs(dist[a]-dist[i]);
     for(int d=1;d<n;d++) {
       for(int a=0;a+d<n;a++) {
         int b=a+d;
         for(int j=0;j<m;j++) {
           int& re=dp[a][b][j];
           re=inf;
           for(int c=a+1;c<=b;c++)
           for(int k=0;k<m;k++) {
             re=min(re,abs(dist[k]-dist[j])+dp[a][c-1][k]+dp[c][b][k]+1);
           }
           cerr<<a<<" "<<b<<" "<<dist[j]<<"="<<dp[a][b][j]<<endl;
         }
       }
     }
     return dp[0][n-1][n];
	}
};
