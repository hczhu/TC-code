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
class TheMoviesLevelOneDivOne {
//Review your code before submission!!!!
	public:
	long long find(int n, int m, vector <int> row, vector <int> seat) 
	{
		map<int, vector<int> > all;
		for(int i=0;i<row.size();i++)
		{
			all[row[i]].push_back(seat[i]);
		}
		llint res=(llint)n*(llint)(m-1);
		int bad=0;
		for(map<int,vector<int> >::iterator itr=all.begin();itr!=all.end();itr++)
		{
			vector<int>& col=itr->second;
			sort(col.begin(),col.end());
			debug(itr->first);
			debug(col.size());
			for(int i=0;i<col.size();i++)
			{
				if((i==0||col[i-1]!=col[i]-1)&&col[i]>1)bad++;
				if(col[i]+1<=m)bad++;
				cerr<<col[i]<<" ";
			}
			cerr<<endl;
			debug(bad);
		}
		debug(bad);
		return res-bad;
	}
};

