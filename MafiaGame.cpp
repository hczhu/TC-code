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

class MafiaGame {
	public:
	double probabilityToLose(int N, vector <int> dec) {
		vector<int> hash(N,0);
		for(int i=0;i<dec.size();i++)hash[dec[i]]++;
		int mm;
		if((mm=*max_element(hash.begin(),hash.end()))<=1)return 0.0;
		debug(mm);
		int cnt=0;
		for(int i=0;i<N;i++)if(hash[i]==mm)cnt++;
		int x=cnt;
		debug(x);
		for(x=cnt;x>1;) {
			if(0==(N%x))return 0.0;
			x=N%x;
			debug(x);
		}
		return 1.0/cnt;
	}
};
