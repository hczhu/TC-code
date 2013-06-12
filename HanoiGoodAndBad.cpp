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
int thr[21];
class HanoiGoodAndBad {
	public:
    int getadd(int n,int a,int& x,int& y) {
      if(a==x)return 0;
      if(a==y)return thr[n-1]*2;
      swap(x,y);
      return thr[n-1];
    }
    int solve(int n,int dave,int a,int b,int c,int x,int y) {
      if(n==0)return 0;
      //assert(n>0);
      int add=((1<<(n-1))-1>=dave)?getadd(n,a,x,y):getadd(n,c,x,y);
      return ((1<<(n-1))-1>=dave)?add+solve(n-1,dave,a,c,b,x,y):
          add+solve(n-1,dave-(1<<(n-1)),b,a,c,x,y);
    }
	 int moves(int N, int Dave) {
		 debug("Start calculation.");
     thr[0]=1;
     for(int i=1;i<=20;i++)thr[i]=thr[i-1]*3;
     return solve(N,Dave,0,1,2,0,2);
	}
};
