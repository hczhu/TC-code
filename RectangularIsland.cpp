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
double dp1[10000],dp2[10000];
double simulate(int steps,int n,int x)
{
	double *pre=dp1,*next=dp2;
	memset(pre,0,sizeof(pre[0]*n));
	pre[x]=1.0;
	while(steps--)
	{
		for(int j=0;j<n;j++)
		{
			next[j]=pre[j]*.5;
			if(j)next[j]+=pre[j-1]*0.25;
			if(j+1<n)next[j]+=pre[j+1]*0.25;
		}
		swap(pre,next);
	}
	return accumulate(pre,pre+n,(double)0.0);
}
class RectangularIsland {
	public:
	double theProbablity(int width, int height, int x, int y, int steps) 
	{
		return simulate(steps,width,x)*simulate(steps,height,y);
	}
};
