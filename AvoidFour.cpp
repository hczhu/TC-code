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
typedef long long int llint;
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
//Mtrix mult and power and number factor
const int N=20;
const llint mod=1000000007;
namespace Matrix
{
	llint tmp[N][N],table[N][N];
	void mult(llint a[N][N],llint b[N][N],llint c[N][N],int n,llint p)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			c[i][j]=0;
			for(int k=0;k<n;k++)
				c[i][j]+=a[i][k]*b[k][j]%p,c[i][j]%=p;
		}
	}
	
	void matrixPower(llint base[N][N],int n,llint m,llint ans[N][N],llint p)
	{
		memset(ans,0,sizeof(llint)*n*N);
		for(int i=0;i<n;i++)ans[i][i]=1;
		memcpy(table,base,sizeof(llint)*n*N);
		while(m>0)
		{
			if((m&1)==1)
			{
				mult(ans,table,tmp,n,p);
				memcpy(ans,tmp,sizeof(llint)*n*N);
			}
			m>>=1;
			mult(table,table,tmp,n,p);
			memcpy(table,tmp,sizeof(llint)*n*N);
		}
	}

	llint power[N][N];
	//Calculate Sum{base^0+base^1+base^2+...+base^m}
	// N>=2*n must be satisfied 
	void matrixPowerSum(llint base[][N],int n,llint m,llint ans[][N],llint p)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=n;j<2*n;j++)
				base[i][j]=0;
			base[i][i+n]=1;
		}
		for(int i=n;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
				base[i][j]=0;
			base[i][i]=1;
		}
		matrixPower(base,2*n,m,ans,p);
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans[i][j]+=ans[i][j+n],ans[i][j]%=p;
	}
};


llint base[][N]=
{
	{1,1,1,1,1},
	{8,8,8,8,8},
	{1,1,0,0,0},
	{0,0,1,0,0},
	{0,0,0,1,0}
};
llint ans[N][N],ans1[N][N],ans2[N][N];
const int D=5;
llint getSub(llint ff,llint n)
{
	Matrix::matrixPower(base,D,ff,ans,mod);

	Matrix::matrixPowerSum(ans,D,n/ff,ans1,mod);
		
	for(int i=0;i<D;i++)
		ans1[i][i]=(ans1[i][i]+mod-1)%mod;

	llint sub=ans1[1][0]+ans1[2][0]+ans1[3][0]+ans1[4][0];
	return sub%mod;
}
llint lcm(vector<llint> num,llint up)
{
	llint res=1;
	for(int i=0;i<num.size();i++)
	{
		llint g=__gcd(num[i],res);
		if(res>up/(num[i]/g))return up+1;
		res*=num[i]/g;
	}
	return res;
}
#define two(x)  ((1)<<(x))
class AvoidFour {
	public:
	int count(long long n) 
	{
		Matrix::matrixPower(base,D,n,ans,mod);
		llint res=ans[0][0]+ans[1][0]+ans[2][0]+ans[3][0]+ans[4][0];
		res%=mod;
		res+=mod-1;
		res%=mod;
		debug(res);
		vector<llint> all;
		for(llint ff=44;ff<=n;ff=ff*10+4)
		{
			bool ok=true;
			for(llint d=44;d<ff;d=d*10+4)
				if(0==(ff%d))ok=false;
			if(ok)all.push_back(ff);
		}
		const int m=all.size();
		debug(m);
		for(int mk=1;mk<two(m);mk++)
		{
			vector<llint> sub;
			for(int i=0;i<m;i++)
				if(two(i)&mk)sub.push_back(all[i]);
			llint cycle=lcm(sub,n);
			debug(mk);
			debug(cycle);
			if(cycle>n)continue;
			llint t=getSub(cycle,n);
			if(sub.size()&1)res+=mod-t;
			else res+=t;
			res%=mod;
		}
		return res;
	}
};
/*
int main()
{
	AvoidFour aa;
	llint n;
	while(cin>>n)
		cout<<aa.count(n)<<endl;
	return 0;
}
*/
