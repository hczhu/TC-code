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

//well defined s
int DFS(string s,int& last)
{
	last=0;
	if(s=="")return 0;
	assert(s[0]=='<');
	int sum=1;
	for(int i=1;i+1<s.length();i++)
	{
		s[i]=='<'?sum++:sum--;
		if(sum==0)
		{
			int last1,last2;
			int res=DFS(s.substr(0,i+1),last1)+DFS(s.substr(i+1,s.length()-i-1),last2);
			last=max(last1,last2);
			res+=(last1+last2-last)*(last1+last2-last);
			cerr<<s<<" = "<<res<<" "<<last<<endl;
			return res;
		}
	}
	int res=DFS(s.substr(1,s.length()-2),last);
	last++;
	cerr<<s<<" = "<<res<<" "<<last<<endl;
	return res;
}
class MegadiamondHunt {
//Review your code before submission!!!!
	public:
	int getValue(string mine) 
	{
		int stack[51];
		int top=0;
		int res=0;
		int last;
		int st=0;
		string s=mine;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='<')stack[top++]=i;
			else if(top)
			{
				top--;
				if(top==0)
				{
					string s=mine.substr(st,i-st+1);
					res+=DFS(s,last);
					cerr<<"find good "<<s<<" "<<last<<endl;
					res+=last*last;
					st=i+1;
				}
			}
			else st=i+1;
		}
		debug(top);
		for(int i=0;i<top;i++)cerr<<stack[i]<<" ";cerr<<endl;
		debug(st);
		stack[top++]=s.length();
		for(int i=1;i<top;i++)
		{
			if(stack[i]<=stack[i-1]+1)continue;
			string s=mine.substr(stack[i-1]+1,stack[i]-stack[i-1]-1);
			res+=DFS(s,last);
			cerr<<"find good "<<s<<" "<<last<<endl;
			res+=last*last;
		}
		return res;
	}
};

/*
int main()
{
	MegadiamondHunt mm;
	string ss;
	cin>>ss;
	cout<<mm.getValue(ss)<<endl;
	return 0;
}
*/
