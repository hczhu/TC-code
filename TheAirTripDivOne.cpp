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
typedef long long int llint;
int aa[10000],bb[10000];
llint ff[10000],tt[10000],pp[10000];
vector<int> edge[500];
llint dis[500];
bool used[500];
typedef pair<llint,int> ppt;
llint check(int n,int delay)
{
	const llint inf=100000100000000001LL;
	for(int i=0;i<n;i++)dis[i]=inf;
	memset(used,false,sizeof(used));
	dis[0]=0;
	priority_queue<ppt,vector<ppt>,greater<ppt> > qq;
	//priority_queue<ppt> qq;
	qq.push(ppt(0,0));
	while(qq.size())
	{
		int v=qq.top().second;
		llint d=qq.top().first;
		qq.pop();
		if(used[v])continue;
		used[v]=true;
		cerr<<v<<"="<<dis[v]<<endl;
		if(v==n-1)return d;
		for(int i=0;i<edge[v].size();i++)
		{
			int e=edge[v][i];
			int u=bb[e];
			if(used[u])continue;
			llint next=max(ff[e],(d-ff[e]+pp[e])/pp[e]*pp[e]+ff[e]);
			while(v&&next-d<delay)next+=(delay-next+d+pp[e]-1)/pp[e]*pp[e];
			next+=tt[e];
			if(next<dis[u])
				dis[u]=next,qq.push(ppt(next,u));
		}
	}
	return inf;
}
class TheAirTripDivOne {
	public:
	int find(int n, vector <string> flights, int cap) 
	{
		vector<int> tmp=parse<int>(accumulate(flights.begin(),flights.end(),string("")),", ");
		debug(tmp.size());
		for(int i=0;i<tmp.size();i+=5)
		{
			aa[i/5]=tmp[i]-1;
			bb[i/5]=tmp[i+1]-1;
			ff[i/5]=tmp[i+2];
			tt[i/5]=tmp[i+3];
			pp[i/5]=tmp[i+4];
			edge[aa[i/5]].push_back(i/5);
		}
		int low=0,high=1000000001;
		debug(check(n,14));
		while(low<high)
		{
			int mid=((low+high)>>1)+1;
			if(check(n,mid)<=cap)low=mid;
			else high=mid-1;
			debug(low);
		}
		if(low==0)return -1;
		return low;
	}
};
