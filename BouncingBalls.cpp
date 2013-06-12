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

#define two(x)  ((1)<<(x))
class BouncingBalls {
//Review your code before submission!!!!
	public:
	double expectedBounces(vector <int> x, int T) {
		double sum=0.0;
		const int n=x.size();
		sort(x.begin(),x.end());
		for(int mk=0;mk<two(n);mk++)
		{
			for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int a=(mk>>i)&1;
				int b=(mk>>j)&1;
				if(a==0&&b==1&&x[j]-x[i]<=2*T)sum++;
			}
		}
		return sum/two(n);
	}
};

