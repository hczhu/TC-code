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

const int N=100;
typedef long long int llint;
const llint inf=100000000000000000LL;
llint value[N][N];
bool con[N][N];
llint ksum[N][N],tmp[N][N];
namespace Matrix
{
	llint tmp[N][N],table[N][N];
	void mult(llint a[N][N],llint b[N][N],llint c[N][N],int n)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			c[i][j]=-inf;
			for(int k=0;k<n;k++)c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
		}
	}
	void identical(llint ans[N][N],int n)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans[i][j]=-inf;
		for(int i=0;i<n;i++)ans[i][i]=0;
	}
	void matrixPower(llint base[N][N],int n,llint m,llint ans[N][N])
	{
		identical(ans,n);
		memcpy(table,base,sizeof(llint)*n*N);
		while(m>0)
		{
			if((m&1)==1)
			{
				mult(ans,table,tmp,n);
				memcpy(ans,tmp,sizeof(llint)*n*N);
			}
			m>>=1;
			mult(table,table,tmp,n);
			memcpy(table,tmp,sizeof(llint)*n*N);
		}
	}

	llint power[N][N];
	//Calculate Sum{base^0+base^1+base^2+...+base^m}
	// N>=2*n must be satisfied 
	void matrixPowerSum(llint base[][N],int n,llint m,llint ans[][N])
	{
		for(int i=0;i<n;i++)
		{
			for(int j=n;j<2*n;j++)
				base[i][j]=-inf;
			base[i][i+n]=0;
		}
		for(int i=n;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
				base[i][j]=-inf;
			base[i][i]=0;
		}
		matrixPower(base,2*n,m,ans);
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans[i][j]=max(ans[i][j],ans[i][j+n]);
	}
};
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
llint ans[N][N];
class AntOnGraph {
//Review your code before submission!!!!
	public:
	string maximumBonus(vector <string> p0, vector <string> p1, vector <string> p2, int sp, int up) 
	{
		debug(-inf*50);
		const int n=p0.size();
		for(int i=0;i<n;i++,cerr<<endl)
		for(int j=0;j<n;j++)
		{
			int v=(p0[i][j]-'0')*100+(p1[i][j]-'0')*10+p2[i][j]-'0';
			value[i][j]=v-500;
			con[i][j]=v>0;
			cerr<<value[i][j]<<" ";
			if(!con[i][j])value[i][j]=-inf;
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)ksum[i][j]=value[i][j];

	/*	for(int i=2;i<=sp;i++)
		{
			Matrix::mult(ksum,value,tmp,n);
			memcpy(ksum,tmp,sizeof(tmp));
		}*/
		Matrix::matrixPower(value,n,sp,ksum);
		hline();
		for(int i=0;i<n;i++,cerr<<endl)
		for(int j=0;j<n;j++)cerr<<ksum[i][j]<<" ";
		Matrix::matrixPowerSum(ksum,n,up-1,ans);
		hline();
		for(int i=0;i<n;i++,cerr<<endl)
		for(int j=0;j<n;j++)cerr<<ans[i][j]<<" ";
		Matrix::mult(ans,ksum,tmp,n);
		memcpy(ans,tmp,sizeof(ans));
		hline();
		for(int i=0;i<n;i++,cerr<<endl)
		for(int j=0;j<n;j++)cerr<<ans[i][j]<<" ";
		const llint max_answer=(llint)up*sp*499;
		debug(max_answer);
		debug(ans[0][1]);
		if(ans[0][1]>max_answer||ans[0][1]<-max_answer)return "IMPOSSIBLE";
		return convert(ans[0][1]);	
	}
};
