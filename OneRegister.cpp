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
string BFS(int s,int t)
{
	set<int> mem;
	mem.insert(s);
	typedef pair<int,string> node;
	queue<node> qq;
	qq.push(make_pair(s,""));
	while(qq.size())
	{
		string prog=qq.front().second;
		int v=qq.front().first;
		qq.pop();
		if(v==t)return prog;
		if(v<=t/v&&mem.count(v*v)==0)
			mem.insert(v*v),qq.push(make_pair(v*v,prog+"*"));
		if(v*2<=t&&mem.count(v*2)==0)
			mem.insert(v*2),qq.push(make_pair(v*2,prog+"+"));
	}
	return "#";
}
class OneRegister {
	public:
	string getProgram(int s, int t) 
	{
		const string bad=":-(";
		if(s==t)return "";
		if(s==0)return bad;
		if(t==0)return "-";
		if(t==1)return "/";
		string ans=bad;
		string tt=BFS(s,t);
		if(tt!="#")ans=tt;
		tt=BFS(1,t);
		if(tt!="#"&&(ans==bad||ans.length()>("/"+tt).length()||(ans.length()==("/"+tt).length()&&ans>("/"+tt))))
			ans=("/"+tt);
		return ans;
	}
};
