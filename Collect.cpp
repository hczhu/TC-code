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
const int N=11;
int toss[11][3100],ttop[11];
int dice[11][3100][6];
double tprob[11][3100];
inline int encode(int a,int b,int c,int d,int e,int f)
{
	int re=a;
	re+=(re<<3)+(re<<1);
	re+=b;
	re+=(re<<3)+(re<<1);
	re+=c;
	re+=(re<<3)+(re<<1);
	re+=d;
	re+=(re<<3)+(re<<1);
	re+=e;
	re+=(re<<3)+(re<<1);
	re+=f;
	return re;
}
int score(int a,int b,int c,int d,int e,int f)
{
	int re=a;
	//re>?=2*b;
	re=max(re,2*b);
	re=max(re,3*c);
	re=max(re,4*d);
	re=max(re,5*e);
	re=max(re,6*f);
	return re;
}
double dp[2][N*N*N*N*N*N];
double buf[N*N*N*N*N*N];
int com[11][11];
int hash[1<<6];
int ccode[6];
#define two(x)  ((1)<<(x))
#define low(x) (((x)^((x)-1))&(x))
class Collect {
	public:
	double expected(int n, int k) 
	{
		ccode[0]=encode(1,0,0,0,0,0);
		ccode[1]=encode(0,1,0,0,0,0);
		ccode[2]=encode(0,0,1,0,0,0);
		ccode[3]=encode(0,0,0,1,0,0);
		ccode[4]=encode(0,0,0,0,1,0);
		ccode[5]=encode(0,0,0,0,0,1);

		for(int i=0;i<6;i++)hash[two(i)]=i;
		com[0][0]=1;
		for(int i=1;i<=11;i++)
		{
			com[i][0]=com[i][i]=1;
			for(int j=1;j<i;j++)
				com[i][j]=com[i-1][j]+com[i-1][j-1];
		}
		for(int s=0;s<=10;s++)
		for(int a=0;a<=s;a++)
		for(int b=s-a;b>=0;b--)
		for(int c=s-a-b;c>=0;c--)
		for(int d=s-a-b-c;d>=0;d--)
		for(int e=s-a-b-c-d;e>=0;e--)
		{
			int f=s-a-b-c-d-e;
			tprob[s][ttop[s]]=pow(1./6,a)*com[s][a]*pow(1.0/6,b)*com[s-a][b]*
				pow(1.0/6,c)*com[s-a-b][c]*
				pow(1.0/6,d)*com[s-a-b-c][d]*
				pow(1.0/6,e)*com[s-a-b-c-d][e]*
				pow(1.0/6,f);
			dice[s][ttop[s]][0]=a;
			dice[s][ttop[s]][1]=b;
			dice[s][ttop[s]][2]=c;
			dice[s][ttop[s]][3]=d;
			dice[s][ttop[s]][4]=e;
			dice[s][ttop[s]][5]=f;
			toss[s][ttop[s]++]=(encode(a,b,c,d,e,f));
		}
		for(int i=0;i<=10;i++)debug(ttop[i]);
		double *pre=dp[0],*next=dp[1];
		
		for(int a=0;a<=n;a++)
		for(int b=n-a;b>=0;b--)
		for(int c=n-a-b;c>=0;c--)
		for(int d=n-a-b-c;d>=0;d--)
		for(int e=n-a-b-c-d;e>=0;e--)
		for(int f=n-a-b-c-d-e;f>=0;f--)
			pre[encode(a,b,c,d,e,f)]=score(a,b,c,d,e,f);

		while(k--)
		{
			for(int a=0;a<=n;a++)
			for(int b=n-a;b>=0;b--)
			for(int c=n-a-b;c>=0;c--)
			for(int d=n-a-b-c;d>=0;d--)
			for(int e=n-a-b-c-d;e>=0;e--)
			for(int f=n-a-b-c-d-e,code=encode(a,b,c,d,e,n-a-b-c-d-e);f>=0;f--,code--)
			{
				double& res=next[code];				
				int rem=n-a-b-c-d-e-f;
				res=0.0;
				buf[0]=pre[code];
				for(int i=0;i<=rem;i++)
				for(int j=0,j1=rem-i;j<=j1;j++)
				for(int k=0,k1=rem-i-j;k<=k1;k++)
				for(int x=0,x1=rem-i-j-k;x<=x1;x++)
				for(int y=0,y1=rem-i-j-k-x;y<=y1;y++)
				for(int z=0,z1=rem-i-j-k-x-y,roll=encode(i,j,k,x,y,0);z<=z1;z++,roll++)
				{
					double& tmp=buf[roll];
					tmp=max(buf[0],pre[code+roll]);
					if(i)tmp=max(tmp,buf[roll-ccode[0]]);
					if(j)tmp=max(tmp,buf[roll-ccode[1]]);
					if(k)tmp=max(tmp,buf[roll-ccode[2]]);
					if(x)tmp=max(tmp,buf[roll-ccode[3]]);
					if(y)tmp=max(tmp,buf[roll-ccode[4]]);
					if(z)tmp=max(tmp,buf[roll-ccode[5]]);
				}
				double *pp=tprob[rem];
				for(int i=ttop[rem]-1;i>=0;i--)
					res+=pp[i]*buf[toss[rem][i]];
			}
			swap(pre,next);
		}
		return pre[0];
	}
};

/*
int main()
{
	Collect cc;
	int n,k;
	cin>>n>>k;
	cout<<cc.expected(n,k)<<endl;
	return 0;
}

*/
