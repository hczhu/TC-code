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



class DifDif {
//Review your code before submission!!!!
	public:
	int predict(vector <int> seq) 
	{
		int n=seq.size();
		vector<int> diff[100];
		diff[0]=seq;
		for(int i=1;i<n;i++,cerr<<endl)
		for(int j=1;j<diff[i-1].size();j++)
		{
			diff[i].push_back(diff[i-1][j]-diff[i-1][j-1]);
			cerr<<diff[i].back()<<" ";
		}
		int ans=0;
		for(int i=0;i<n;i++)ans+=diff[i].back();
		return ans;
	}
};
