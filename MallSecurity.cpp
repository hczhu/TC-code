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
//Maximum Cardinality bipartite matching
template<int N>
class bipartite_match_t
{
public:
int rset[N];
int rmatch[N];
int ff;
bool augment(int v,const vector<vector<int> >& edge)
{
	for(int i=0;i<edge[v].size();i++)
	{
		int u=edge[v][i];
		if(ff==rset[u])continue;
		rset[u]=ff;
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
	memset(rset,0,sizeof(rset[0])*m);
	memset(rmatch,0xff,sizeof(int)*m);
	int res=0;
	ff=1;
	for(int i=0;i<n;i++)
	{
		if(!augment(i,edge))continue;
		res++;
		ff++;
		//memset(rset,false,sizeof(bool)*m);
	}
	return res;
};
};
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


bipartite_match_t<100> solver;
int flag[50][100];
int used[50][100];
int etop[50];
vector<int> up[50][100],down[50][100];
class MallSecurity {
//Review your code before submission!!!!
	public:
	int maxGuards(int n, vector <string> esc)
	{
		vector<string> all=parse<string>(accumulate(esc.begin(),esc.end(),string("")),",");
		for(int i=0;i<all.size();i++)
		{
			int a,b,c;
			sscanf(all[i].c_str(),"%d %d %d",&a,&b,&c);
			int f1=c-1;
			int f2=c%n;
			etop[f1]=max(etop[f1],a);
			etop[f2]=max(etop[f2],b);
			a--;b--;
			up[f1][a].push_back(b);
			down[f2][b].push_back(a);
		}
		const int floor=(int)(min_element(etop,etop+n)-etop);
		const int neck=etop[floor];
		debug(floor);
		debug(neck);
		int ans=0;
		int ff=1;
		for(int mk=0;mk<(1<<neck);mk++,ff++)
		{
			int pick=0;
			for(int i=0;i<neck;i++)
			{
				used[floor][i]=ff;
				if((1<<i)&mk)
				{
					pick++;
					for(int j=0;j<up[floor][i].size();j++)used[(floor+1)%n][up[floor][i][j]]=ff;
					for(int j=0;j<down[floor][i].size();j++)used[(floor+n-1)%n][down[floor][i][j]]=ff;
				}
			}
			int ltop=0,rtop=0;
			for(int i=(floor+1)%n,ll=0;i!=floor;i++,i%=n,ll^=1)
			for(int j=0;j<etop[i];j++)
			{
				if(ff!=used[i][j])
				{
					if(0==ll)flag[i][j]=ltop++;
					else flag[i][j]=rtop++;
				}
			}
			debug(mk);
			debug(ltop);
			debug(rtop);
			vector<vector<int> >  edge(ltop);
			int lcnt=0;
			for(int i=(floor+1)%n,ll=0;i!=floor;i++,i%=n,ll^=1)
			{
				if(1==ll)continue;
				for(int j=0;j<etop[i];j++)
				{
					if(ff==used[i][j])continue;
					int a=flag[i][j];lcnt++;
//					cerr<<a<<"  -->  : ";
					assert(a<ltop);
					for(int k=0;k<up[i][j].size();k++)
					{
						int b=up[i][j][k];
						if(ff!=used[(i+1)%n][b])
						{
							edge[a].push_back(flag[(i+1)%n][b]);
							assert((flag[(i+1)%n][b]<rtop));
//							cerr<<b<<" ";
						}
					}
					for(int k=0;k<down[i][j].size();k++)
					{
						int b=down[i][j][k];
						if(ff!=used[(i+n-1)%n][b])
						{
							edge[a].push_back(flag[(i+n-1)%n][b]);
							assert(flag[(i+n-1)%n][b]<rtop);
//							cerr<<b<<" ";
						}
					}
//					cerr<<endl;
				}
			}
			assert(lcnt==ltop);
			pick+=ltop+rtop-solver.maxMatch(ltop,rtop,edge);
			debug(pick);
			ans=max(ans,pick);
		}
		return ans;
	}
};

