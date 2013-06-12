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
#include <cassert>
#include <limits>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
//#define SZ(vec) ((int)(vec).size())
/*********************************
 Tips
 * Binary search
 * Ternary search
 * Bitwise tricks
 * Bipartite matching
 * Graph algorithms
 * DP
 * Subset DP
 * Greedy algorithms
 * Network flow
 * Construct the solution directly
 * Be careful to the input constraints
 * Corner cases.
**********************************/
typedef long long int llint;
const llint mod=1000000007;
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
llint bino[101][101];
llint hh[101][101][101];
llint ff[101][101][101];
llint gg[101][101][101];
class CubeBuilding {
	public:
	 int getCount(int cR, int cG, int cB, int N) {
		 debug("Start calculation.");
     init_bino(bino,true,mod);
     const int A=26;
     const int B=51;
     hh[0][0][0]=1;
     for(int n=1;n<=N;n++)
     for(int a=0;a<=A;a++)
     for(int b=0;b<=B;b++) {
       for(int i=a+b;i<=n;i++)
         hh[n][a][b]+=bino[i-1][a-1]*bino[i-a][b]%mod;
       hh[n][a][b]%=mod;
     }
     for(int n=1;n<=N;n++) {
       ff[n][0][0]=1;
       for(int b=1;b<=B;b++)ff[n][0][b]=0;
       for(int a=1;a<=A;a++)
       for(int b=0;b<=B;b++) {
         llint& res=ff[n][a][b];
         for(int x=1;x<=a;x++)
         for(int y=0;y<=b;y++)
           res+=hh[n][x][y]*ff[x+y][a-x][b-y]%mod;
         res%=mod;
       }
     }
     gg[0][0][0]=1;
     for(int n=1;n<=N;n++) {
       gg[n][0][0]=1;
       for(int a=1;a<=A;a++)
       for(int b=0;b<=B;b++) {
         llint& res=gg[n][a][b];
         //res=gg[n-1][a][b];
         for(int x=0;x<=a;x++)
         for(int y=0;y<=b;y++) {
           res+=gg[n-1][a-x][b-y]*ff[N][x][y]%mod;
         }
         res%=mod;
       }
     }
     return (gg[N][cR][cG+cB]*bino[cG+cB][cG]+gg[N][cG][cR+cB]*bino[cR+cB][cR]
         +bino[cR+cG][cG]*gg[N][cB][cR+cG])%mod;
	}
};
/*
int main() {
  int a,b,c,n;
  CubeBuilding cube;
  cin>>a>>b>>c>>n;
  cout<<cube.getCount(a,b,c,n)<<endl;
  return 0;
}
*/
