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
//Linear priem numbers sieve. The array factor[] store a prime factor of a composite number.
int primeSieve(bool factor[],int prime[],int n)
{
	int top=0;
	memset(factor,false,sizeof(bool)*(n+1));
	for(int i=2;i<=n;i++)
	{
		if(!factor[i])prime[top++]=i;
		for(int j=0;j<top&&prime[j]*i<=n;j++)
		{
			factor[prime[j]*i]=true;
			if(0==(i%prime[j]))break;
		}
	}
	return top;
}
bool factor[10000001];
int prime[1000000],len[1000000];
class PrimeSequences {
	public:
	int getLargestGenerator(int n, int d) 
	{
		int top=primeSieve(factor,prime,10000000);
		debug(top);
		int ret=-1;
		for(int i=0,j=0;i<top&&prime[i]<=n;i++)
		{
			int next=prime[i]>>1;
			while(j<top&&prime[j]<next)j++;
			len[i]=1;
			if(j<top&&prime[j]==next)len[i]=len[j]+1;
			if(len[i]>=d)ret=prime[i];
		}
		return ret;
	}
};

