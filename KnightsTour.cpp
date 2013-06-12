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

const int N=8;
bool visited[N][N];
vector<string> grid;
int jump[N][N];
bool valid(int r,int c)
{
	return r>=0&&r<8&&c>=0&&c<8&&!visited[r][c]&&grid[r][c]=='.';
}
int next_num(int r,int c)
{
	int res=0;
	for(int dx=-2;dx<=2;dx++)
	for(int dy=-2;dy<=2;dy++)
	{
		if(abs(dx)*abs(dy)!=2)continue;
		if(valid(r+dx,c+dy))res++;
	}
	return res;
}
bool get_next(int& r,int& c)
{
	int x=-1,y=-1,low=1000;
	for(int dx=-2;dx<=2;dx++)
	for(int dy=-2;dy<=2;dy++)
	{
		if(abs(dx)*abs(dy)!=2)continue;
		if(!valid(r+dx,c+dy))continue;
		int t=next_num(r+dx,c+dy);
		if(t<low||(t==low&&make_pair(r+dx,c+dy)<make_pair(x,y)))
			low=t,x=r+dx,y=c+dy;
	}
	r=x,c=y;
	return x!=-1;

}

class KnightsTour {
//Review your code before submission!!!!
	public:
	int visitedPositions(vector <string> board) {
		int x,y;
		grid=board;
		for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			if(grid[i][j]=='K')x=i,y=j;
		cerr<<x<<" "<<y<<endl;
		visited[x][y]=true;
		int res=1;
		while(get_next(x,y))
		{
			cerr<<x<<" "<<y<<endl;
			visited[x][y]=true;
			res++;
		}
		return res;
	}
};
