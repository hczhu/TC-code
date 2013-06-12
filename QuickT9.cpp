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
const string button[]=
{
    "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};
int hash[1000];
map<string,vector<string> > invert;
map<pair<string,string>,int> order;
const int inf=10000000;
int sum[100][100];
int dp[100];
int get_min(string seg)
{
	int res=inf;
	string dig="";
	for(int j=0;j<seg.length();j++)dig.push_back('0'+hash[seg[j]]);
	const vector<string>& list=invert[dig];
	for(int i=0;i<list.size();i++)
	{
		if(list[i].length()<seg.length()||list[i].substr(0,seg.length())!=seg)
			continue;
		const string& word=list[i];
		string more=dig;
		for(int j=seg.length();j<=word.length();j++)
		{
			vector<string>& mlist=invert[more];
			int sum=seg.length(),star=0;
			assert(order.count(make_pair(more,word)));
			star=order[make_pair(more,word)];
			sum+=j==seg.length()?1:2*(j-seg.length());
			sum+=star;
		//	cerr<<word<<" for "<<seg<<"="<<star<<" "<<sum<<endl;
			res=min(res,sum);
			if(j<word.length())more.push_back(hash[word[j]]+'0');
		}
	}
	//cerr<<seg<<"="<<res<<endl;
	return res;
}
class QuickT9 {
	public:
	int minimumPressings(vector <string> t9, string word) 
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<button[i].length();j++)hash[button[i][j]]=i;
		}
		int top=0;
		vector<string> all_word;
		for(int i=0;i<t9.size();i++)
		{
			istringstream is(t9[i]);
			string dic;
			while(is>>dic)
			{
				string dig="";
				invert[dig].push_back(dic);
				for(int j=0;j<dic.length();j++)
				{
					dig.push_back(hash[dic[j]]+'0');
					invert[dig].push_back(dic);
				}
				all_word.push_back(dic);
			}
		}
		debug(invert.size());
		for(map<string,vector<string> >::iterator itr=invert.begin();itr!=invert.end();itr++)
		{
			sort(itr->second.begin(),itr->second.end());
			int sum=0;
			int len=itr->first.length();
			for(int i=0;i<itr->second.size();i++)
			{
				if(i&&itr->second[i-1].substr(0,len)!=itr->second[i].substr(0,len))sum++;
				order[make_pair(itr->first,itr->second[i])]=sum;
			}
		}
		for(int i=1;i<=word.length();i++)dp[i]=inf;
		for(int i=0;i<word.length();i++)
		{
			for(int j=1;j+i<=word.length();j++)
			{
				int t=get_min(word.substr(i,j));
				dp[i+j]=min(dp[i]+t,dp[i+j]);
			}
		}
		int ans=dp[word.length()];
		if(ans==inf)return -1;
		return ans;
	}
};
