#line 66 "IncredibleMachine.cpp"



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



class IncredibleMachine {
	public:
	double gravitationalAcceleration(vector <int> x, vector <int> y, int tot) 
	{		
		const int n=x.size();
		double low=0.0,high=1e6;
		for(int cc=0;cc<200;cc++)
		{
			double mid=(low+high)/2;
			double v=0.0,sum=0.0;
			for(int i=1;i<n;i++)
			{
				double dx=x[i]-x[i-1];
				double dy=y[i-1]-y[i];
				double s=sqrt(dx*dx+dy*dy);
				double g=mid*dy/s;
				double t=(-v+sqrt(v*v+2.0*g*s))/g;
				debug(i);
				debug(t);
				sum+=t;
				v+=t*g;
			}
			if(sum<tot)high=mid;
			else low=mid;
		}
		return low;
	}
};


// Powered by FileEdit
