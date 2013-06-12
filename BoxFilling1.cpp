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
// X is the dimension which is first filled
llint get2D(llint X,llint Y,llint x,llint y)
{
	llint d=min(x,y);
	llint res=(d-1)*(X+Y-d+1);
	debug(res);
	if(y==d)res+=x-d+1;
	else res+=X-d+1+y-d;
	debug(res);
	cerr<<"get2D "<<X<<" "<<Y<<" in "<<x<<" "<<y<<"="<<res<<endl;
	return res;
}
llint solve(llint X,llint Y,llint Z,llint x,llint y,llint z)
{
	llint d=min(x,min(y,z));
	llint res=0;

	if(X==1)return get2D(Y,Z,y,z);
	if(Y==1)return get2D(X,Z,x,z);
	if(Z==1)return get2D(X,Y,x,y);


	res+=X*Y+Y*Z+Z*X;res*=(d-1);
	res-=(d-2)*(d-1)*(X+Y+Z);
	res+=(d-2)*(d-1)*(2*d-3)/2;
	res-=(d-1)*(X+Y+Z);
	res+=(d-2)*(d-1)/2*3;
	res+=d-1;
	debug(res);
//	llint begin=0;
//	for(llint t=0;t<d-1;t++)
//		begin+=(X-t)*(Y-t)+(Y-t)*(Z-t)+(Z-t)*(X-t)-(X-t)-(Y-t)-(Z-t)+1;
//	debug(begin);
	if(d==z)
	{
		X-=d-1;Y-=d-1;Z-=d-1;x-=d-1;y-=d-1;z-=d-1;
		res+=get2D(X,Y,x,y);
	}
	else if(d==y)
	{
		X-=d-1;Y-=d-1;Z-=d-1;x-=d-1;y-=d-1;z-=d-1;
		res+=X*Y;Z--;z--;
		res+=get2D(X,Z,x,z);
	}
	else
	{
		X-=d-1;Y-=d-1;Z-=d-1;x-=d-1;y-=d-1;z-=d-1;
		res+=X*Y;Z--;z--;
		res+=Z*X;Y--;y--;
		res+=get2D(Y,Z,y,z);
	}
	return res;
}
class BoxFilling {
	public:
	long long getNumber(int X, int Y, int Z, int x, int y, int z) 
	{
//		debug(get2D(3,5,3,4));
//		debug(get2D(5,3,4,3));
//		debug(get2D(5,5,3,4));
		return solve(X,Y,Z,x,y,z);
	}
};

int main()
{
	BoxFilling bb;
	cout<<bb.getNumber(2,2,5,1,2,3)<<endl;
	return 0;
}

// Powered by FileEdit
