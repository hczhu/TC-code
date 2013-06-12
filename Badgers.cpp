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

class Badgers {
	public:
	int feedMost(vector <int> a, vector <int> b, int t) 
	{
		int n=a.size();
		while(n)
		{
			vector<int> all(a.size());
			for(int i=0;i<a.size();i++)all[i]=a[i]+b[i]*(n-1);
			sort(all.begin(),all.end());
			if(accumulate(all.begin(),all.begin()+n,0)<=t)break;
			n--;
		}
		return n;
	}
};
