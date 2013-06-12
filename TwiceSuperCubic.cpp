#line 39 "TwiceSuperCubic.cpp"
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



class TwiceSuperCubic {
	public:
	int count(int n) 
	{
		map<int,int> mem;
		for(int a=1;a<=1000;a++)
		for(int b=a;b<=1000;b++)
		{
			mem[a*a*a+b*b*b]++;
		}
		debug(mem.size());
		int res=0;
		for(map<int,int>::iterator it=mem.begin();it!=mem.end();it++)
			if(it->first<=n&&it->second==2)res++;
		return res;
	}
};


// Powered by FileEdit
