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
//*******************************************
typedef long long int llint;
llint aa[1000000],bb[1000000];

const llint mod=1000000007;

llint mult(llint a,llint b){a%=mod;b%=mod;return a*b%mod;}

llint mult(llint a,llint b,llint c){a%=mod,b%=mod,c%=mod;return ((a*b%mod)*c)%mod;}

// sum of a*start+(a+1)*(start+step)+...+b*(start+step*(b-a))

llint get_sum(llint a,llint b,llint start,llint step)
{
	if(a>b)return 0;
	llint res=mult(b-a+1,a,start);
	llint mm=(b-a+1)*(b-a)/2;
	res+=mult(a*step+start,mm);
	mm=(b-a)*(b-a+1)/2;
	llint mm1=(2*b-2*a+1);
	if(0==(mm%3))mm/=3;
	else if(0==(mm1%3))mm1/=3;
	else assert(0);
	res+=mult(mm,mm1,step);
	res%=mod;
	res+=mod;
	res%=mod;
	return res;
}
class MegaSum {
//Review your code before submission!!!!
	public:
	int calculate(long long n) {
		int top=0;
		llint pre=0;
		llint nr=-1,nc=-1;
		for(llint i=1;;i++)
		{
			llint x=pre+1;
			llint y=i*i;
			
			aa[top]=x;
			bb[top++]=y;
			pre=y;

			if(x<=n&&n<=y)
			{
				llint mid=(x+y)/2;
				if(n>=mid)nc=i-(n-mid),nr=i;
				else nr=n-x+1,nc=i;
				if(i&1)swap(nr,nc);
				cerr<<nr<<" "<<nc<<endl;
				break;
			}
		}
		debug(top);
		llint res=0;
		for(int i=0;i<top;i++)
		{
			llint rc=i+1;
			llint r=nr,c=nc;
			if(rc&1)swap(r,c);
			llint mid=(aa[i]+bb[i])/2;
			llint start,step,x,y;
			// aa[i]--->mid
			if(c>=rc)
			{
				x=aa[i];y=min(mid,aa[i]+r-1);
				step=-(c+1-rc);
				start=r*(-step);
				res+=get_sum(x,y,start,step);
				//cerr<<x<<" "<<y<<" "<<start<<" "<<step<<endl;
			}
			// mid+1--->bb[i]
			if(r>=rc)
			{
				y=bb[i];
				x=max(mid+1,bb[i]-c+1);
				step=r-rc+1;
				start=step*(c-(rc-(x-mid))+1);
				res+=get_sum(x,y,start,step);
				//cerr<<x<<" "<<y<<" "<<start<<" "<<step<<endl;
			}
			res%=mod;
			//cerr<<aa[i]<<" "<<bb[i]<<"="<<res<<endl;
		}
		return res;
	}
};
/*
int main()
{
	MegaSum gg;
	llint n;
	cin>>n;
	cout<<gg.calculate(n)<<endl;
	return 0;
}
*/


// Powered by FileEdit
