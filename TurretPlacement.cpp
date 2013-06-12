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

typedef long long int llint;

class TurretPlacement {
//Review your code before submission!!!!
	public:
	long long count(vector <int> x, vector <int> y) 
	{
		llint res=0;
		for(int i=0;i<x.size();i++)
		for(int j=i+1;j<x.size();j++)
		{
			llint sd=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			sd<<=2;
			llint d=sqrt(sd)-1;
			while(d<0||(d+1)*(d+1)<=sd)d++;
			debug(sd);
			debug(d);
			llint add=(d*(d-1)/2);
			debug(add);
			res+=add;
		}
		return res;
	}
};

