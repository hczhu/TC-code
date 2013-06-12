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
#define NDEBUG
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

typedef long long int llint;

int cc=0,go_max;
llint luck[1024*100];
const int N=2048;
int can[N][N],ctop[N];
int add[100][N],atop[100];
int next[100][N],ntop[100];
int merge(int a1[],int top1,int a2[],int top2,int a3[])
{
	int top=0;
	int x=0,y=0;
	while(x<top1&&y<top2)
	{
		if(a1[x]<a2[y])a3[top++]=a1[x++];
		else if(a1[x]>a2[y])a3[top++]=a2[y++];
		else a3[top++]=a1[x++],y++;
	}
	while(x<top1)a3[top++]=a1[x++];
	while(y<top2)a3[top++]=a2[y++];
	return top;
}

#define two(x)  ((1)<<(x))
void DFS(int pick,llint mul,llint low,llint high,llint& ans)
{
	assert(pick<100);
	if(pick&1)ans+=(high/mul)-(low-1)/mul;
	else ans-=high/mul-(low-1)/mul;
	ntop[pick+1]=0;
	for(int i=0;i<ntop[pick];i++)
	{
		int pos=next[pick][i];
		llint t=luck[pos]/__gcd(mul,luck[pos]);
		if(t<=high/mul)next[pick+1][ntop[pick+1]++]=pos;
	}
	for(int i=ntop[pick+1]-1;i>=0;i--)
	{
		int pos=next[pick+1][i];
		llint t=luck[pos]/__gcd(mul,luck[pos]);
		ntop[pick+1]--;
		DFS(pick+1,mul*t,low,high,ans);
	}
}
llint solve(llint low,llint high)
{
	int top=0;
	for(int len=1;len<=10;len++)
	{
		for(int mk=0;mk<two(len);mk++)
		{
			llint x=0;
			for(int i=0;i<len;i++)
				x*=10,x+=(mk&two(i))?7:4;
			luck[top++]=x;
			
			for(int j=0;j<top-1;j++)
			{
				if(0==(x%luck[j]))
				{
					top--;
					break;
				}
			}
		}
	}
	debug(top);
	sort(luck,luck+top);
	llint ans=high+1-low;
	for(int i=0;i<top;i++)next[0][ntop[0]++]=i;
	DFS(0,1,low,high,ans);
	return ans;
}
class TheAlmostLuckyNumbers {
//Review your code before submission!!!!
	public:
	long long count(long long a, long long b) {
		return solve(a,b);
	}
};

/*
int main()
{
	llint a,b;
	cin>>a>>b;
	cout<<solve(a,b)<<endl;
	return 0;
}
*/
