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
llint dp[51][1001];
bool exist[51][1001];
vector<int> seq;
llint DP(int pos,int up)
{
	if(pos==-1)return 1;
	if(up==0)return 0;
	if(up>seq[pos])up=seq[pos];
	if(exist[pos][up])return dp[pos][up];
	exist[pos][up]=true;
	llint res=DP(pos,up-1);
	int cnt=0;
	for(int i=pos;i>=0;i--)
		if(seq[i]>=up)cnt++;
	res+=(DP(pos-1,up-1)*cnt)%mod;
	res%=mod;
//	cerr<<pos<<" "<<up<<"="<<res<<endl;
	dp[pos][up]=res;
	return res;
}
class RabbitNumbering {
//Review your code before submission!!!!
	public:
	int theCount(vector <int> num) 
	{
		const int n=num.size();
		sort(num.begin(),num.end());
		seq=num;
		return DP(n-1,1000);
	}
};

