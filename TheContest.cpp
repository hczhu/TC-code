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



const int N=100;


int rmatch[N];
bool rset[N];
bool adj[N][N];
bool rused[N];

bool agument(int v,int n)
{
	for(int i=0;i<n;i++)
	{
		if(adj[v][i]&&!rset[i]&&!rused[i])
		{
			rset[i]=true;
			if(rmatch[i]==-1||agument(rmatch[i],n))
			{
				rmatch[i]=v;
				return true;
			}
		}
	}
	return false;
}


int check(const vector<int>& must,const vector<int>& rem,int n)
{
	memset(rmatch,0xff,sizeof(int)*n);
	int res=0;
	for(int i=0;i<must.size();i++)
	{
		memset(rset,false,sizeof(bool)*n);
		if(!agument(must[i],n))return -1;
		res++;
	}
	for(int i=0;i<rem.size();i++)
	{
		memset(rset,false,sizeof(bool)*n);
		if(agument(rem[i],n))res++;
	}
	return res;
}

char get_char(int order)
{
	order++;
	if(order<10)return '0'+order;
	if(order<10+26)return 'A'+order-10;
	return order-10-26+'a';
}

class TheContest {
//Review your code before submission!!!!
	public:
	vector <string> getSchedule(int X, int Y) 
	{
		//Bipartite graph positon(1,2,...,Y) number(1,2,...,n)
		//Note that the edge-chromatic number of a bipartite graph equals to the maximum degree
		const int n=max(X,Y);
		//adj[i][j]=true number i can be in position j

		for(int i=0;i<n;i++)for(int j=0;j<Y;j++)adj[i][j]=true;

		vector<string> res;
		vector<int> number_degree(n,Y);

		for(int round=0;round<X;round++)
		{
			debug(round);
			string ans(Y,'0');
			vector<bool> number_used(n,false);
			memset(rused,false,sizeof(bool)*Y);
			for(int i=0;i<Y;i++)
			{
				bool ok=false;
				rused[i]=true;
				for(int j=0;j<n;j++)
				{
					if(number_used[j]||!adj[j][i])continue;
					number_used[j]=true;
					vector<int> must,rem;
					for(int k=0;k<n;k++)
					{
						if(number_used[k])continue;
						assert(number_degree[k]<=n-round);
						if(number_degree[k]==n-round)must.push_back(k);
						else rem.push_back(k);
					}
				//	debug(must.size());
				//	debug(rem.size());
					if(Y-i-1==check(must,rem,Y))
					{
						ok=true;
						ans[i]=get_char(j);
						adj[j][i]=false;
						number_degree[j]--;
						break;
					}
					number_used[j]=false;
				}
				assert(ok);
			}
			cerr<<ans<<endl;
			res.push_back(ans);
		}
		return res;
	}
};
/*
int main()
{
	int X,Y;
	cin>>X>>Y;
	TheContest the;
	the.getSchedule(X,Y);
	return 0;
}
*/
