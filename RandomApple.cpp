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
int grid[100][100];
llint dp[50*50*200];
int sum[100];
void doit(int add,int psum,llint dp[])
{
	psum+=add;
	for(int i=psum;i>=add;i--)
		dp[i]+=dp[i-add];
}

void undoit(int add,int psum,llint dp[])
{
	psum-=add;
	for(int i=add;i<=psum;i++)
		dp[i]-=dp[i-add];
	for(int i=1;i<=add;i++)dp[i+psum]=0;
}
class RandomApple {
	public:
	vector <double> theProbability(vector <string> hundred, vector <string> ten, vector <string> one)
	{
		/*
		hundred.resize(50);
		ten.resize(50);
		one.resize(50);
		for(int i=0;i<50;i++)
		{
			hundred[i]=string(50,'1');
			ten[i]=string(50,'9');
			one[i]=string(50,'9');
		}*/
		const int n=hundred.size();
		const int m=hundred[0].length();
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			grid[i][j]=100*(hundred[i][j]-'0')+10*(ten[i][j]-'0')+one[i][j]-'0';
		for(int i=0;i<n;i++)sum[i]=accumulate(grid[i],grid[i]+m,0);
		dp[0]=1;
		int psum=0;
		for(int i=0;i<n;i++)
		{
			doit(sum[i],psum,dp);
			psum+=sum[i];
		}
//		for(int i=0;i<=psum;i++)cerr<<dp[i]<<" ";cerr<<endl;
		vector<double> res(m,0.0),mul(n,0.0);
		for(int i=0;i<n;i++)
		{
			undoit(sum[i],psum,dp);
			debug(i);
			psum-=sum[i];
//			for(int i=0;i<=psum;i++)cerr<<dp[i]<<" ";cerr<<endl;

			for(int s=0;s<=psum;s++)
			{
				mul[i]+=1.0*dp[s]/(s+sum[i]);
			}
	/*		for(int j=0;j<m;j++)
			{
				res[j]+=1.0*dp[s]*grid[i][j]/(s+sum[i]);
			}*/

			doit(sum[i],psum,dp);
			psum+=sum[i];
		}
//		for(int i=0;i<n;i++)cerr<<mul[i]<<" ";cerr<<endl;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			res[j]+=mul[i]*grid[i][j];
		for(int i=0;i<m;i++)res[i]/=(((1LL)<<n)-1);
		return res;
	}
};
