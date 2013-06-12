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

double prob[4][5001];
void update(double pre[],double next[],int n,int d)
{
	// a --> b if  a+d>=b&&a<b || 2*n-a-b<=d a+b>=2*n-d
	const double rd=1.0/d;
	double psum=0.0;
	for(int a=1;a<=n;a++)
	{
		next[a]=psum*rd;
		psum+=pre[a];
		if(a>d)psum-=pre[a-d];
	}
	psum=0.0;
	int b=2*n-d;
	for(int a=n-d+1;a<n;a++)
	{
		psum+=pre[b-a];
		next[a]+=psum*rd;
	}
}
class BouncingDiceGame {
//Review your code before submission!!!!
	public:
	double winProbability(int n, int d, int x, int y) 
	{
		double *pre1=prob[0],*next1=prob[1];
		double *pre2=prob[2],*next2=prob[3];
		pre1[x]=1.0;pre2[y]=1.0;
		double ans=0.0;
		double ysum=0.0,xsum=0.0;
		for(int step=1;step<=n;step++)
		{
			update(pre1,next1,n,d);
			update(pre2,next2,n,d);
			ans+=next1[n]*(1.0-ysum);
			ysum+=next2[n];
			xsum+=next1[n];
			swap(pre1,next1);
			swap(pre2,next2);
//			for(int i=1;i<=n;i++)cerr<<pre1[i]<<" ";cerr<<endl;
//			for(int i=1;i<=n;i++)cerr<<pre2[i]<<" ";cerr<<endl;
			pre1[n]=pre2[n]=0.0;
//			hline();
//			debug(step);
		}
		debug(ans);
		debug(xsum);
		debug(ysum);
		//add=1/d+(1-1/d)*(1-1/d)*add
		// add*d*d= d+ (d-1)*(d-1)*add
		// add= d/(2*d-1)
		double add=1.0*d/(2.0*d-1);
		debug(add);
		debug((1-xsum)*(1-ysum));
		ans+=(1.0-xsum)*(1.0-ysum)*add;
		return ans;
	}
};

/*
int main()
{
	BouncingDiceGame bb;
	int n,d,x,y;
	cin>>n>>d>>x>>y;
	printf("%.10lf\n",bb.winProbability(n,d,x,y));
	return 0;
}
*/




// Powered by FileEdit
