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

class LuckyRemainder {
	public:
	int getLuckyRemainder(string X) {
          const int n=X.length();
          int ans=1,s=0;
          for(int i=0;i<n;i++) {
            if(i)ans<<=1,ans%=9;
            s+=X[i]-'0';
          }
          ans*=s%9;
          ans%=9;
          return ans;
	}
};
