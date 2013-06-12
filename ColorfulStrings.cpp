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
// Convert anything to string
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
int exist[2*3*4*5*6*7*8*9+1];
class ColorfulStrings {
//Review your code before submission!!!!
	public:
	string getKth(int n, int k) 
	{
		if(n==1)
		{
			if(k>10)return "";
			string res;
			res.push_back(k-1+'0');
			return res;
		}
		if(n>8)return "";
		int per[8];
		for(int i=0;i<8;i++)per[i]=i+2;
		vector<int> all;
		int ff=1;
		do
		{
			int num=0;
			for(int i=0;i<n;i++)
			{
				num*=10;
				num+=per[i];
			}
			ff++;
			bool ok=true;
			for(int a=0;a<n&&ok;a++)
			{
				int mm=1;
				for(int b=a;b<n&&ok;b++)
				{
					mm*=per[b];
					if(exist[mm]==ff)ok=false;
					exist[mm]=ff;
				}
			}
			if(ok)all.push_back(num);
		}while(next_permutation(per,per+8));
		debug(all.size());
		sort(all.begin(),all.end());
		int size=unique(all.begin(),all.end())-all.begin();
		if(k>size)return "";
		return convert(all[k-1]);
	}
};

