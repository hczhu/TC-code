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

long long int way[2001];
class FoxMakingDice {
	public:
	long long theCount(int n, int k) {
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			way[i+j]++;
		long long int ans=0;
		for(int s=k;s<=n+n;s++)
		{
			ans+=way[s]*(way[s]-1)*(way[s]-2)/3;
			debug(s);
			debug(way[s]);
			debug(ans);
		}
		return ans;
	}
};
