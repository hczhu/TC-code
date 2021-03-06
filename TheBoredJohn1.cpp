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

typedef long long int llint;
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

const int N=4000000;
int euler[N+1];
void preprocess()
{
	for(int t=2;t*t<=N;t++)
	{
		if(euler[t])continue;
		for(int s=t*t;s<=N;s+=t)euler[s]=t;
	}
	euler[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(euler[i]==0)
		{
			euler[i]=i-1;
			continue;
		}
		int p=euler[i],n=i/p,mm=p-1;
		while(0==(n%p))n/=p,mm*=p;
		euler[i]=euler[n]*mm;
	}
}

class TheBoredJohn {
	public:
	long long killMonsters(int n, long long k, vector <string> missing) 
	{
		preprocess();
		return 0;
		vector<int> all=parse<int>(accumulate(missing.begin(),missing.end(),string(""))," ,");
		debug(all.size());
		map<pair<int,int>,int > mem;
		map<int,int> miss;
		for(int i=0;i<all.size();i+=2)
		{
			int r=all[i],c=all[i+1];
			int g=__gcd(r,c);
			r/=g;c/=g;
			mem[make_pair(r,c)]++;
			miss[max(r,c)]++;
		}
		llint rem=(llint)n*(llint)n;
		llint res=0;
		vector<llint> missline;
		for(map<pair<int,int>,int>::iterator it=mem.begin();it!=mem.end();it++)
			missline.push_back((llint)n/max(it->first.first,it->first.second)-it->second);
		debug(missline.size());
		sort(missline.begin(),missline.end(),greater<int>());
		for(int i=0;i<missline.size();i++)cerr<<missline[i]<<" ";cerr<<endl;
		for(int a=1;a<n;a++)
		{

		}

		return res;
	} 
};
