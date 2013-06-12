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
typedef long long llint;
const llint mod=1000000007;
llint ff[501][11],gg[501][11];
class PuyoPuyo {
	public:
	int theCount(int m, int n) {
			if(n%m)return 0;
			n/=m;
			ff[0][0]=gg[0][0]=1;
			for(int a=0;a<=n;a++)
			{
				for(int i=0;i<a;i++)
				{
					ff[a][0]+=4*ff[a-i-1][m-1]*gg[i][0]%mod;
					gg[a][0]+=3*gg[a-i-1][m-1]*gg[i][0]%mod;
				}
				ff[a][0]%=mod;
				gg[a][0]%=mod;
				cerr<<a<<" "<<0<<":"<<ff[a][0]<<" "<<gg[a][0]<<endl;
				ff[a][1]=ff[a][0];
				gg[a][1]=gg[a][0];
				for(int b=2;b<m;b++)
				{
					for(int i=0;i<=a;i++)
					{
						ff[a][b]+=ff[a-i][b-1]*gg[i][0]%mod;
						gg[a][b]+=gg[a-i][b-1]*gg[i][0]%mod;
					}
					ff[a][b]%=mod;
					gg[a][b]%=mod;
					cerr<<a<<" "<<b<<":"<<ff[a][b]<<" "<<gg[a][b]<<endl;
				}
			}
			return ff[n][0];
	}
};
