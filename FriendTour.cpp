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

template<typename T,int N>
void init_bino(T com[N][N],bool take_mod=false,long long int mod=1000000000000000000LL)
{
	{
		com[0][0]=1;
		for(int i=1;i<N;i++)
		{
			com[i][0]=com[i][i]=1;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j]);
		}
	}
}
double com[50][50];
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
int ff[100];
double dp[1<<16][17]; 
vector<int> edge[50];
int tot[50];
double buf[100];
string input[]=
{
	"3 2 4",
	 "3 5 1",
	  "5 2 1 4",
	   "3 1 5",
	    "3 2 4"
};
class FriendTour {
	public:
	double tourProbability(vector <string> friends, int m)
	{
//		friends=vector<string>(input,input+5);
//		m=2;
		memset(ff,0xff,sizeof(ff));
		vector<int> good=parse<int>(friends[0]);
		debug(good.size());
		const int n=good.size()+1;
		ff[0]=0;
		for(int i=0;i<good.size();i++)ff[good[i]-1]=i+1;
		for(int i=0;i<friends.size();i++)
		{
			if(ff[i]<0)continue;
			debug(i);
			vector<int> tmp=parse<int>(friends[i]);
			tot[ff[i]]=tmp.size();
			for(int j=0;j<tmp.size();j++)
				if(ff[tmp[j]-1]>=0)
					edge[ff[i]].push_back(ff[tmp[j]-1]),
					cerr<<ff[i]<<"--->"<<ff[tmp[j]-1]<<endl;
			cerr<<ff[i]<<" "<<tot[ff[i]]<<endl;
		}
		init_bino(com);
		for(int i=0;i<n;i++)dp[two(n)-1][i]=1.0;
		for(int mk=two(n)-3;mk>0;mk-=2)
		{
			for(int v=0;v<n;v++)
			{
				if(0==(two(v)&mk))continue;
				double& res=dp[mk][v];
				int top=0;
				for(int k=0;k<edge[v].size();k++)
				{
					int u=edge[v][k];
					if((mk&two(u)))continue;
					buf[top++]=dp[mk^two(u)][u];
				}
				if(top==0)
				{
//					cerr<<mk<<" "<<v<<"="<<dp[mk][v]<<endl;
					continue;
				}
				sort(buf,buf+top);
				const int tt=tot[v];
				if(tt<=m)
				{
					res=buf[top-1];
//					cerr<<mk<<" "<<v<<"="<<dp[mk][v]<<endl;
					continue;
				}
				const double down=com[tt][m];
				for(int j=top-1;j>=0&&tt-(top-j-1)>=m;j--)
				{
					int pre=top-j-1;
					double p=com[tt-pre-1][m-1]/down;
					res+=p*buf[j];
				}
//				cerr<<mk<<" "<<v<<"="<<dp[mk][v]<<endl;
			}
		}
		return dp[1][0];
	}
};
