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


vector<string> grid;
int DFS(int r,int c)
{
	grid[r][c]=='.';
	int re=1;
	for(int dr=-1;dr<=1;dr+=2)
	for(int dc=-1;dc<=1;dc+=2)
	{
		int nr=r+dr;
		int nc=c+dc;
		if(nr<0||nr==grid.size()||nc<0||nc>=grid[0].length()||grid[nr][nc]=='.')
			continue;
		re+=DFS(nr,nc);
	}
	return re;
}
map<vector<int>, vector<int> >  mem;
vector<int> DP(vector<int> state,int turn,int n,const vector<int>& score)
{
	if(*max_element(state.begin(),state.end())==0)
		return vector<int>(n,0);
	if(mem.count(state))return mem[state];
	vector<int> res(n,-1);
	int pos=turn%n;
	for(int i=0;i<state.size();i++)
	{
		if(state[i]==0)continue;
		state[i]--;
		int add=0;
		if(state[i]==0)add=score[i];
		vector<int> tmp=DP(state,turn+1,n,score);
		tmp[pos]+=add;
		if(tmp[pos]>res[pos])res=tmp;
		state[i]++;
	}
	mem[state]=res;
	return res;
}






class MultiplayerBattleships {
	public:
	int getFirstPlayerScore(vector <string> field, int playerCount) 
	{
		grid=field;
		vector<int> all;
		for(int i=0;i<grid.size();i++)
		for(int j=0;j<grid[i].length();j++)
			if(grid[i][j]=='#')all.push_back(DFS(i,j));
		return DP(all,0,playerCount,all)[0];
	}
};
