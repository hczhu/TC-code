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

int dp[1001][1001];
class HandlesSpelling {
	public:
	int spellIt(vector <string> parts, vector <string> name) 
	{

		const string all=accumulate(parts.begin(),parts.end(),string(""));
/*		string all;
		while(all.length()<1000)all.push_back('a');
		name.clear();
		for(int i=0;i<50;i++)name.push_back(string(i+1,'a'));*/
		const int n=all.length();
		int ret=-n;
		for(int i=n-1;i>=0;i--)
		{
			for(int d=1;d<=n-i;d++)
				dp[i][d]=dp[i+1][d-1];
			int* pp=dp[i];
			for(int x=0;x<name.size();x++)
			{
				if(name[x].length()>n-i)continue;
				if(name[x]==all.substr(i,name[x].length()))
				{
					int k=name[x].length();
					for(int j=n-i-k;j>=0;j--)
						pp[j+k]=max(pp[j+k],dp[i+k][j]+k);
				}
			}
		}
		for(int a=0;a<n;a++)
		for(int b=a;b<n;b++)
		{
			if(dp[a][b-a+1]==b-a+1)
			{
				ret=max((b-a+1)*(b-a+1)-(n-(b-a+1)-dp[0][a]-dp[b+1][n-b-1]),ret);
			}
		}
		return ret;
	}
};
