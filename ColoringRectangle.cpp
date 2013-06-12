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

int solve(vector<int> aa[2],double W,double H)
{
	int idx=0;
	double sum=0.0;
	int res=0;
	hline();
	while(sum<W+1e-5)
	{
		if(aa[idx].empty())return 1000;
		double a=aa[idx].back();aa[idx].pop_back();
		debug(idx);
		debug(a);
		debug(sum);
		idx^=1;
		sum+=sqrt(a*a-H*H);
		res++;
	}
	return res;
}

class ColoringRectangle {
//Review your code before submission!!!!
	public:
	int chooseDisks(int width, int height, vector <int> red, vector <int> blue) 
	{
		sort(red.begin(),red.end());
		sort(blue.begin(),blue.end());
		vector<int> aa[2]={red,blue};
		vector<int> bb[2]={blue,red};
		int res=min(solve(aa,width,height),solve(bb,width,height));
		if(res>100)res=-1;
		return res;
	}
};

