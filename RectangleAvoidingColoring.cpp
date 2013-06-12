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
#define NDEBUG
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
vector<string> transpose(const vector<string>& grid) {
  vector<string> res((grid[0].size()),string((grid.size()),' '));
  for(int i=0;i<grid.size();i++)for(int j=0;j<grid[i].size();j++) {
    res[j][i]=grid[i][j];
  }
  return res;
}
#define Idx(a,b) (((7-(a))*(a))/2+(b)-(a)-1)
#define Two(x) ((1)<<(x))
#define Bit(x,b) (1&((x)>>(b)))
typedef long long int llint;
llint dp[51][1<<6][1<<6];
int hash[1000];
llint DP(int mask[2],int r,const vector<string>& grid) {
  hash['B']=0;hash['W']=1;
  int bb=mask[0],ww=mask[1];
  if(r==SZ(grid))return 1;
  llint& res=dp[r][bb][ww];
  if(res>=0)return res;
  res=0;
  const int m=SZ(grid[r]);
  For(mk,0,Two(m)) {
    bool ok=true;
    int nmk[2]={bb,ww};
    Rep(i,m) {
      if(grid[r][i]!='?'&&Bit(mk,i)!=hash[grid[r][i]])ok=false;
    }
    if(!ok)continue;
    Rep(a,m)For(b,a+1,m) {
      if(Bit(mk,a)==Bit(mk,b)) {
        int idx=Idx(a,b);
        if(Bit(mask[Bit(mk,a)],idx))ok=false;
        else nmk[Bit(mk,a)]^=Two(idx);
      }
    }
    if(ok) {
      res+=DP(nmk,r+1,grid);
    }
  }
  //cerr<<bb<<" "<<ww<<" "<<r<<"="<<res<<endl;
  return res;
}
class RectangleAvoidingColoring {
	public:
	 long long count(vector <string> grid) {
     debug(Idx(0,2));
     debug(Idx(2,3));
		 debug("Start calculation.");
     if(SZ(grid)<SZ(grid[0])) {
       grid=transpose(grid);
     }
     const int m=SZ(grid[0]);
     const int n=SZ(grid);
     if(m>=5)return 0;
     memset(dp,0xff,sizeof(dp));
     int mk[2]={0};
     return DP(mk,0,grid);
	}
};
