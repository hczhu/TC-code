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
int get_index(char ch)
{
	if(islower(ch))return 26+ch-'a';
	return ch-'A';
}
class BallsConverter {
	public:
	string theGood(vector <string> convert) {
		const int n=convert.size();
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(convert[i][j]!=convert[j][i])return "Bad";
			for(int k=0;k<n;k++)
			{
				if(convert[get_index(convert[i][j])][k]!=
						convert[i][get_index(convert[j][k])])
					return "Bad";
			}
		}
		return "Good";
	}
};
