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
map<vector<int>,int> mem;
class NewCoins {
//Review your code before submission!!!!
	public:
	int minCoins(vector <int> price) {
		if(price.empty())return 0;
		if(price.size()==1)return 1;
		sort(price.begin(),price.end());
		if(mem.count(price))return mem[price];
		int res=0;
		for(int i=0;i<price.size();i++)res+=price[i];
		const int up=*max_element(price.begin(),price.end());
		for(int d=2;d<=up;d++)
		{
			int sum=0;
			vector<int> next;
			for(int i=0;i<price.size();i++)
			{
				sum+=price[i]%d;
				int rem=price[i]/d;
				if(rem)next.push_back(rem);
			}
			if(sum<res)res=min(res,sum+minCoins(next));
		}
		mem[price]=res;
		return res;
	}
};

