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



class TheNewHouseDivOne {
	public:
	double distance(vector <int> hx, vector <int> hy, int k) 
	{
		double res=1e20;
		for(double x=-51;x<51;x+=0.5)
		for(double y=-50;y<51;y+=0.5)
		{
			vector<double> dis;
			for(int i=0;i<hx.size();i++)
				dis.push_back(fabs(hx[i]-x)+fabs(hy[i]-y));
			sort(dis.begin(),dis.end());
			res=min(res,dis[k-1]);
		}
		return res;
	}
};
