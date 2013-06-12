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


double dp[100][100];
int buf[100];
class QuickSort {
	public:
	double getEval(vector <int> L) 
	{
		for(int len=1;len<50;len++)
		for(int a=1;a<=50;a++)
		{
			int b=a+len;
			int top=0;
			for(int i=0;i<L.size();i++)
				if(L[i]>=a&&L[i]<=b)buf[top++]=L[i];
			dp[a][b]=0;
			if(top==0)continue;
			for(int i=0;i<top;i++)
			{
				int ind=0;
				for(int j=0;j<i;j++)if(buf[j]>buf[i])ind++;
				for(int j=i+1;j<top;j++)if(buf[j]<buf[i])ind++;
				dp[a][b]+=(dp[a][buf[i]-1]+dp[buf[i]+1][b]+ind);
			}
			dp[a][b]/=top;
		}
		return dp[1][50];
	}
};
