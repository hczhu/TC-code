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
const int mod= 1000000009;
int com[101][101];
int dp[1000001];
class NumberPyramids {
//Review your code before submission!!!!
	public:
	int count(int baseLength, int top) {
		int n=baseLength-1;
		// check top>=2^n
		if(n>30)return 0;
		if(top<(1<<n))return 0;
		top-=(1<<n);
		debug(top);
		com[0][0]=1;
		for(int i=1;i<=100;i++)
		{
			com[i][0]=com[i][i]=1;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j]+com[i-1][j-1])%mod;
		}
		dp[0]=1;
		for(int i=0;i<=n;i++)
		{
			int add=com[n][i];
			//debug(add);
			for(int k=add;k<=top;k++)dp[k]=(dp[k]+dp[k-add])%mod;
		}
		return dp[top];
	}
};



// Powered by FileEdit
