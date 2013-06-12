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
#define two(x)  ((1LL)<<(x))
string getPosition(int n,llint k)
{
	debug(n);
	debug(k);
	assert(k>=0&&k<two(n));
	if(n==1)return k==0?"0":"1";
	string res;
	if((two(n-1))>k)
	{
		res="0"+getPosition(n-1,k);
	}
	else
	{
		llint kk=k-two(n-1);
		if(kk==0)res="1"+getPosition(n-1,two(n-1)-1);
		else res="1"+getPosition(n-1,kk-1);
	}
	cerr<<"position "<<n<<" "<<k<<"="<<res<<endl;
	return res;

}
string solve(int n,llint k)
{
	debug(n);
	debug(k);
	assert(k>=0&&k<two(n));
	if(n==1)return k==0?"0":"1";
	string res;
	if((two(n-1))>k)
	{
		res="0"+solve(n-1,k);
	}
	else
	{
		llint kk=k-two(n-1);
		if(kk==0)res="1"+getPosition(n-1,two(n-1)-1);
		else res="1"+max(solve(n-1,kk-1),getPosition(n-1,two(n-1)-1));
	}
	cerr<<"solve "<<n<<" "<<k<<"="<<res<<endl;
	return res;
}
class TheLockDivOne {
	public:
	string password(int n, long long k) 
	{
		return solve(n,k-1);
	}
};
/*
int main()
{
	int n;
	llint k;
	TheLockDivOne lock;
	while(cin>>n>>k)
		cout<<lock.password(n,k)<<endl;
	return 0;
}
*/
