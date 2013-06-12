
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



class OneWayStreets {
	public:
	string canChange(vector <string> road) 
	{
		const int n=road.size();
		for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(road[i][j]==road[j][i])road[i][j]=road[j][i]='N';
		for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(road[i][k]=='Y'&&road[k][j]=='Y')
				road[i][j]='Y';
		for(int i=0;i<n;i++)
			if(road[i][i]=='Y')return "NO";
		return "YES";
	}
};
