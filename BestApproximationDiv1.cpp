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

class BestApproximationDiv1 {
	public:
	string findFraction(int m, string number) 
	{
		int best=-1,xx,yy;
		for(int b=1;b<=m;b++)
		for(int a=0;a<b;a++)
		{
			int x=a,y=b;
			int pos=2;
			x*=10;
			while(pos<=7)
			{
				int d=x/y;
				x%=y;x*=10;
				if(d+'0'!=number[pos])break;
				pos++;
			}
			int t=pos-2;
			if(t>best)
			{
				best=t;
				xx=a,yy=b;
			}
		}
		assert(best>=0);
		char buf[1000];
		sprintf( buf,"%d/%d has %d exact digits",xx,yy,best+1);
		return string(buf);
	}
};
