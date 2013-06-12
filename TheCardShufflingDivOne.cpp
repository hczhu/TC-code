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



class TheCardShufflingDivOne {
	public:
	int shuffle(int n, int left, int right) 
	{
		if(n==1)return 1;
		int last,m;
		if(n&1)m=3,last=(left&1)?0:2;
		else last=0,m=2;
		while(m<n)
		{
			int a=(m+1)/2;
			int b=m-a;
			if(last<a)
			{
				last=a-1-last;
				a++;b++;
				last-=left%a;last+=a;last%=a;
				if(a==b)last=(a-1-last)*2+1;
				else last=(a-1-last)*2;
			}
			else
			{
				last-=a;
				last=b-1-last;
				a++;b++;
				last-=right%b;last+=b;last%=b;
				if(a==b)last=(b-1-last)*2;
				else last=(b-1-last)*2+1;
			}
			debug(last);
			m+=2;
		}
		return n-last;
	}
};
