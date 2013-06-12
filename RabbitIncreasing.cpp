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
typedef long long int llint;
//typedef int llint;
const llint mod=1000000009;
llint Go(llint& x1,llint& x2,int n,const llint mod) {
  x1%=mod;x2%=mod;
  llint res=(x1+x2)%mod;
  assert(n>=0);
  if(n==0)return res;
  n--;
  swap(x1,x2);
  res+=x2;res%=mod;
  while(n>0) {
    llint t=(x1+x2)%mod;
    x1=x2;
    x2=t;
    res+=x2;res%=mod;
    n--;
  }
  return res;
}
class RabbitIncreasing {
	public:
	 int getNumber(vector <int> leaving, int k) {
		 debug("Start calculation.");
     if(leaving[0]==1||leaving[0]==2)return 0;
     llint x1=1,x2=0;
     llint y1=x1,y2=x2;
     int year=2;
     llint ans=0;
     llint mod2=1LL<<SZ(leaving);
     Rep(i,SZ(leaving)) {
       int sum=Go(x1,x2,leaving[i]-year,mod);
       Go(y1,y2,leaving[i]-year,mod2);
       debug(x1);debug(x2);
       debug(y1);debug(y2);
       x1=(x1+mod*((y1^x1)&1))>>1;
       y1>>=1;
       debug(x1);debug(x2);
       debug(leaving[i]);
       debug(year);
       year=leaving[i];
       mod2>>=1;
       debug("----------------------");
     }
     ans=Go(x1,x2,k-year,mod);
     return ans;
	}
};
