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
typedef long long int llint;
const llint mod=1000000009;
class FoxStones {
	public:
	 int getCount(int N, int M, vector <int> sx, vector <int> sy) {
		 debug("Start calculation.");
     map<vector<int>,int> mem;
     const int n=SZ(sx);
     for(int x=1;x<=N;x++)
     for(int y=1;y<=M;y++) {
       vector<int> sig(n);
       for(int i=0;i<n;i++)sig[i]=max(abs(sx[i]-x),abs(sy[i]-y));
       mem[sig]++;
     }
     llint ans=1;
     for(map<vector<int>,int>::iterator itr=mem.begin();itr!=mem.end();++itr) {
       debug(itr->second);
       llint t=1;
       for(int j=1;j<=itr->second;j++)t*=j,t%=mod;
       ans*=t;
       ans%=mod;
     }
     return ans%mod;
	}
};
