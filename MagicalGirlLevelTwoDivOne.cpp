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
//INT_MAX INT_MIN
#include <limits.h>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<(b);++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
typedef long long int llint;
const llint mod=1000000007;
llint dp[11][11][2][1<<10];
llint choose[11][11][2];
#define Two(x) ((1)<<(x))
class MagicalGirlLevelTwoDivOne {
 public:
  int theCount(vector <string> grid, int n, int m) {
    debug("Start calculation.");
    Rep(r,n)Rep(c,m) {
      llint& even=choose[r][c][0];
      llint& odd=choose[r][c][1];
      even=odd=1;
      for(int i=r;i<SZ(grid);i+=n)for(int j=c;j<SZ(grid[0]);j+=m) {
        if(isdigit(grid[i][j])) {
          if(1&(grid[i][j]-'0')) {
            even=0;
          } else {
            odd*=0;
          }
        } else {
          even*=4;even%=mod;
          odd*=5;odd%=mod;
        }
      }
      cerr<<"("<<even<<","<<odd<<") ";
      if(c+1==m)cerr<<endl;
    }
    dp[0][0][0][0]=1;
    Rep(r,n)Rep(c,m) Rep(row,2) Rep(col,Two(m)) if(dp[r][c][row][col]) {
      const llint add=dp[r][c][row][col];
      int nr=r,nc=c+1,nrow,ncol;
      if(nc==m)nc=0,nr++;
      Rep(d,2) {
        nrow=1&(row+d);
        ncol=col^(d<<(c));
        if(nc==0&&nrow==0)continue;
        if(nc==0)nrow=0;
        dp[nr][nc][nrow][ncol]+=add*choose[r][c][d];
        dp[nr][nc][nrow][ncol]%=mod;
      }
      cerr<<r<<" "<<c<<" "<<row<<" "<<col<<"="<<add<<endl;
    }
    return dp[n][0][0][Two(m)-1];
  }
 };
