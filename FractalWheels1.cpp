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
#define NDEBUG
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
const int N=1000;
vector<int> edge[1000];
bool visited[N];
bool con[N][N];
int deg[N];
int used[N],have[N];
bool checkCycle(const vector<int>& cycle)
{
	static int ff=0;
	ff++;
	for(int i=0;i<cycle.size();i++)have[cycle[i]]=ff;
	int v=cycle[0];
	used[v]=ff;
	queue<int> qq;
	qq.push(v);
	int sum=0;
	while(qq.size())
	{
		int v=qq.front();qq.pop();sum++;
		vector<int> neib;
		int deg=0;
		if(edge[v].size()<cycle.size())
		{
			for(int i=0;i<edge[v].size();i++)
			{
				if(have[edge[v][i]]!=ff)continue;
				deg++;
				if(used[edge[v][i]]==ff){}
				else neib.push_back(edge[v][i]);
			}
		}
		else
		{
			for(int i=0;i<cycle.size();i++)
			{
				if(!con[v][cycle[i]])continue;
				deg++;
				if(used[cycle[i]]==ff){}
				else neib.push_back(cycle[i]);
			}
		}
		for(int i=0;i<neib.size();i++)
		{
			qq.push(neib[i]);
			used[neib[i]]=ff;
		}
		if(deg!=2)return false;
	}
	debug(sum);
	return sum==cycle.size();
}
int BFS(int n,int r)
{
	hline();
	cerr<<"check "<<r<<endl;
	memset(visited,false,sizeof(bool)*n);
	const int h=edge[r].size();
	if(h<3)return -1;
	int d;
	queue<int> qq;
	qq.push(r);
	visited[r]=true;
	for(d=-2;qq.size();d++)
	{
		int a=0,b=0;
		for(int t=qq.size();t--;)
		{
			int c=qq.front();qq.pop();n--;
			vector<int> cycle;
			for(int i=0;i<edge[c].size();i++)
			{
				if(!visited[edge[c][i]])
					visited[edge[c][i]]=true,qq.push(edge[c][i]),cycle.push_back(edge[c][i]);
			}
	//		debug(c);
	//		debug(cycle.size());
	//		for(int i=0;i<cycle.size();i++)cerr<<cycle[i]<<" ";cerr<<endl;
			if(cycle.size()&&cycle.size()!=h)return -1;
			if(cycle.size()==h&&!checkCycle(cycle))return -1;
			if(cycle.size()==0)a++;
			else b++;
		}
		if(a*b)return -1;
	}
	if(n)return -1;
	return d;
}

class FractalWheels {
	public:
	vector <int> describeWheel(int n, vector <string> edges) 
	{
		vector<int> all=parse<int>(accumulate(edges.begin(),edges.end(),string(""))," ,");
		debug(all.size());
		for(int i=0;i<all.size();i+=2)
			edge[all[i]].push_back(all[i+1]),
			edge[all[i+1]].push_back(all[i]),
			con[all[i]][all[i+1]]=con[all[i+1]][all[i]]=true;
		vector<int> res(2),empty;
		for(int i=0;i<n;i++)
		{
			int d;
			debug(i);
			if(edge[i].size()>=3&&(d=BFS(n,i))!=-1)
			{
				debug(i);
				res[1]=edge[i].size();
				res[0]=d;
				return res;
			}
		}
		return empty;
	}
};


// Powered by FileEdit
