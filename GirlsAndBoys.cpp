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

class GirlsAndBoys {
	public:
	int sortThem(string row) 
	{
		int a=0,b=0;
		for(int i=0;i<row.length();i++)
		for(int j=i+1;j<row.length();j++)
		{
			if(row[i]=='G'&&row[j]=='B')a++;
			else if(row[i]!=row[j])b++;
		}
		return min(a,b);
	}
};
