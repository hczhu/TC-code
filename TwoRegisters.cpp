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
string calc(int x,int y)
{
//	cerr<<x<<" aa "<<y<<endl;
	assert(x>=y);
	string res;
	char xx='X',yy='Y';
	while(y>1)
	{
		for(int i=x/y;i;i--)res+=string(1,xx);
		x%=y;
		swap(x,y);
		swap(xx,yy);
	}
	assert(y==1&&x>=1);
	while(x>1)res+=string(1,xx),x--;
//	cerr<<x<<" bb "<<y<<"="<<res<<endl;
	assert(x==1&&y==1);
	reverse(res.begin(),res.end());
	return res;
}
int count(int x,int y)
{
//	cerr<<x<<" aa "<<y<<endl;
	assert(x>=y);
	int res=0;
	while(y>1)
	{
		res+=x/y;
		x%=y;
		swap(x,y);
	}
	assert(y==1&&x>=1);
	res+=x-1;

	return res;
}
class TwoRegisters {
	public:
	string minProg(int r) 
	{
		if(r==1)return "";
		string res;
		int len=100000000;
		for(int y=1;y<r;y++)
			if(__gcd(r,y)==1)len=min(len,count(r,y));
		debug(len);
		res=string(len,'Y');
		for(int y=1;y<r;y++)
			if(__gcd(r,y)==1&&count(r,y)==len)res=min(res,calc(r,y));
		return res;
	}
};
