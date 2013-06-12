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
typedef long long int llint;
const int N=3000000;
const llint mod=1000000007;
int prime[N],fact[N];
class GuessTheNumberGame {
	public:
	 int possibleClues(int n) {
		 debug("Start calculation.");
     int top=primeSieve(fact,prime,n);
     llint ans=1;
     Rep(i,top) {
       int t=0;
       for(int m=n;m;m/=prime[i],t++);
       //debug(prime[i]);
       //debug(t);
       ans*=t;
       ans%=mod;
     }
     return ans;
	}
};
