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
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<b;++i)
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
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
int sum[1000001];
class DivideAndShift {
	public:
	 int getLeast(int N, int M) {
		 debug("Start calculation.");
     vector<int> all;
     const int n=N;
     for(int i=2;i<=N;i++) {
       while(0==(N%i)) {
         all.push_back(i);
         N/=i;
       }
     }
     N=n;
     debug(SZ(all));
     vector<int> sub;
     for(int t=1;t*t<=N;t++) {
       if(0==(N%t)) {
         sub.push_back(t);
         sub.push_back(N/t);
       }
     }
     debug(SZ(sub));
     sort(All(sub));
     Rep(i,SZ(sub)) {
       Rep(j,SZ(all)) {
         if(0==(sub[i]%all[j])) {
           sum[sub[i]]=1+sum[sub[i]/all[j]];
           break;
         }
       }
     }
     int ans=N;
     M--;
     for(int d=-100;d<=100;d++) {
       int m=(((M+d)%N)+N)%N;
       //debug(m);
       Rep(i,SZ(sub)) {
         if(0==(m%sub[i])) {
           ans=min(ans,abs(d)+SZ(all)-sum[sub[i]]);
           cerr<<d<<" "<<m<<" "<<sub[i]<<" "<<SZ(all)-sum[sub[i]]<<endl;
         }
       }
     }
     return ans;
	}
};
