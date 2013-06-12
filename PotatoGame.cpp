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
#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif

class PotatoGame {
	public:
	string theWinner(int n) 
	{
		// n=5k+r (r<5)
		// 5k - 4^n != 5a or 5b+2
		// 5k+2-4^n != 5a or 5b+2
		// 5k+1 --> 5k
		// 5k+3 --> 5k+2
		// 5k+4 --> 5k
		return ((n%5)==0||(n%5)==2)?"Hanako":"Taro";
	}
};
