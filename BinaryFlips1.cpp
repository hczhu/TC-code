
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
llint rev[200000];
//kx>=b
llint mygreater(llint k,llint b)
{
	assert(k>0);
	if(b>=0)return (b+k-1)/k;
	return b/k;
}
//kx<=b
llint mysmaller(llint k,llint b)
{
	assert(k>0);
	if(b>=0)return b/k;
	return (b-k+1)/k;
}
template<class T>
T __gcd(T a,T b,T& x,T& y)
{
	T r,g;
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	r=a%b;
	g=__gcd(b,r,x,y);
	r=x;x=y;y=r-a/b*y;
	return g;
}
bool check(llint A,llint B,llint a,llint b,llint K)
{
	if(0==(a&1)||1==(b&1))return false;
	if((a*A+b*B)%K)return false;
	if(a>b&&A<K&&(a-b)*A>=K)return false;
	if(b>a&&B<K&&(b-a)*B>=K)return false;
	return true;
}
llint solve(llint A,llint B,llint K)
{
	const llint inf=100000000000000LL;
	llint x,y;
	llint g=__gcd(A,B,x,y);
	for(llint res=1;res<=A+B;res++)
	{
		res=174;
		if(res*K%g)continue;
		llint xx=x*(res*K/g);
		llint yy=y*(res*K/g);
		//a>=bb
		{
			llint low=max(mygreater(B/g,-xx),mygreater(A/g,-yy));
			low=max(low,mygreater(A/g+B/g,yy-xx));
			llint up=inf;
			if(A<K)up=mysmaller(A*(A/g+B/g),K-1-A*(xx-yy));
			debug(low);debug(up);
			if(low<=up&&check(A,B,xx+B/g*low,yy-A/g*low,K))return res;
			low++;if(low<=up&&check(A,B,xx+B/g*low,yy-A/g*low,K))return res;
		}
		// a<=b
		{
			llint low=max(mygreater(B/g,-xx),mygreater(A/g,-yy));
			llint up=mysmaller(A/g+B/g,yy-xx);
			if(B<K)low=max(low,mygreater(B*(A/g+B/g),B*(yy-xx)-K+1));
			debug(low);debug(up);
			if(low<=up&&check(A,B,xx+B/g*low,yy-A/g*low,K))return res;
			low++;if(low<=up&&check(A,B,xx+B/g*low,yy-A/g*low,K))return res;
		}
		break;
	}
	return -1;
}

class BinaryFlips {
	public:
	int minimalMoves(int A, int B, int K) 
	{
		if(A==0)return 0;
		if(A+B<K)return -1;
		if(B==0)return A/__gcd(A,K);
		return solve(A,B,K);
	}
};
int main()
{
	int A,B,K;
	BinaryFlips bb;
	while(cin>>A>>B>>K)
		cout<<bb.minimalMoves(A,B,K)<<endl;
	return 0;
}
