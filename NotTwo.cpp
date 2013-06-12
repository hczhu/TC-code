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

class NotTwo {
//Review your code before submission!!!!
	public:
	int maxStones(int width, int height) {
		int res=0;
		for(int dx=0;dx<2;dx++)
		for(int dy=0;dy<2;dy++)
		{
			int x=0,y=0;
			for(int i=dx;i<width;i+=2)x++;
			for(int j=dy;j<height;j+=2)y++;
			cerr<<x<<" "<<y<<endl;
			res+=(x*y+1)/2;
			debug(res);
		}
		return res;
	}
};

