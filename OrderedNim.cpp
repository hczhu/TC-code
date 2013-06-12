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

class OrderedNim {
//Review your code before submission!!!!
	public:
	string winner(vector <int> heap) {
		int win=0;
		string name[2]={"Bob","Alice"};
		for(int i=heap.size()-1;i>=0;i--)
		{
			if(heap[i]==1)win^=1;
			else win=1;
		}
		return name[win];
	}
};

