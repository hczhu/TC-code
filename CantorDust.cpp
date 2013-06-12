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

char get_color(int ind)
{
	while(ind)
	{
		if(1==(ind%3))return '.';
		ind/=3;
	}
	return 'X';
}

int match_times(string& a,string& b)
{
	int re=0;
	for(int i=0;i+b.length()<=a.length();i++)
		if(0==memcmp(a.c_str()+i,b.c_str(),b.length()))re++;
	return re;
}

class CantorDust {
//Review your code before submission!!!!
	public:
	int occurrencesNumber(vector <string> pattern, int time) 
	{
		int n=1;
		for(int i=0;i<time;i++)n*=3;
		string brow,wrow(n,'.');
		for(int i=0;i<n;i++)brow+=get_color(i);
		const int R=pattern.size();
		const int C=pattern[0].size();
		vector<int> brow_match(R),wrow_match(R);
		for(int i=0;i<R;i++)
		{
			brow_match[i]=match_times(brow,pattern[i]);
			wrow_match[i]=match_times(wrow,pattern[i]);
		}
		int res=0;
		for(int r1=0;r1+R<=n;r1++)
		{
			int low=n;
			int prew=-1;
			for(int i=0;i<R;i++)
			{
				if(get_color(i+r1)=='X')
				{
					if(prew!=-1&&pattern[i]!=pattern[prew])low=0;
					prew=i;
					low=min(low,brow_match[i]);
				}
				else low=min(low,wrow_match[i]);

			}
			res+=low;
		}
		return res;
	}
};
