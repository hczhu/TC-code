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
typedef long long int llint;
const llint up=2000000000;
llint dp[100][100];
bool exist[100][100];
string all;
llint DP(int a,int b,int n)
{
	int len=(b+n-a)%n;
	if(len==2)return 1;
	int des[26];
	for(int i=0;i<len;i++)
	{
		int ind=(i+a)%n;
		if(isupper(all[ind]))des[all[ind]-'A']=i;
	}
	int have=0;
	int rightmost=0;
	for(int i=0;i<len;i++)
	{
		int x=(i+a)%n;
		{
			int j=des[all[x]-'a'];
		
	}
}




class CircleCount {
//Review your code before submission!!!!
	public:
	int countOrder(string circle) 
	{
		const int n=circle.length();
		if(n==2)return 1;

	}
};
