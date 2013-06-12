
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
const llint inf=2000000000000000000LL;
llint getLower(llint n)
{
	llint res=sqrt(1.0*n);if(res)res--;
	while((res+1)*(res+1)<n)res++;
	res*=res;
	return res;
}
llint getUpper(llint n)
{
	llint res=sqrt(1.0*n);
	while(res*res<=n)res++;
	res*=res;
	return res;
}
llint getPower(llint n,int m,llint up)
{
	llint re=1;
	while(m&&re<=up/n)re*=n,m--;
	if(m)return up+1;
	return re;
}
class PerfectPowers {
	public:
	long long nearestCouple(long long lower, long long upper) 
	{
		vector<llint> all;
		for(int m=3;m<63&&(1<<m)<=upper;m+=2)
		{
			llint b;
			for(b=2;getPower(b,m,upper)<lower;b++);
			debug(b);
			llint t;
			while((t=getPower(b,m,upper))<=upper)
				all.push_back(t),b++;
			debug(all.size());
		}
		debug(all.size());
		sort(all.begin(),all.end());
		llint res=inf;
		for(int i=1;i<all.size();i++)
			if(all[i]!=all[i-1])res=min(res,all[i]-all[i-1]);
		debug(res);
		llint s1=getUpper(lower-1);
		llint s2=getUpper(s1);
		debug(s1);
		debug(s2);
		if(s1<=upper&&s2<=upper&&s1!=s2)res=min(res,s2-s1);
		debug(res);
		for(int i=0;i<all.size();i++)
		{
			llint pre=getLower(all[i]);
			if(pre>=lower)res=min(res,all[i]-pre);
			llint next=getUpper(all[i]);
			if(next<=upper)res=min(res,next-all[i]);
		}
		return res>=inf?-1:res;
	}
};
