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
int getlog(int n) {
  int res=0;
  debug(n);
  for(int t=1;t<n;t<<=1,res++);
  debug(res);
  return res;
}
typedef long long int llint;
llint bino(llint n,llint m) {
  if(m>n||m<0)return 0;
  if(n-m<m)m=n-m;
  llint res=1;
  for(llint x=0;x<m;x++) {
    res*=n-x;
    assert(0==(res%(x+1)));
    res/=x+1;
  }
  return res;
}
pair<llint,llint> minMax(int n,int k) {
  llint mini=0,maxi=0;
  for(int i=0;i<=k&&n>0;i++) {
    llint sub=min(llint(n),bino(k,i));
    n-=sub;
    mini+=sub*i;
    maxi+=sub*(k-i);
  }
  return n?make_pair(numeric_limits<llint>::max(),0LL):make_pair(mini,maxi);
}
class NumberMagic {
	public:
   
	 int theMin(int N, int M) {
		 debug("Start calculation.");
     int low=1,high=N;
     while(low<high) {
       int mid=(low+high)>>1;
       pair<llint,llint> pp=minMax(N,mid);
       cerr<<mid<<"="<<pp.first<<","<<pp.second<<endl;
       if(pp.first>(llint)mid*(llint)M||pp.second<(llint)mid*(llint)M)
         low=mid+1;
       else high=mid;
     }
     return low;
	}
};
