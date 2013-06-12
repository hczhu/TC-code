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
namespace bipartiteMatch
{
const int N=100;
bool rset[N];
int rmatch[N];
bool augment(int v,const vector<vector<int> >& edge)
{
	for(int i=0;i<edge[v].size();i++)
	{
		int u=edge[v][i];
		if(rset[u])continue;
		rset[u]=true;
		if(rmatch[u]==-1||augment(rmatch[u],edge))
		{
			rmatch[u]=v;
			return true;
		}
	}
	return false;
}
int maxMatch(int n,int m,const vector<vector<int> >& edge)
{
	memset(rset,false,sizeof(bool)*m);
	memset(rmatch,0xff,sizeof(int)*m);
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(!augment(i,edge))continue;
		res++;
		memset(rset,false,sizeof(bool)*m);
	}
	return res;
}
};
int have[100];

class PeopleYouMayKnow {
//Review your code before submission!!!!
	public:
	int maximalScore(vector <string> friends, int aa, int bb) 
	{
		vector<int> fa,fb;
		for(int i=0;i<friends[aa].length();i++)
		{
			if('Y'==friends[aa][i])fa.push_back(i),have[i]++;
			if('Y'==friends[bb][i])fb.push_back(i),have[i]++;
		}
		debug(fa.size());debug(fb.size());
		int res=0;
		
		vector<int> tmp;
		tmp=fa;fa.clear();
		for(int i=0;i<tmp.size();i++)
		{
			if(have[tmp[i]]==2)
			{
				res++;
				cerr<<"common "<<tmp[i]<<endl;
			}
			else fa.push_back(tmp[i]);
		}
		tmp=fb;fb.clear();
		for(int i=0;i<tmp.size();i++)if(have[tmp[i]]==1)fb.push_back(tmp[i]);
		debug(res);


		debug(fa.size());debug(fb.size());
		for(int i=0;i<fa.size();i++)cerr<<fa[i]<<" ";cerr<<endl;
		for(int i=0;i<fb.size();i++)cerr<<fb[i]<<" ";cerr<<endl;
		const int n=fa.size();
		const int m=fb.size();
		vector<vector<int> > edge(n);
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if('Y'==friends[fa[i]][fb[j]])edge[i].push_back(j);
		res+=bipartiteMatch::maxMatch(n,m,edge);
		debug(res);
		return res;
	}
};
