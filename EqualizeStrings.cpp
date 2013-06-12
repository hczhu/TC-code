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
int get_dis(char a,char b)
{
	int d=(int)a-(int)b;
	if(d<0)d=-d;
	if(d>26-d)d=26-d;
	return d;
}
class EqualizeStrings {
	public:
	string getEq(string s, string t) 
	{
		string res(s.length(),'a');
		for(int i=0;i<s.length();i++)
		{
			int dd=100;
			for(char x='a';x<='z';x++)
			{
				int sum=get_dis(s[i],x)+get_dis(t[i],x);
				if(sum<dd)dd=sum,res[i]=x;
			}
		}
		return res;
	}
};
