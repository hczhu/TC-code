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

const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
class SequenceOfCommands {
	public:
	string whatHappens(vector <string> commands) 
	{
		string all=accumulate(commands.begin(),commands.end(),string(""));
		int d=0;
		int x=0,y=0;
		for(int i=1;i<=1000000;i++)
		{
			switch(all[i%all.length()])
			{
				case 'L':
					d++,d%=4;
					break;
				case 'R':
					d+=3,d%=4;
					break;
				case 'S':
					x+=dir[d][0];
					y+=dir[d][1];
					break;
				default:
					break;
			};
			if(x==0&&y==0&&0==(i%all.length()))return "bounded";
		}
		return "unbounded";
	}
};
