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
#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif

const int M=1000;
double com[M+1][M+1];
int head[10],tail[10];
void calcom(double a)
{
	com[0][0]=1.0;
	double b=1.0-a;
	for(int i=1;i<=M;i++)
	{
		com[i][0]=com[i-1][0]*b;
		com[i][i]=com[i-1][i-1]*a;
		for(int j=1;j<i;j++)
			com[i][j]=com[i-1][j-1]*a+com[i-1][j]*b;
	}
}
double dp[10][M+1];
int sum[11];
class SequentialThreads {
	public:
	double expectedExecutionTime(vector <string> threads) 
	{
		const int n=threads.size();
		for(int i=0;i<n;i++)
		{
			int a=1,b=0;
			for(int j=0;j<threads[i].length();j++)
			{
				if(threads[i][j]=='S')swap(a,b);
				head[i]+=a;tail[i]+=b;
			}
			cerr<<head[i]<<" "<<tail[i]<<endl;
			sum[i+1]=sum[i]+head[i]+tail[i];
		}
		for(int i=1;i<=M;i++)dp[0][i]=(i==head[0]?1.0:0.0);
		for(int i=1;i<n;i++)
		{
			calcom(1.0/(i+1));
			for(int t=sum[i+1];t<=M;t++)
			{
				int tt=t-tail[i];
				double& res=dp[i][t];
				for(int k=tt-head[i];k<=tt;k++)
				{
					int rem=t-k;
					assert(rem>=tail[i]&&rem<=head[i]+tail[i]);
					int j1=tail[i]+head[i]-rem,j2=k-sum[i];
					if(rem>tail[i])j1=j2=head[i]+tail[i]-rem;
					for(int j=j1;j<=j2;j++)
						res+=dp[i-1][k-j]*com[k-1][j]*i/(i+1);
				}
				//cerr<<i<<" "<<t<<" "<<res<<endl;
			}
			debug(accumulate(dp[i],dp[i]+M+1,0.0));
		}
		double ans=0.0;
		for(int i=1;i<=M;i++)ans+=dp[n-1][i]*i;
		return ans;
	}
};
