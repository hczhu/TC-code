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
class BunnyComputer {
	public:
	 int getMaximum(vector <int> pr, int k) {
		 debug("Start calculation.");
     int ans=0;
     for(int i=0;i<=k&&i<pr.size();i++) {
       vector<int> all;
       int mini=numeric_limits<int>::max();
       for(int j=i,rank=0;j<pr.size();j+=k+1,rank^=1) {
         all.push_back(pr[j]);
         if(rank==0)mini=min(mini,pr[j]);
       }
       ans+=accumulate(all.begin(),all.end(),0);
       if(all.size()&1)ans-=mini;
     }
     return ans;
	}
};
