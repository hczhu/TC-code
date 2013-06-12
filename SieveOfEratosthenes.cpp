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
//#define NDEBUG
#include <cassert>
#include <limits>
//INT_MAX INT_MIN
#include <limits.h>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
//Linear priem numbers sieve. The array factor[] store a prime factor of a composite number.
int primeSieve(int factor[],int prime[],int n)
{
	int top=0;
	memset(factor,0,sizeof(int)*(n+1));
  //make 1 not prime
  factor[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(0==factor[i])prime[top++]=i;
		for(int j=0;j<top&&prime[j]*i<=n;j++)
		{
			factor[prime[j]*i]=prime[j];
			if(0==(i%prime[j]))break;
		}
	}
	return top;
}
const int N=1000000;
int fact[N+1],prime[N];
class SieveOfEratosthenes {
	public:
	 int lastScratch(int maxNum) {
		 debug("Start calculation.");
     int n=sqrt(1.0*maxNum)+1;
     while(n*n>maxNum)n--;
     debug(n);
     int top=primeSieve(fact,prime,n);
     int maxPrime=prime[top-1];
     debug(maxPrime);
     primeSieve(fact,prime,maxNum/maxPrime);
     for(int i=maxNum/maxPrime;i>=maxPrime;i--) {
       if(fact[i]==0||fact[i]>=maxPrime) {
         return i*maxPrime;
       }
     }
     return 0;
	}
};
