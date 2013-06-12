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
#define NDEBUG
#include <cassert>
#include <limits>
#include <cstdarg>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define hline() cerr<<"-----------------------------------------"<<endl;
const int mod=500500573;
int bino[2501][2501];
template<typename T,int N>
void init_bino(T com[N][N],bool take_mod=false,long long int mod=1000000000000000000LL)
{
	if(take_mod)
	{
		assert(mod>0);
		com[0][0]=1%mod;
		for(int i=1;i<N;i++)
		{
			com[i][0]=com[i][i]=1%mod;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
		}
	}
	else
	{
		com[0][0]=1;
		for(int i=1;i<N;i++)
		{
			com[i][0]=com[i][i]=1;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j]);
		}
	}
}

typedef long long int llint;


void generateInverse(llint p,llint inv[],llint n) {
	inv[1]=1;
	n=min(n,p-1);
	for(llint i=2;i<=n;i++) {
		inv[i]=(p-(inv[p%i]*(p/i)%p))%p;
	}
}
llint rev[2501];
class ProductAndSum {
	public:
	int getSum(int p2, int p3, int p5, int p7, int S) {
		for(int t=2;t*t<=mod;t++)assert(mod%t);
		if(0>(S-=5*p5+7*p7))return 0;
		generateInverse(mod,rev,2500);
		init_bino(bino,true,mod);
		const int x5=p5,x7=p7;
		llint ten[2501];
		ten[0]=1;
		for(int i=1;i<=2500;i++) {
			ten[i]=((llint)ten[i-1]*(llint)10)%mod;
		}
		for(int i=1;i<=2500;i++){
			ten[i]+=ten[i-1];
			ten[i]%=mod;
		}
		llint ans=0;
		int enumer=0;
		for(int x9=0;2*x9<=p3&&x9*9<=S;x9++)
		for(int x8=0;3*x8<=p2&&x8*8+9*x9<=S;x8++)
		for(int x6=0;x6+3*x8<=p2&&x6+2*x9<=p3&&x8*8+x9*9+x6*6<=S;x6++)
		for(int x4=0;2*x4+x6+3*x8<=p2&&4*x4+6*x6+8*x8+9*x9<=S;x4++) {
			int x2=p2-3*x8-x6-2*x4;
			int x3=p3-x6-2*x9;
			int x1=S-9*x9-8*x8-6*x6-4*x4-3*x3-2*x2;
			if(x1<0)continue;
			assert(x1>=0);
			assert(x2>=0);
			assert(x3>=0);
			int xx[]={0,x1,x2,x3,x4,x5,x6,x7,x8,x9};
			const int s=accumulate(xx+1,xx+10,0);
			llint comb=1;
			assert(s<=2500);
			for(int ss=s,j=1;j<10;j++) {
				comb*=(llint)bino[ss][xx[j]];
				comb%=mod;
				ss-=xx[j];
			}
			comb*=rev[s];
			comb%=mod;
			llint col_sum=0;
			for(int i=1;i<=9;i++) {
				col_sum+=comb*xx[i]*i;
			}
			col_sum%=mod;
//			cerr<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<" "<<x6<<" "<<x7<<" "<<x8<<" "<<x9<<endl;
//			debug(col_sum);
			assert(s<=2500&&s>=1);
			ans+=col_sum*ten[s-1];
//			debug(s-1);
//			debug(ten[s-1]);
			ans%=mod;
			enumer++;
		}
		debug(enumer);
		return ans;
	}
};
/*
int main() {
	ProductAndSum pp;
	debug(pp.getSum(2,0,0,0,4));
	debug(pp.getSum(0,0,0,0,10));
	debug(pp.getSum(2,0,0,0,5));
	debug(pp.getSum(1,1,1,1,10));
	debug(pp.getSum(5,5,5,5,100));
	debug(pp.getSum(100,100,100,100,2500));
	debug(pp.getSum(3,2,0,0,12));
	return 0;
}
*/
