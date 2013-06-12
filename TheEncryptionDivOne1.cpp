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
typedef long long int llint;
const llint mod=1234567891;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
int match[1000],rmatch[1000];

map<vector<int>,llint> mem;
llint DP(vector<int>& state)
{
	if(mem.count(state))return mem[state];
	if(state[0]==26)return 1;
	llint res=0;
	for(int i=3;i<9;i++)
	{
		if(state[i]==0)continue;
		int x=i/3,y=i%3;
		for(int j=0;j<9;j++)
		{
			if(0==state[j]||i==j)continue;
			int a=j/3,b=j%3;
			if(0==b)continue;
			const int mm=state[j];
			state[i]--;state[(x-1)*3+y]++;
			state[j]--;state[a*3+(b-1)]++;
			res+=b*DP(state)*mm;res%=mod;
			state[j]++;state[a*3+(b-1)]--;
			state[i]++;state[(x-1)*3+y]--;
		}
		if(state[i]>1&&y>0)
		{
			const int mm=state[i]-1;
			state[i]-=2;
			state[(x-1)*3+y]++;
			state[x*3+y-1]++;
			res+=mm*DP(state)*y;res%=mod;
			state[i]+=2;
			state[(x-1)*3+y]--;
			state[x*3+y-1]--;
		}
		break;
	}
	mem[state]=res;
	//for(int i=0;i<state.size();i++)cerr<<state[i]<<" ";cerr<<endl;
	//debug(res);
	return res;
}
class TheEncryptionDivOne {
	public:
	int count(string msg, string emsg) {
		for(int i=0;i<msg.length();i++)
		{
			char a=msg[i];
			char b=emsg[i];
			if(tolower(a)==b||toupper(a)==b)return 0;
			if(match[a]&&match[a]!=b)return 0;
			if(rmatch[b]&&rmatch[b]!=a)return 0;
			match[a]=b;rmatch[b]=a;
		}
		vector<int> state(9,0);
		for(char a='a',b='A';a<='z';a++,b++)
		{
			int x=0,y=0;
			if(0==match[a])x++;
			if(0==match[b])x++;
			if(0==rmatch[a])y++;
			if(0==rmatch[b])y++;
			state[x*3+y]++;
		}
		debug(state.size());
		for(int i=0;i<state.size();i++)cerr<<state[i]<<" ";cerr<<endl;
		return DP(state);
	}
};
int main()
{
	TheEncryptionDivOne the;
	string aa,bb;
	while(cin>>aa>>bb)
	{
		mem.clear();
		memset(match,0,sizeof(match));
		memset(rmatch,0,sizeof(rmatch));
		cout<<the.count(aa,bb)<<endl;
	}
	return 0;
}
