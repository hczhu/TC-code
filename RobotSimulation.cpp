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

class RobotSimulation {
	public:
	typedef pair<int,int>  point;
	int cellsVisited(string program, int m) 
	{
		const int n=program.length();
		point pos(0,0);
		set<point>  mem;
		mem.insert(pos);
		for(int i=0;i<n;i++)
		{
			switch(program[i])
			{
				case 'U':
					pos.second++;
					break;
				case 'D':
					pos.second--;
					break;
				case 'R':
					pos.first++;
					break;
				case 'L':
					pos.first--;
					break;
				default:
					assert(0);
			}
			mem.insert(pos);
		}
		debug(mem.size());
		if(pos==point(0,0))return mem.size();
		int ans=0;
		const int x=pos.first;
		const int y=pos.second;
		for(set<point>::iterator itr=mem.begin();itr!=mem.end();itr++)
		{
			point pos=*itr;
			ans++;
			for(int i=1;i<m;i++)
			{
				pos.first+=x,pos.second+=y;
				if(mem.find(pos)!=mem.end())break;
				ans++;
				if(i>program.length())
				{
					ans+=m-1-i;
					break;
				}
			}
			cerr<<pos.first<<" "<<pos.second<<"="<<ans<<endl;
		}
		return ans;
	}
};
