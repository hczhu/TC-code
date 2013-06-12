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
const llint mod=1000000007;
llint table[101][101];

vector<llint> get_poly(vector<llint> inter)
{
	hline();
	for(int i=0;i<inter.size();i++)cerr<<inter[i]<<" ";cerr<<endl;
	vector<llint> res=inter;
	for(int i=0;i<res.size();i++)
	{
		res[i]=inter[0];
		vector<llint> tmp;
		for(int j=1;j<inter.size();j++)
		{
			tmp.push_back((inter[j]-inter[j-1]+mod)%mod);
		}

		inter=tmp;
	}
	for(int i=0;i<res.size();i++)cerr<<res[i]<<" ";cerr<<endl;
	return res;
}
template<typename T>
T __gcd(T n,T m,T& a,T& b)
{
	T a1=0,b1=1;
	a=1,b=0;
	// a*n+b*m=n;  a1*n+b1*m=m;
	while(m)
	{
		T c=n/m;
		T r=n-m*c;
		T t;
		t=a;a=a1;a1=t-c*a1;
		t=b;b=b1;b1=t-c*b1;
		n=m;m=r;
	}
	return n;
}
llint getReverse(llint a,llint p,llint rev[]=NULL)
{
	if(rev!=NULL)return rev[a];
	llint x,y;
	assert(1==std::__gcd(a,p));
	__gcd(a,p,x,y);
	return ((x%p)+p)%p;
}
llint bino(llint n,llint k)
{
	if(n<k)return 0;
	llint res=1;
	for(int i=1;i<=k;i++)
	{
		res*=(n-i+1);
		res%=mod;
		res*=getReverse(i,mod);
		res%=mod;
	}
	return res;
}
class SuperSum {
//Review your code before submission!!!!
	public:
	int calculate(int k, int n) 
	{
		for(llint t=2;t*t<=mod;t++)assert(mod%t);
		return bino(n+k,k+1);
	}
};

