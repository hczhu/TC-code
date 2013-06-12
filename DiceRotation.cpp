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

int get_ans(int x,int y)
{
	int res=0;
	if(x==4)res+=y+1;
	if(x>=2&&y>=2)res++;
	cerr<<x<<" "<<y<<"="<<res<<endl;
	return res;
}
class DiceRotation {
	public:
	int theCount(int gx, int gy) 
	{
		return get_ans(gx,gy)+get_ans(gy,gx);
	}
};
