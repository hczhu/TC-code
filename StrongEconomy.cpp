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

class StrongEconomy {
//Review your code before submission!!!!
	public:
	long long earn(long long n, long long k, long long price, long long target) {
		if((target+n-1)/n<=k)return 1;
		llint have=0;
		llint res=(target+n*k-1)/(n*k);
		llint round=0,more;
		for(;have<target;)
		{
			round++;have+=n*k;
			if(have>=target)
			{
				res=min(res,round);
				break;
			}
			res=min(res,round+(target-have+n*k-1)/(n*k));
			if(price>have)more=(price-have+n*k-1)/(n*k),round+=more,have+=more*n*k;
			for(;price<=have&&n*k<=target;)
			{
				have-=price;
				n<k?n++:k++;
				res=min(res,round+(target-have+n*k-1)/(n*k));
			}
		}
		return res;
	}
};
/*
int main()
{
	llint n,k,price,target;
	cin>>n>>k>>price>>target;
	StrongEconomy ss;
	cout<<ss.earn(n,k,price,target)<<endl;
	return 0;
}
*/
