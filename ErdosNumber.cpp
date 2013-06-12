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

template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
class ErdosNumber {
//Review your code before submission!!!!
	public:
	vector <string> calculateNumbers(vector <string> publication) 
	{
		const int inf=1000000;
		map<string,int> ans;
		for(int i=0;i<publication.size();i++)
		{
			vector<string> names=parse<string>(publication[i]);
			for(int j=0;j<names.size();j++)ans[names[j]]=inf;
		}
		ans["ERDOS"]=0;
		queue<string> qq;
		qq.push("ERDOS");
		while(qq.size())
		{
			string seed=qq.front();qq.pop();
			for(int i=0;i<publication.size();i++)
			{
				vector<string> names=parse<string>(publication[i]);
				if(names.end()==find(names.begin(),names.end(),seed))continue;
				for(int j=0;j<names.size();j++)
				{
					if(ans[names[j]]>ans[seed]+1)
						ans[names[j]]=ans[seed]+1,qq.push(names[j]);
				}
			}
		}
		vector<string> res;
		for(map<string,int>::iterator it=ans.begin();it!=ans.end();it++)
		{
			res.push_back(it->first);
			if(it->second<inf)res.back()+=" "+convert(it->second);
		}
		return res;
	}
};
