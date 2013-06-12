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
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
double dp[1001][1001];
double aa[1001],xx[1001],yy[1001];
class TheTicketsDivOne {
	public:
	 double find(int nn, int mm) {
		 debug("Start calculation.");
     dp[1][1]=1.0;
     for(int n=2;n<=nn;n++) {
       int i=n;
       aa[1]=1.0/6;
       for(int j=2;j<=n;j++)aa[j]=dp[i-1][j-1]/3;
       xx[1]=0.5,yy[1]=aa[1];
       for(int j=2;j<=n;j++) {
         xx[j]=xx[j-1]/2;
         yy[j]=yy[j-1]/2+aa[j];
       }
       dp[n][n]=yy[n]/(1.0-xx[n]);
       debug(dp[n][n]);
       for(int j=1;j<n;j++)
         dp[n][j]=xx[j]*dp[n][n]+yy[j];
     }
     return dp[nn][mm];
	}
};
