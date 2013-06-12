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




class CubePainting {
//Review your code before submission!!!!
	public:
	int count(vector <string> cube) 
	{
		vector<string> top(3);
		for(int i=0;i<3;i++)
		{
			top[i]=cube[i+3].substr(6,3);
			reverse(top[i].begin(),top[i].end());
		}
		string mid[3];
		for(int i=0;i<3;i++)
		{
			mid[i]+=cube[i];
			for(int j=0;j<3;j++)mid[i].push_back(cube[j+3][3+i]);
			mid[i]+=cube[6+i];
			for(int j=0;j<3;j++)mid[i].push_back(cube[j+3][9+i]);
			debug(i);
			debug(mid[i]);
		}
		vector<string> bottom(3);
		for(int i=0;i<3;i++)bottom[i]=cube[i+3].substr(0,3);
		cerr<<"top"<<endl;for(int i=0;i<3;i++)cerr<<top[i]<<endl;
		cerr<<"bottom"<<endl;for(int i=0;i<3;i++)cerr<<bottom[i]<<endl;
		return 0;
	}
};
