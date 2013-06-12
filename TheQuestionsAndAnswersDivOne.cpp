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
vector<int> can;
int ans=0;
bool exist[10][1<<10];
int mem[10][1<<10];
int DP(int pos,int n,int rem)
{
	if(pos==n)return rem==0?1:0;
	if(exist[pos][rem])return mem[pos][rem];
	exist[pos][rem]=true;
	int& res=mem[pos][rem];
	for(int i=0;i<can.size();i++)
	{
		if((rem&can[i])!=can[i])continue;
		res+=DP(pos+1,n,rem^can[i]);
	}
	return res;
}
class TheQuestionsAndAnswersDivOne {
//Review your code before submission!!!!
	public:
	int find(int n, vector <string> answer) 
	{
		const int m=answer.size();
		for(int mk=1;mk<two(m);mk++)
		{
			bool ok=true;
			vector<int> pick;
			for(int i=0;i<m;i++)
				if(two(i)&mk)pick.push_back(i);
			for(int i=1;i<pick.size();i++)
				if(answer[pick[i]]!=answer[pick[0]])ok=false;
			if(ok)
			{
				can.push_back(mk);
				debug(mk);
			}
		}
		debug(can.size());
		return DP(0,n,two(m)-1);
	}
};

