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
typedef long long int llint;
llint inter(llint a1,llint b1,llint a2,llint b2)
{
	llint res=min(b1,b2)-max(a1,a2);
	if(res<0)res=0;
	return res;
}
llint intersection(llint a,llint b,llint x,llint y,llint p)
{
	llint res=0;

	llint si=0,ei=0;
	if(a>y)si=(a-y+p-1)/p;
	if(b>x)ei=(b-x+p-1)/p;
	debug(si);
	debug(ei);
	res+=inter(x+p*si,y+p*si,a,b);
	debug(res);
	ei--;
	if(ei>si)res+=inter(a,b,x+p*(ei),p*ei+y);
	debug(res);
	ei--;
	if(ei>si)res+=(ei-si)*(y-x);
end:
	cerr<<a<<" "<<b<<" intersect "<<x<<" "<<y<<" "<<p<<"=";
	cerr<<res<<endl;
	return res;
}
class LateProfessor {
//Review your code before submission!!!!
	public:
	double getProbability(int wait, int walk, int late, int best, int worst)
	{
		if(walk<=late)return 0.0;
		if(best==worst)
		{
			int p=wait+walk;
			int r=best%p;
			return (r>wait&&r<=wait+walk-late)?1.0:0.0;
		}
		return 1.0*intersection(best,worst,wait,wait+walk-late,wait+walk)/(worst-best);
	}
};

