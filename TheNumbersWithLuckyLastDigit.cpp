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
class TheNumbersWithLuckyLastDigit {
	public:
	 int find(int n) {
		 debug("Start calculation.");
     const int inf=1000000000;
     int ans=inf;
     for(int a=0;a<=1000;a++)
     for(int b=0;b<=1000;b++) {
       int t=4*a+7*b;
       if(t==0)continue;
       if(t<=n&&((n-t)%10)==0) {
         ans=min(ans,a+b);
       }
     }
     return ans==inf?-1:ans;
	}
};
