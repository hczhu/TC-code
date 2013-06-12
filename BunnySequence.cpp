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
#define Rep(i,n) for(typeof(n) i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<b;++i)
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
const int N=1001000;
llint ff[N];
class BunnySequence {
	public:
	 int getNumber(int m, int n) {
		 debug("Start calculation.");
     if(n<2)return 1;
     llint pre=0;
     ff[0]=1;pre=1;
     //for(int s=1;s<=n;s++) {
     For(s,1,n+1) {
       if(s-m-1>=0)pre-=ff[s-m-1];
       ff[s]=pre;
       pre+=ff[s];
       pre%=mod;
     }
     llint ans=1;
     //for(int z=0;z<n-1;z++) {
     Rep(z,n-1) {
       int g=n-1-z;
       if(g==m||g==m-1)ans+=ff[g]-1;
       else {
         ans+=ff[g]+2*mod-2*(g>=m?ff[g-m]:0)+(g>=2*m?ff[g-2*m]:0);
       }
       ans%=mod;
       //debug(z);
       //debug(ans);
     }
     return ans;
	}
};
