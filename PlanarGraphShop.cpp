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
template<typename T>
vector<T> unique(vector<T> table)
{
	sort(table.begin(),table.end());
	return vector<T>(table.begin(),unique(table.begin(),table.end()));
}
const int X=37;
const int N=50000;
int dp[N+1];
class PlanarGraphShop {
//Review your code before submission!!!!
	public:
	int bestCount(int n) {
		vector<int> planar;
		assert(X*X*X>N);
		for(int x=1;x<=X;x++)
		{
			for(int y=0;y<=3*x-6;y++)
				planar.push_back(x*x*x+y*y);
		}
		planar.push_back(1);
		planar.push_back(8);
		planar.push_back(9);
		planar=unique(planar);
		debug(planar.size());
		for(int i=0;i<planar.size();i++)
			if(planar[i]==9||planar[i]==36)debug("Bingo");
		for(int i=1;i<=n;i++)dp[i]=i;
		for(int i=0;i<planar.size();i++)
		{
			const int cost=planar[i];
			for(int j=cost;j<=n;j++)
				dp[j]=min(dp[j-cost]+1,dp[j]);
		}
		return dp[n];
	}
};

