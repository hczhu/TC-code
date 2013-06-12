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
int dp[8*9][2][1<<16];
vector<int> want,current,dist;
int DP(int a,int b,int mid,int c,int n,int mk) {
  if(mk+1==(1<<n)) {
    cerr<<a<<" "<<b<<" "<<c<<" "<<mk<<endl;
    assert(0);
    return 0;
  }
  int code=(mid-a)*(n-mid)+b-mid;
  assert(code<8*9);
  int& res=dp[code][c][mk];
  if(res>=0)return res;
  const int inf=numeric_limits<int>::max();
  res=inf;
  Rep(i,n) {
    if(mk&(1<<i))continue;
    int para=1+abs(want[i]-current[c?b:a]);
    int t=inf;
    if(a) {
      t=(c==0?dist[a]-dist[a-1]:dist[b]-dist[a-1])+DP(a-1,b,mid,0,n,mk^(1<<i));
    }
    if(b+1<n) {
      t=min(t,(c==1?dist[b+1]-dist[b]:dist[b+1]-dist[a])+DP(a,b+1,mid,1,n,mk^(1<<i)));
    }
    if(t==inf)t=0;
    res=min(res,max(para,t));
  }

  return res;
}
class TicketPrinters {
	public:
	 int minTime(int currentPrinter, vector <int> printerDistance, vector <int> startingValues, vector <int> wantedValues) {
		 debug("Start calculation.");
     debug(sizeof(dp));
     memset(dp,0xff,sizeof(dp));
     current=startingValues;
     want=wantedValues;
     const int n=SZ(want);
     dist.resize(n,0);
     For(i,1,n) dist[i]=dist[i-1]+printerDistance[i-1];

     debug(n);
     return DP(currentPrinter,currentPrinter,currentPrinter,0,n,0);
	}
};
