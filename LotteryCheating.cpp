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
// Convert anything to string
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
class LotteryCheating {
//Review your code before submission!!!!
	public:
	int minimalChange(string ID) 
	{	
		int res=ID.length();
		for(llint d=0;;d++)
		{
			llint n=d*d;
			string p=convert(n);
			while(p.length()<ID.length())p="0"+p;
			if(p.length()>ID.length())break;
			int sum=0;
			for(int i=0;i<ID.length();i++)
				if(ID[i]!=p[i])sum++;
			cerr<<p<<"="<<sum<<endl;
			res=min(res,sum);
		}
		return res;
	}
};

