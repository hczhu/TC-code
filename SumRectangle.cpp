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
int num[100][100];
class SumRectangle {
	public:
	int getCorner(vector <int> col, vector <int> row) 
	{
		const int n=col.size();
		const int m=row.size();
		for(int i=0;i<m;i++)num[0][i]=row[i];
		for(int i=0;i<n;i++)num[i][0]=col[i];
		for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			num[i][j]=num[i-1][j-1]-num[i][j-1]-num[i-1][j];
		return num[n-1][m-1];
	}
};
