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
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
double dp[100][100];
double prob[2][100];
class MuddyRoad {
	public:
	 double getExpectedValue(vector <int> road) {
		 debug("Start calculation.");
     const int n=SZ(road);
     Rep(i,n)prob[1][i]=1.0*road[i]/100,prob[0][i]=1.0-prob[1][i];
     dp[0][0]=1.0;
     For(i,1,n)Rep(k,i+1) {
       dp[i][k]=dp[i-1][k]*prob[0][i-1];
       if(i>=2)dp[i][k]+=dp[i-2][k]*prob[1][i-1]*prob[0][i-2];
       if(i>=2&&k>0)dp[i][k]+=dp[i-2][k-1]*prob[1][i-1]*prob[1][i-2];
       cerr<<i<<" "<<k<<"="<<dp[i][k]<<endl;
     }
     double ans=0.0;
     Rep(i,n)ans+=dp[n-1][i+1]*(i+1);
     return ans;
	}
};
