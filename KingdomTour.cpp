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
//Be carefull for cut into strings!!!!
template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}

int dp[211][211][2];
int tmp[211][211][2];
bool exist[211][211][2];
vector<int> edge[200];
int cost[200][200];
int n,m,len;
const int inf=100000000;
int DP(int v,int f)
{
	debug(v);
	vector<int> son;
	int sp=1;
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i]==f)continue;
		son.push_back(edge[v][i]);
		sp+=DP(son.back(),v);
	}
	for(int i=0;i<=2*m;i++)dp[v][i][0]=dp[v][i][1]=inf;
	const int deg=edge[v].size();
	if(son.empty())
	{
		dp[v][0][1]=0;
		dp[v][1][0]=0;
		return 1;
	}
	dp[v][0][deg&1]=0;
	dp[v][1][1^(deg&1)]=0;
	for(int i=0;i<son.size();i++)
	{
		int u=son[i];
		for(int k=sp;k>=0;k--)
		for(int x=0;x<2;x++)
		{
			tmp[v][k][x]=inf;
			int& res=tmp[v][k][x];
			for(int s=0;s<=k;s++)
			for(int y=0;y<2;y++)
			{
				res=min(res,dp[v][k-s][x^y]+dp[u][s][y]+(y?cost[v][u]:0));
			}
		}
		for(int k=sp;k>=0;k--)
		for(int x=0;x<2;x++)dp[v][k][x]=tmp[v][k][x];

	}
	debug(v);
	debug(sp);
	for(int i=0;i<=sp;i++)cerr<<dp[v][i][0]<<","<<dp[v][i][1]<<" ";cerr<<endl;
	return sp;
}
class KingdomTour {
	public:
	int minTime(int n, vector <string> road, int m, int len) 
	{
		::n=n;
		::m=m;
		::len=len;
		vector<int> all=parse<int>(accumulate(road.begin(),road.end(),string(""))," ,");
		assert(0==(all.size()%3));
		debug(all.size());
		int sum=0;
		for(int i=0;i<all.size();i+=3)
		{
			int a=all[i],b=all[i+1];
			cost[a][b]=cost[b][a]=all[i+2];
			edge[a].push_back(b);
			edge[b].push_back(a);
			sum+=all[i+2];
		}
		DP(0,-1);
		int ans=1000000000;
		for(int i=0;i<=m;i++)
		{
			ans=min(ans,dp[0][2*i][0]+i*len);
		}
		debug(ans);
		ans+=sum;
		return ans;
	} 
};
/*
int main()
{
	vector<string> edge;
	string ss;
	int n,m,len;
	cin>>n>>m>>len;
	while(getchar()!='\n');
	char buf[100];
	while(gets(buf))
	{
		edge.push_back(string(buf));
		debug(buf);
	}
	edge.push_back(ss);
	KingdomTour kk;
	cout<<kk.minTime(n,edge,m,len)<<endl;
	return 0;
}
*/
