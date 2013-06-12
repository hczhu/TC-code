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
const int mod=1000000007;
int dp[41][41][2][1601];
class FoxAverageSequence {
  public:
   int theCount(vector <int> seq) {
     const int m=40;
     const int n=seq.size();
     for(int a=0;a<=m;a++)
      for(int b=0;b<2;b++)
        for(int s=0;s<=n*m;s++)
          dp[n][a][b][s]=1;
     for(int len=n-1;len>=0;len--)
      for(int pre=0;pre<=m;pre++)
        for(int cmp=0;cmp<2;cmp++) {
          int* vec=dp[len][pre][cmp];
          int low=seq[len]<0?0:seq[len];
          int high=seq[len]<0?m:seq[len];
          if(cmp)low=max(low,pre);
          if(len==0){
            vec[0]=0;
            for(int k=low;k<=high;k++){
              vec[0]+=dp[1][k][pre>k?1:0][k];
              vec[0]%=mod;
            }
            continue;
          }
          const int ms=len*m;
          for(int s=pre;s<=ms;s++) {
            int kk=min(high,s/len);
            for(int k=low;k<=kk;k++){
              vec[s]+=dp[len+1][k][pre>k?1:0][s+k];
              vec[s]%=mod;
            }
          }
          continue;
          int pre_dp=0;
          for(int s=0,av=-1;s<=ms;s++) {
            int nav=len?s/len:m;
            vec[s]=pre_dp;
            if(nav>av&&nav>=low&&nav<=high) {
              vec[s]+=dp[len+1][nav][pre>nav?1:0][s+nav];
              vec[s]%=mod;
            }
            av=nav;
            pre_dp=vec[s];
            if(len==1)cerr<<len<<" "<<pre<<" "<<cmp<<" "<<s<<"="<<vec[s]<<endl;
          }
        }
     return dp[0][0][0][0];
   }
};
