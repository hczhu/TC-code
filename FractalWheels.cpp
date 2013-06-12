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
template<>
vector<string> parse(const string& ss,const char* cut)
{
	vector<string> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			re.push_back(s);
		}
	}
	return re;
}
vector<vector<int> > edge; 
const int N=1000;
bool con[N][N];
int visited[N];
bool check_cycle(vector<int>& all)
{
	map<int,int> mem;
	for(int i=0;i<all.size();i++)mem[all[i]]=i;
	assert(mem.size()==all.size());
	const int n=all.size();
	vector<vector<int> > cycle(n);
	for(int i=0;i<all.size();i++)
	{
		int x=all[i];
		for(int j=0;j<edge[x].size();j++)
		{
			int y=edge[x][j];
			if(mem.count(y))
			{
				cycle[i].push_back(mem[y]);
	//	//		cycle[mem[y]].push_back(i);
		//		cerr<<x<<" --- "<<y<<endl;
			}
		}
	}
	for(int i=0;i<n;i++)if(cycle[i].size()!=2)
	{
		debug("bad");
		return false;
	}
	for(int i=0;i<n;i++)visited[i]=false;
	queue<int> qq;
	qq.push(0);visited[0]=true;
	int cnt=0;
	while(qq.size())
	{
		int v=qq.front();qq.pop();
		cnt++;
		for(int i=0;i<cycle[v].size();i++)
		{
			if(!visited[cycle[v][i]])
			{
				visited[cycle[v][i]]=true;
				qq.push(cycle[v][i]);
			}
		}
	}
	debug(cnt);
	return cnt==n;
	return find(visited,visited+n,false)==visited+n;
}
bool used[N];
int pp[N];
bool check_wheel(int v,int d,int k)
{
	queue<int> qq;
	qq.push(v);used[v]=true;
	while(d-->=0)
	{
		if(qq.size()==0)return false;
		for(int tt=qq.size();tt--;)
		{
			int v=qq.front();qq.pop();
			vector<int> son;
			for(int i=0;i<edge[v].size();i++)
			{
				int u=edge[v][i];
				if(!used[u])qq.push(u),son.push_back(u),used[u]=true;
			}
			debug(son.size());
			if(son.size()!=k||!check_cycle(son))return false;
		}
	}
	return true;
}

class FractalWheels {
	public:
	vector <int> describeWheel(int n, vector <string> edges) 
	{
		vector<string> tmp=parse<string>(accumulate(edges.begin(),edges.end(),string("")),",");
		edge.resize(n);
		int em=0;
		for(int i=0;i<tmp.size();i++)
		{
			vector<int> ee=parse<int>(tmp[i]);
			assert(ee.size()==2);
			int a=ee[0],b=ee[1];
			con[a][b]=con[b][a]=true;
			edge[a].push_back(b);
			edge[b].push_back(a);
			cerr<<a<<" ---- "<<b<<endl;
			++em;
		}
		vector<int> res;

		for(int i=0;i<n;i++)
		{
			debug(edge[i].size());
			if(edge[i].size()<3)continue;
			int d=0,k=edge[i].size();
			for(int m=n;m>1;)
			{
				if((m%k)!=1)
				{
					d=-1;
					break;
				}
				m/=k;
				d++;
			}
			debug(i);
			debug(d);
			d--;
			if(d<0)continue;
			int e=2*k;
			debug(d);
			debug(k);
			debug(e);
			for(int j=0;j<d;j++)e*=k,e+=2*k;
			debug(em);
			debug(e);
			if(em!=e)continue;
			vector<int> all(n);
			for(int j=0;j<n;j++)all[j]=j,used[j]=false,pp[i]=-1;
			if(check_wheel(i,d,k))
			{
				res.resize(2);
				res[0]=d;
				res[1]=k;
			}
		}

		return res;
	}
};


// Powered by FileEdit
