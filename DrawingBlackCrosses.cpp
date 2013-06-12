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
#define two(x)  ((1)<<(x))
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
typedef long long int llint;
//*******************************************
const int mod=1000000007;
llint fact[21];
llint dp[20][256][256];
bool exist[20][256][256];
bool good[256][256];
int bit_cnt[256];
llint mult(llint a,llint b)
{
	return a*b%(llint)mod;
}
vector<string> rotate(vector<string> grid)
{
	const int n=grid.size();
	const int m=grid[0].length();
	vector<string> res(grid[0].length(),string(grid.size(),'.'));
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
		res[i][j]=grid[j][i];
	return res;
}
void move_black(vector<string>& grid)
{
	int top=0;
	for(int i=0;i<grid.size();i++)
	{
		bool ok=false;
		for(int j=0;j<grid[i].length()&&!ok;j++)
			ok=grid[i][j]=='B';
		if(ok)
		{
			swap(grid[top],grid[i]);
			top++;
		}
	}
}
int row[20];
llint DP(int r,int mr,int mc,int n,int m)
{
	const int bn=min(8,n);
	const int bm=min(8,m);
	mr&=two(bn)-1;
	if(r==n)return good[mr][mc]?fact[bit_cnt[mr]+n-bn]:0;
	assert(r<20);
	assert(mr<256);
	assert(mc<256);
	if(exist[r][mr][mc])return dp[r][mr][mc];
	llint& res=dp[r][mr][mc];
	res=0;
	exist[r][mr][mc]=true;
	for(int i=0;i<bm;i++)
	{
		if(row[r]&two(i))continue;
		if(mc&two(i))continue;
		res+=DP(r+1,mr^two(r),mc^two(i),n,m);
		res%=mod;
	}
	int cand=m-bm-(bit_cnt[mr]+max(r,bn)-bn-bit_cnt[mc]);
	assert(cand>=0);
	if(cand)
	{
		res+=mult(cand,DP(r+1,mr^two(r),mc,n,m));
		res%=mod;
	}
	if(r<bm)res+=DP(r+1,mr,mc,n,m),res%=mod;
#ifndef NDEBUG
	cerr<<r<<" "<<mr<<" "<<mc<<"="<<res<<endl;
#endif

	return res;
}
class DrawingBlackCrosses {
//Review your code before submission!!!!
	public:
	int count(vector <string> grid) 
	{
	/*	grid.clear();
		for(int i=0;i<20;i++)
		{
			grid.push_back(string(20,'.'));
		}*/


		move_black(grid);
		grid=rotate(grid);
		move_black(grid);
		int n=grid.size();
		int m=grid[0].length();
		if(n>m)
		{
			swap(n,m);
			grid=rotate(grid);
		}
		debug(n);
		debug(m);
		int bn=min(8,n);
		int bm=min(8,m);
		for(int i=0;i<n;i++,cerr<<endl)
			cerr<<grid[i]<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(grid[i][j]=='B')
				{
					row[i]^=two(j);
					if(i>=bn||j>=bm)*((int*)0)=0;
				}
			}
		}
		for(int i=0;i<two(8);i++)
		for(int j=0;j<8;j++)
			if(two(j)&i)bit_cnt[i]++;
		fact[0]=1;
		for(int i=1;i<=20;i++)fact[i]=mult(fact[i-1],i);
		for(int mr=0;mr<two(bn);mr++)
		for(int mc=0;mc<two(bm);mc++)
		{
			int take=bit_cnt[mr]+n-bn;
			if(take-bit_cnt[mc]<m-bm&&mr!=two(bn)-1)continue;
			bool& ok=good[mr][mc];
			ok=true;
			for(int i=0;ok&&i<bn;i++)
				ok=(mr&two(i))||(((row[i]|mc)&(two(bm)-1))==(two(bm)-1));
			if(ok)
			{
				hline();
				debug(mr);
				debug(mc);
			}
		}
		return DP(0,0,0,n,m);
	}
};



// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
