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


void pass(string& ss)
{
	ss.erase(ss.begin());
}
class DriveOrder {
	public:
	string determineOrder(vector <string> car, int major) 
	{
		int pri[3]={0,0,0};
		int rr[3]={1,2,0};
		if(major!=-1)pri[major]++;
		string res;
		while(car[0].length()||car[1].length()||car[2].length())
		{
			bool f=false;
			for(int i=0;i<3;i++)
				if(car[i].length()&&pri[i])
				{
					res.push_back(car[i][0]);
					pass(car[i]);
					f=true;
					break;
				}
			if(f)continue;
			f=false;
			for(int i=0;i<3;i++)
			{
				if(car[i].length()&&car[rr[i]].empty())
				{
					res.push_back(car[i][0]);
					pass(car[i]);
					f=true;
					break;

				}
			}
			if(f)continue;
			f=false;
			int ind=-1;
			char best='Z'+1;
			for(int i=0;i<3;i++)
			{
				if(car[i].length()&&car[i][0]<best)
					best=car[i][0],ind=i;
			}
			res.push_back(car[ind][0]);
			pass(car[ind]);
		}
		return res;
	}
};
