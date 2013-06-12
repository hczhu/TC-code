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
typedef pair<int,int>  pp;
int cmp(int a1,int b1,int a2,int b2)
{
	if(a1!=a2)return a1>a2?1:-1;
	if(b1!=b2)return b1<b2?1:-1;
	return 0;
}
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
int low[51][61][20],high[51][61][20];
const int inf=100000000;
int alower[100],blower[100];
int aupper[100],bupper[100];
class ChuckContest {
	public:
	string chuckRules(int prob, vector <string> lower, 
			vector <string> upper, vector <int> part) 
	{
		const int n=part.size();
		
		for(int i=0;i<n;i++)
			sscanf(lower[i].c_str(),"%d %d",alower+i,blower+i),blower[i]--,
			sscanf(upper[i].c_str(),"%d %d",aupper+i,bupper+i),bupper[i]++;
		for(int i=n-2;i>=0;i--)
		{
			if(0>cmp(aupper[i+1],bupper[i+1],aupper[i],bupper[i]))
				aupper[i]=aupper[i+1],bupper[i]=bupper[i+1];
		}

		for(int k=0;k<=n;k++)
		for(int i=0;i<=prob;i++)
		for(int j=0;j<20;j++)
			low[k][i][j]=inf;
		low[0][0][0]=0;
		int start=1;
		for(int i=1;i<=n;i++)
		{
			hline();
			debug(i);
			int end=part[i-1];
			for(int a=0;a<=prob;a++)
			for(int b=0;b<20;b++)
			{
				low[i][a][b]=low[i-1][a][b];
				int& ll=low[i][a][b];
				if(a&&a==aupper[i-1]&&ll<bupper[i-1])
					ll+=(bupper[i-1]+19-ll)/20*20;
				for(int k=1;k<=a;k++)
				{
					const int base=k*start;
					int add=(end-start)*k%20;
					for(int j=0;j<=add;j++)
					{
						int rem=(b-base-j)%20;rem+=20;rem%=20;
						int t=base+j+low[i-1][a-k][rem];
						if(a==aupper[i-1]&&t<bupper[i-1])
							t+=(bupper[i-1]-t+19)/20*20;
						ll=min(ll,t);

					}
				}
				if(cmp(a,ll,alower[i-1],blower[i-1])<0||
					cmp(a,ll,aupper[i-1],bupper[i-1])>0)
					ll=inf;
				if(ll<inf)cerr<<a<<" "<<b<<" "<<ll<<endl;
			}
			start=end+1;
		}
		int ra=-1,rb=inf;
		for(int a=prob;a>=0;a--)
		for(int b=0;b<20;b++)
		{
			if(low[n][a][b]>=inf)continue;
			if(cmp(ra,rb,a,low[n][a][b])<0)
				ra=a,rb=low[n][a][b];
		}
		if(ra==-1)return "";
		return convert(ra)+" "+convert(rb);
	}
};

int main()
{
	ChuckContest cc;
	int prob;
	int n;
	cin>>prob>>n;
	vector<string> lower,upper;
	vector<int> part;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		lower.push_back(convert(a)+" "+convert(b));
		cin>>a>>b;
		upper.push_back(convert(a)+" "+convert(b));
		cin>>a;
		part.push_back(a);
	}
	debug(cc.chuckRules(prob,lower,upper,part));
	return 0;
}


