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

string get_prefix(string& a,string& b)
{
	int i;
	for(i=0;i<a.length()&&i<b.length()&&a[i]==b[i];i++);
	return a.substr(0,i);
}

class Prefixes {
//Review your code before submission!!!!
	public:
	vector <string> prefixList(vector <string> protein) 
	{
		vector<string> group[50],prefix;
		int top=0;
		while(protein.size()>1)
		{
			const int n=protein.size();
			string pre="";
			for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				string t=get_prefix(protein[i],protein[j]);
				if(t.length()>pre.length()||(t.length()==pre.length()&&t<pre))pre=t;
			}
			debug(pre);
			vector<string> next;
			prefix.push_back(pre);
			for(int i=0;i<n;i++)
			{
				if(protein[i].length()>=pre.length()&&protein[i].substr(0,pre.length())==pre)
					group[top].push_back(protein[i]);
				else next.push_back(protein[i]);
			}
			protein=next;
			debug(top);
			debug(group[top].size());
			top++;
		}
		if(protein.size())group[top]=protein,prefix.push_back(""),top++;
		debug(top);
		vector<string> res;
		for(int i=0;i<top;i++)
		{
			sort(group[i].begin(),group[i].end());
			for(int j=0;j<group[i].size();j++)
				res.push_back(group[i][j]);
			res.push_back(string(prefix[i].length(),'-'));
		}
		return res;
	}
};
