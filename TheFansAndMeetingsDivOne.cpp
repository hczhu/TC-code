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
double dp[41][40*40+1];
double psum[41][40*40+2];

vector<double> DP(vector<int> low,vector<int> up,int p)
{
	const int n=low.size();
	memset(dp,0,sizeof(dp));
	memset(psum,0,sizeof(psum));
	dp[0][0]=1.0;
	const int tot=accumulate(up.begin(),up.end(),0);
	for(int s=1;s<=tot+1;s++)psum[0][s]=1;
	for(int i=0;i<n;i++)
	{
		double k=1.0/(up[i]+1-low[i]);
		for(int j=p;j;j--)
		for(int s=1;s<=tot;s++)
		{
			if(low[i]<=s)dp[j][s]+=(psum[j-1][s+1-low[i]]-psum[j-1][s-min(up[i],s)])*j/(n+1-j)*k;
			//for(int x=low[i];x<=up[i]&&x<=s;x++)
			//	dp[j][s]+=dp[j-1][s-x]*j/(n+1-j)*k;
		}
		for(int j=1;j<=p;j++)
		for(int s=1;s<=tot+1;s++)
			psum[j][s]=psum[j][s-1]+dp[j][s-1];

	}
	vector<double> res(tot+1);
	double sum=accumulate(dp[p],dp[p]+tot+1,0.0);
	debug(sum);
	for(int i=0;i<=tot;i++)
	{
		res[i]=dp[p][i];
		cerr<<i<<" : "<<dp[p][i]<<" "<<res[i]<<endl;;
	}
	return res;
}
class TheFansAndMeetingsDivOne {
//Review your code before submission!!!!
	public:
	double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB, int k) 
	{
		int sum1=accumulate(maxJ.begin(),maxJ.end(),0);
		int sum2=accumulate(maxB.begin(),maxB.end(),0);
		int sum=min(sum1,sum2);
		debug(sum);
		vector<double> pro1=DP(minJ,maxJ,k);
		vector<double> pro2=DP(minB,maxB,k);
		double ans=0;
		for(int i=1;i<=sum;i++)
		{
			ans+=pro1[i]*pro2[i];
		}
		return ans;
	}
};

// Powered by FileEdit


// Powered by FileEdit
