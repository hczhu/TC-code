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
llint get_next(llint pre,llint prod,llint add,llint mod)
{
	return (pre*prod+add)%mod;
}
llint ff[2][41],gg[2][41];
class RoadOrFlightHard {
//Review your code before submission!!!!
	public:
	long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst,
					int flightProd, int flightAdd, int flightMod, int K) 
	{
		llint *pre_f=ff[0],*next_f=ff[1];
		llint *pre_g=gg[0],*next_g=gg[1];
		llint walk=roadFirst%roadMod;
		llint flight=flightFirst%flightMod;
		for(int i=1;i<=N;i++)
		{
	//		debug(i);
	//		debug(walk);
	//		debug(flight);
			next_f[0]=pre_f[0]+walk;
			for(int k=1;k<=K;k++)
			{
				next_f[k]=min(pre_f[k],pre_g[k])+walk;
				next_g[k]=min(pre_f[k-1],pre_g[k])+flight;
			}
			walk=get_next(walk,roadProd,roadAdd,roadMod);
			flight=get_next(flight,flightProd,flightAdd,flightMod);
			swap(pre_f,next_f);
			swap(pre_g,next_g);
	//		for(int k=1;k<=K;k++)cerr<<pre_f[k]<<" ";cerr<<endl;
	//		for(int k=1;k<=K;k++)cerr<<pre_g[k]<<" ";cerr<<endl;
		}
		llint ans=pre_f[0];
		for(int i=1;i<=K;i++)
		{
			ans=min(ans,min(pre_f[i],pre_g[i]));
		}
		return ans;
	}
};

