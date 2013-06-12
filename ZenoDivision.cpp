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
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif

typedef unsigned long long int llint;

class ZenoDivision {
	public:
	string cycle(string sa, string sb) 
	{
		istringstream ina(sa),inb(sb);
		llint a,b;
		ina>>a;inb>>b;
		debug(a);
		debug(b);
		for(int n=1;n<=60;n++)
		{
			llint ones=0;
			for(int i=0;i<n;i++)ones<<=1,ones^=1;
			debug(ones);
			if(ones%b)continue;
			llint want=a*(ones/b);
			string res(n,'-');
			for(int k=1;k<=n;k++)
				if(want&((1LL)<<(n-k)))res[k-1]='*';
			return res;
		}
		return "impossible";
	}
};
