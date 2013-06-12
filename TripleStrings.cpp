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
#define SZ(vec) ((int)(vec).size())
class TripleStrings {
	public:
	 int getMinimumOperations(string init, string goal) {
		 debug("Start calculation.");
     for(int n=SZ(init);n>0;n--)
       if(init.substr(SZ(init)-n)==goal.substr(0,n))
         return 2*(SZ(init)-n);
     return SZ(init)*2;
	}
};
