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

int dp[1<<20],next[1<<20];
#define two(x)  ((1)<<(x))

class TheMoviesLevelTwoDivOne {
//Review your code before submission!!!!
	public:
	vector <int> find(vector <int> length, vector <int> scary) 
	{
/*		
		length.resize(20);
		scary.resize(20);
		for(int i=0;i<20;i++)
		{
			length[i]=2+(rand()%100);
			scary[i]=1+(rand()%(length[i]-1));
		}
		for(int i=0;i<20;i++)cerr<<length[i]<<",";cerr<<endl;
		for(int i=0;i<20;i++)cerr<<scary[i]<<",";cerr<<endl;*/
		const int n=length.size();
		for(int mk=two(n)-1;mk>=0;mk--)
		{
			dp[mk]=-100000;
			next[mk]=-1000;
			int sum=74;
			for(int i=0;i<n;i++)
				if(mk&two(i))sum+=47-length[i];
			if(sum<0)continue;
			dp[mk]=0;
			for(int i=0;i<n;i++)
			{
				if(mk&two(i))continue;
				if(sum<scary[i])continue;
				if(sum+47<length[i])continue;
			//	cerr<<mk<<"--->"<<i<<endl;
				if(1+dp[mk^two(i)]>dp[mk])
				{
					dp[mk]=1+dp[mk^two(i)];
					next[mk]=i;
				}
			}
		//	cerr<<mk<<"="<<dp[mk]<<" "<<next[mk]<<endl;
		}
		vector<int> res;
		int mk=0;
		while(dp[mk]>0)
		{
			assert(next[mk]>=0);
			res.push_back(next[mk]);
			mk^=two(next[mk]);
		}
		assert(res.size()==dp[0]);
		debug(mk);
		while(res.size()<n)
		{
			for(int i=0;i<n;i++)
			{
				if(0==(mk&two(i)))
				{
					res.push_back(i);
					mk^=two(i);
					break;
				}
			}
		}
		assert(res.size()==n);
		debug(dp[0]);
		return res;
	}
};
/*
int main()
{
	TheMoviesLevelTwoDivOne the;
	vector<int>  a,b;
	vector<int> c=the.find(a,b);
	for(int i=0;i<c.size();i++)cerr<<c[i]<<" ";cerr<<endl;
	return 0;
}
*/

