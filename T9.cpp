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

class T9 {
//Review your code before submission!!!!
	public:
	string message(vector <string> part, vector <string> dict, vector <string> keystr) 
	{
		map<string,vector<string> > invert;
		char alpha[26];
		for(int i=0;i<9;i++)
		for(int j=0;j<part[i].length();j++)
			alpha[part[i][j]-'a']=i+1+'0';
		string res;
		for(int i=0;i<dict.size();i++)
		{
			string code;
			for(int j=0;j<dict[i].length();j++)
				code.push_back(alpha[dict[i][j]-'a']);
			debug(code);
			debug(dict[i]);
			invert[code].push_back(dict[i]);
		}
		for(map<string,vector<string> >::iterator itr=invert.begin();itr!=invert.end();itr++)
		{
			sort(itr->second.begin(),itr->second.end());
			debug(itr->second.size());
		}
		string all=accumulate(keystr.begin(),keystr.end(),string(""));
		all+="0";
		string cur="";
		for(int i=0;i<all.length();i++)
		{
			if(all[i]>='1'&&all[i]<='9')
			{
				cur.push_back(all[i]);
			}
			else if(all[i]=='0')
			{
				if(cur!="")
				{
					assert(invert.find(cur)!=invert.end());
					res+=invert[cur][0];
					debug(cur);
					debug(invert[cur][0]);
					cur="";
				}
				res+=" ";
			}
			else
			{
				int idx=0;
				while(all[i]=='#'||all[i]=='*')
				{
					idx+=all[i]=='#'?1:5;
					i++;
				}
				debug(cur);
				debug(idx);
				assert(invert.find(cur)!=invert.end());
				assert(invert[cur].size()>idx);
				res+=invert[cur][idx];
				cur="";
				i--;
			}
		}
		res.erase(res.end()-1);
		return res;
	}
};

