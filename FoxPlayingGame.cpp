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
#include <stack>
#include <stdarg.h>
//#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif


double dp_max[200][200],dp_min[200][200];
class FoxPlayingGame {
  public:
  double theMax(int nA, int nB, int paramA, int paramB) {
    dp_max[0][0]=dp_min[0][0]=0.0;
    double aa=paramA/1000.0;
    const double bb=paramB/1000.0;
    for(int s=1;s<=nA+nB;s++) {
      for(int a=0;a<=s;a++) {
        int b=s-a;
        dp_max[a][b]=-1e100;
        if(a)dp_max[a][b]=max(dp_max[a][b],max(dp_max[a-1][b]+aa,dp_min[a-1][b]+aa));
        if(b)dp_max[a][b]=max(dp_max[a][b],max(dp_max[a][b-1]*bb,dp_min[a][b-1]*bb));
        dp_min[a][b]=1e100;
        if(a)dp_min[a][b]=min(dp_min[a][b],min(dp_max[a-1][b]+aa,dp_min[a-1][b]+aa));
        if(b)dp_min[a][b]=min(dp_min[a][b],min(dp_max[a][b-1]*bb,dp_min[a][b-1]*bb));
      }
    }
    return dp_max[nA][nB];
  }
};
