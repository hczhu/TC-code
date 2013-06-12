
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
const int N=10*9;
typedef long long int llint;
const llint mod=600921647;
namespace Matrix
{
	llint tmp[N][N],table[N][N];
	void mult(llint a[N][N],llint b[N][N],llint c[N][N],int n,llint p)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==0)continue;
			for(int k=0;k<n;k++)
			{
				c[i][k]+=a[i][j]*b[j][k];
				if(c[i][k]>=p)c[i][k]%=p;
			}
		}
		/*
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]%=p;*/
		/*
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			c[i][j]=0;
			for(int k=0;k<n;k++)c[i][j]+=(a[i][k]*b[k][j]%p);
			c[i][j]%=p;
		}*/
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
			debug(m);
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
template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}
llint base[N][N],ans[N][N],tmp[N][N],tmp1[N][N];
llint vect[9*9];
const int L=9;
inline int index(int a,int b)
{
	return a*L+b;
}
llint getAnswer(int n,int len)
{
	llint res=0;
	const int B=n*L;
	Matrix::matrixPower(base,B,len,ans,mod);
	for(int ind=0;ind<n;ind++)
		res+=ans[index(ind,8)][B-1],res%=mod;
	cerr<<"len="<<len<<" res="<<res<<endl;
	return res;
}
class ShuffledPlaylist {
	public:
	int count(vector <string> songs, vector <string> trans, int lower, int upper)
	{
		vector<int> list=parse<int>(accumulate(songs.begin(),songs.end(),string(""))," ,");
		for(int i=0;i<trans.size();i++)
			trans[i]+="N";
		trans.push_back("");
		for(int i=0;i<trans.size();i++)
			trans.back()+="Y";

		const int n=trans.size();
		for(int i=0;i<list.size();i+=2)
		{
		//	cerr<<list[i]<<" "<<list[i+1]<<endl;
			int a=list[i],len=list[i+1];
			for(int b=0;b<n;b++)
			{
				if(trans[b][a]=='N')continue;
				base[index(a,L-1)][index(b,L-len)]++;
			}
		}
		const int B=L*n;
		debug(B);
		for(int i=0;i<n;i++)
		for(int j=0;j<L-1;j++)
			base[index(i,j)][index(i,j)+1]++;
		base[B-1][B-1]=1;
		llint res=getAnswer(n,lower-1);
		res=(mod-res)%mod;
		res+=getAnswer(n,upper);
		res%=mod;
		return res;
	}
};
