#line 76 "KDivisibleNumbers.cpp"
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



class KDivisibleNumbers {
	public:
	int findLargest(vector <int> divisors, int K, int A, int B) 
	{
		int res=-1;
		for(int t=A;t<=B;t++)
		{
			int cnt=0;
			for(int i=0;i<divisors.size();i++)
				if(0==(t%divisors[i]))cnt++;
			if(cnt==K)
			{
				debug(t);
				res=t;
			}
		}
		return res;
	}
};


// Powered by FileEdit
