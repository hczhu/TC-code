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

class JingleRingle {
	public:
	int profit(vector <int> buy, vector <int> sell, int tax) 
	{
		sort(buy.begin(),buy.end(),greater<int>());
		sort(sell.begin(),sell.end());
		int ret=0;
		for(int a=1;a<=sell.size();a++)
		{
			int earn=-accumulate(sell.begin(),sell.begin()+a,0);
			for(int i=0,rem=a;i<buy.size()&&rem;i++)
			{
				int add=buy[i]-(buy[i]*tax)/100;
				if(add>0)earn+=add,rem--;
			}
			ret=max(ret,earn);
		}
		return ret;
	}
};
