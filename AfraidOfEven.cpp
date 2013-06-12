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
#define Rep(i,n) for(typeof(n) i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<b;++i)
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
//#define SZ(vec) ((int)(vec).size())
//#define All(vec) (vec).begin(),(vec).end()
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
#define Low(x) ((((x)^((x)-1))&x))
class AfraidOfEven {
	public:
	 vector <int> restoreProgression(vector <int> seq) {
		 debug("Start calculation.");
     const int n=seq.size();
     for(;;seq[0]<<=1) {
       int best=numeric_limits<int>::max();
       bool ok=false;
       For(i,1,n) {
         int d=(seq[i]-seq[0])/i;
         if((seq[i]-seq[0])%i)continue;
         bool good=true;
         For(j,1,n) {
           int s=(seq[0]+j*d);
           if(s<=0||(s%seq[j])||Low((s/seq[j]))!=s/seq[j])good=false;
         }
         if(good) {
           ok=true;
           best=min(best,d);
         } 
       }
       if(ok) {
         int d=best;
         debug(d);
         debug(seq[0]);
         For(j,1,n) seq[j]=seq[0]+d*j;
         break;
       }
     }
     return seq;
	}

};
