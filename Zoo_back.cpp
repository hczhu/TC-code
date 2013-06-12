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
int cnt[100];
class Zoo {
	public:
	 long long theCount(vector <int> ans) {
		 debug("Start calculation.");
     Rep(i,SZ(ans)) cnt[ans[i]]++;
     long long int res=1;
     int sym=0;
     Rep(i,100) {
       if(cnt[i]>2)return 0;
       if(i&&cnt[i]>cnt[i-1])return 0;
       if(2==cnt[i])res<<=1;
       if(1==cnt[i])sym=1;
     }
     return res<<sym;
	}
};
