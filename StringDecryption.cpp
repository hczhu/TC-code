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
typedef long long int llint;
const llint mod=1000000009;
string all;
llint dp[501][11][11][2];
bool exist[501][11][2];
bool zero[501][501];
llint num[501][501];
llint DP(int pos,int pre,int cut,int have)
{
	if(pos==all.length())
	{
		if(have==0&&pre<10)return 1;
		return 0;
	}
	llint& res=dp[pos][pre][have];
	if(exist[pos][pre][have])return res;
	res=0;
	exist[pos][pre][have]=true;
	for(int i=pos+1;i+1<all.length();i++)
	{
		int d=all[i]-'0';
		if(d==pre)continue;
		if(pre==10&&d==0)continue;
		if(zero[pos][i-1])continue;
		llint m=num[pos][i-1];

	}

	cerr<<pos<<" "<<pre<<" "<<have<<"="<<res<<endl;
}
class StringDecryption {
	public:
	int decrypt(vector <string> code) {
		all=accumulate(code.begin(),code.end(),string(""));
		debug(all);
		const int n=all.length();
		for(int i=0;i<n;i++)
		{
			num[i][i]=all[i]-'0';
			zero[i][i]=all[i]=='0';
			for(int j=i+1;j<n;j++)
				num[i][j]=((num[i][j-1]*10)+all[j]-'0')%mod,
				zero[i][j]=zero[i][j-1]&&(all[j]=='0');
		}

	}
};
