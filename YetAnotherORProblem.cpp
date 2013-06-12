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
typedef int llint;
#define Two(x)  ((1)<<(x))
const llint mod=1000000009;
llint dp[65][21][1<<10][11];
class YetAnotherORProblem {
	public:
	 int countSequences(vector<long long> R) {
		 debug("Start calculation.");
     const int n=R.size();
     int m=-1;
     long long up=*max_element(All(R));
     while(up) m++,up>>=1;
     debug(m);
     Rep(mk,Two(n))dp[0][0][mk][0]=1;
     For(k,0,m+1)for(int mk=Two(n)-1;mk>=0;mk--)Rep(c,2*n+1){
       //if((c&3)>1)continue;
       llint* cur=dp[k+1][c][mk];
       if((c<<1)<=(n<<1))cur[n]+=dp[k][(c<<1)][mk][0];
       if((c<<1)+1<=(n<<1))cur[n]+=dp[k][(c<<1)+1][mk][0];
       cur[n]%=mod;
       for(int r=n-1;r>=0;r--) {
         if(r==0&&(c&3)>1)continue;
         const int bit=1&(R[r]>>k);
         cur[r]=dp[k+1][c][mk|(bit<<r)][r+1];
         cur[r]+=(c>=1&&(bit||(Two(r)&mk)))?dp[k+1][c-1][mk][r+1]:0;
         cur[r]%=mod;
       }
     }
     llint ans=dp[m+1][0][0][0]+dp[m+1][1][0][0];
     return ans%mod;
	}
};
/*
int main() {
  YetAnotherORProblem yet;
  vector<long long> R;
  long long x;
  while(cin>>x)R.push_back(x);
  cout<<yet.countSequences(R)<<endl;
  return 0;
}

*/
