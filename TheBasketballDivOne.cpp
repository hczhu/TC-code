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

const int N=5;
int win[N];
int aa[N*N],bb[N*N];
set<vector<int> > mem;
int DFS(int pos,int top,int m,int n)
{
	if(pos==top)
	{
		if((*max_element(win,win+n))==m)
		{
			vector<int> tmp(win,win+n);
			sort(tmp.begin(),tmp.end());
			if(mem.count(tmp)==0)
			{
				mem.insert(tmp);
				return 1;
			}
			return 0;
		}
		return 0;
	}
	int res=0;
	for(int w=0;w<=2;w++)
	{
		win[aa[pos]]+=w;
		win[bb[pos]]+=2-w;
		res+=DFS(pos+1,top,m,n);
		win[aa[pos]]-=w;
		win[bb[pos]]-=2-w;
	}
	return res;
}
class TheBasketballDivOne {
//Review your code before submission!!!!
	public:
	int find(int n, int m) {
		mem.clear();
		int top=0;
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
		{
			aa[top]=a;
			bb[top++]=b;
		}
		//debug(top);
		return DFS(0,top,m,n);
	}
};



int main()
{
	TheBasketballDivOne tt;
	for(int n=2;n<=5;n++)
	for(int m=1;m<=9;m++)
	{
		cout<<n<<" "<<m<<" = "<<tt.find(n,m)<<endl;
	}
	return 0;
}


