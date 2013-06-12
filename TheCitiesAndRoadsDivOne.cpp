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
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
typedef long long int llint;
const llint mod=1234567891LL;
const int N=20;
int hash[1<<N];
int edge[N];
int add[1<<N];
bool con[N][N];
int cuta[N],cutb[N];
int suba[N],subb[N];
bool used[N];
void DFS(int v,const vector<string>& grid,int n,int& mk)
{
	used[v]=true;
	mk^=two(v);
	for(int i=0;i<n;i++)
	{
		if(!used[i]&&grid[v][i]=='Y')
			DFS(i,grid,n,mk);
	}
}
vector<int> get_part(const vector<string>& grid)
{
	vector<int> res;
	memset(used,false,sizeof(used));
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			int mk=0;
			DFS(i,grid,grid.size(),mk);
			res.push_back(mk);
		}
	}
	return res;
}
class TheCitiesAndRoadsDivOne {
//Review your code before submission!!!!
	public:
	int find(vector <string> grid) {
		const int n=grid.size();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				if(grid[i][j]=='Y')edge[i]^=two(j);
		}

		for(int i=0;i<n;i++)hash[two(i)]=i;
		for(int mk=1;mk<two(n);mk++)
		{
			int ind=hash[low(mk)];
			int sub=mk^tow(ind);
			add[mk]=add[sub];
			for(int i=0;i<n;i++)
				if((two(i)&sub)&&grid[ind][i]=='N')add[mk]++;
		}
		int top=0;
		for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(grid[i][j]=='N')continue;
			grid[j][i]=grid[i][j]='N';
			vector<int> part=get_part(grid);
			grid[j][i]=grid[i][j]='Y';
			if(part.size()>1)
			{
				assert(part.size)
			}
		}
	}
};

