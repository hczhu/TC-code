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
llint get_com(int n,int a)
{
	if(n<a)return 0;
	llint res=1;
	for(int i=0;i<a;i++)res*=(n-i);
	for(int i=0;i<a;i++)res/=(i+1);
	return res;
}
class LotteryPyaterochka {
//Review your code before submission!!!!
	public:
	double chanceToWin(int n) {
		//if(n<=2)return 1.0;
		llint ans=0;
		llint tot=get_com(5*n,5);
		debug(tot);
		ans=tot;
		for(int a=0;a<=5;a++)
		for(int b=0;b<=5;b++)
		{
			if(a+2*b!=5)continue;
			llint sum=get_com(n,a);
			debug(sum);
			sum*=get_com(n-a,b);
			debug(sum);
			for(int i=0;i<a;i++)sum*=5;
			for(int i=0;i<b;i++)sum*=10;
			cerr<<a<<" "<<b<<"="<<sum<<endl;
			ans-=sum;
		}
		return 1.0*ans/tot;
	}
};

/*
int main()
{
	printf("%.10lf\n",(1.0-1500.0/get_com(15,5)));
	LotteryPyaterochka ll;
	int n;
	cin>>n;
	cout<<ll.chanceToWin(n)<<endl;
	return 0;
}
*/
