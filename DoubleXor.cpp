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
//*******************************************

class DoubleXor {
//Review your code before submission!!!!
	public:
	int calculate(int n) {
		int ans=n;
		for(int i=n-1;i;i--)
		{
			int next=0,m=i;
			for(int j=0,ten=1;j<7;j++,ten*=10)
				next+=ten*(((ans%10)^(m%10))%10),ans/=10,m/=10;
			ans=next;
		}
		return ans;
	}
};

