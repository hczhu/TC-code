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
bool used[100];
class Nisoku {
//Review your code before submission!!!!
	public:
	double theMax(vector <double> card) 
	{
		sort(card.begin(),card.end());
		double ans=1.0;
		for(int i=0;i<card.size();i++)
		{
			if(used[i])continue;
			debug(card[i]);
			double x=card[i];
			for(int j=card.size()-1;j>i;j--)
			{
				if(!used[j]&&x*card[j]<x+card[j])
				{
					used[j]=true;
					x+=card[j];
					cerr<<"find "<<card[j]<<endl;
					break;
				}
			}
			ans*=x;
		}
		return ans;
	}
};

