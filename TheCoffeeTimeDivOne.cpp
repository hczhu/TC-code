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
typedef long long int llint;
class TheCoffeeTimeDivOne {
	public:
	long long find(int n, vector <int> tea) 
	{
		llint res=0;
		res+=tea.size()*4+(tea.size()+6)/7*47;
		debug(res);
		llint m=n-tea.size();
		res+=m*4+(m+6)/7*47;
		debug(res);
		sort(tea.begin(),tea.end());
		for(int i=tea.size()-1;i>=0;i-=7)res+=tea[i]*2;

		debug(res);
		tea.push_back(0);
		sort(tea.begin(),tea.end());
		reverse(tea.begin(),tea.end());
		int pre=n,rem=0;
		for(int i=0;i<tea.size();i++)
		{
			if(tea[i]==pre)pre--;
			else if(pre>tea[i])
			{
				int use=min(pre-tea[i],rem);
				rem-=use;
				pre-=use;
				cerr<<tea[i]<<" "<<pre<<endl;
				if(pre<=tea[i])
				{
					pre=tea[i]-1;
					continue;
				}
				llint m=(pre-tea[i]+6)/7;
				rem=7-((pre-tea[i])%7);
				if(rem==7)rem=0;
				debug(m);
				res+=(pre*2-7*(m-1))*m;
				debug(res);
				debug(rem);
				pre=tea[i]-1;
			}
			else assert(0);
		}
		return res;
	}
};
