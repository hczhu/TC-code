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
typedef long long int llint;
llint x,y,z;
struct node_t
{
	int pos[3];
	node_t(int x,int y,int z){pos[0]=x,pos[1]=y,pos[2]=z;};
	node_t(){};
	llint get_value()const
	{
		return x*pos[0]+y*pos[1]+z*pos[2];
	}
	bool operator<(const node_t& other)const
	{
		return get_value()<other.get_value();
	};
};
void BFS(int step,map<pair<llint,llint>,int>& mem,llint x,llint y)
{
	mem.insert(make_pair(x,y));
	queue<pair<llint,llint> > qq;
	qq.push(*(mem.begin()));
	for(int i=0;i<step;i++)
	{
		for(int t=qq.size();t--;)
		{
			x=qq.front().first;
			y=qq.front().second;
			qq.pop();
			{
				llint nx=x+y;
				llint ny=y;
				if(mem.count(make_pair(nx,ny))==0)
					mem.insert(make_pair(nx,ny)),qq.push(make_pair(nx,ny));
			}
			{
				llint nx=x;
				llint ny=x+y;
				if(mem.count(make_pair(nx,ny))==0)
					mem.insert(make_pair(nx,ny)),qq.push(make_pair(nx,ny));
			}
			if(y>x)
			{
				llint nx=x;
				llint ny=y-x;
				if(mem.count(make_pair(nx,ny))==0)
					mem.insert(make_pair(nx,ny)),qq.push(make_pair(nx,ny));
			}
			if(y<x)
			{
				llint nx=x-y;
				llint ny=y;
				if(mem.count(make_pair(nx,ny))==0)
					mem.insert(make_pair(nx,ny)),qq.push(make_pair(nx,ny));
			}
		}
	}
	debug(mem.size());
}
class RabbitPuzzle {
//Review your code before submission!!!!
	public:
	int theCount(vector<long long> sou, vector<long long> det, int K) 
	{	
		set<pair<llint,llint> > mem1,mem2;
		BFS(K/2,mem1,sou[1]-sou[0],sou[2]-sou[1]);
		BFS(K-K/2,mem2,det[1]-det[0],det[2]-det[1]);

		return 
	}
};

