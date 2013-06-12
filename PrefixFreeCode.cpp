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

//************************************************


int dp[501][52];
int best[501];
class PrefixFreeCode {
//Review your code before submission!!!!
	public:
	int minCost(int N, vector <int> cost) 
	{
		const int M=cost.size();
		sort(cost.begin(),cost.end());
		dp[1][1]=cost[0];
		const int inf=100000000;
		for(int i=2;i<=M;i++)dp[1][i]=inf;
		for(int n=2;n<=N;n++)
		{
			for(int m=2;m<=M;m++)
			{
				dp[n][m]=inf;
				for(int k=1;k<n;k++)
					dp[n][m]=min(dp[n][m],dp[n-k][m-1]+k*cost[m-1]+best[k]);
				cerr<<n<<" "<<m<<"="<<dp[n][m]<<endl;
			}
			best[n]=inf;
			for(int m=2;m<=M;m++)best[n]=min(best[n],dp[n][m]);
			debug(best[n]);
			debug(*(min_element(dp[n]+2,dp[n]+M+1)));
			assert(best[n]==(*min_element(dp[n]+2,dp[n]+M+1)));
			dp[n][1]=best[n]+n*cost[0];
			cerr<<n<<" best= "<<best[n]<<endl;
		}
		return best[N];
	}
};
template<typename T>
istream& operator>>(istream& in,vector<T>& vect)
{
	vect.clear();
	int n;
	cerr<<"A integer of length wanted"<<endl;
	in>>n;
	vect.resize(n);
	cerr<<n<<" elements wanted"<<endl;
	for(int i=0;i<n;i++)in>>vect[i];
	return in;
}


int main()
{
	int n;
	cin>>n;
	vector<int> cost;
	cin>>cost;
	PrefixFreeCode pp;
	cout<<pp.minCost(n,cost)<<endl;
	return 0;
}

