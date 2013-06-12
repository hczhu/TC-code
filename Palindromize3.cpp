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
#define two(x)  ((1)<<(x))
class Palindromize3 {
//Review your code before submission!!!!
	public:
	string getPalindrome(string s) 
	{
		const int n=s.length();
		const int m=n/2;
		string res="";
		int press=n+1,letter=n+1;
		for(int mk=0;mk<two(m);mk++)
		{
			set<char> mem;
			int key=0;
			string ans=s;
			for(int i=0;i<m;i++)
			{
				int j=n-1-i;
				if(s[i]==s[j])continue;
				key++;
				if(mk&two(i))mem.insert(s[i]),ans[j]=s[i];
				else mem.insert(s[j]),ans[i]=s[j];
			}
			if(key<press||(key==press&&mem.size()<letter)||(key==press&&mem.size()==letter&&ans<res))
				res=ans,press=key,letter=mem.size();
			debug(mk);
			debug(ans);
			debug(mem.size());
			debug(key);
		}
		return res;
	}
};

