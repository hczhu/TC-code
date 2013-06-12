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
#include <cassert>
#include <limits>
#include <cstdarg>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
class MinimumLiars {
	public:
	 int getMinimum(vector <int> claim) {
		 debug("Start calculation.");
     const int n=claim.size();
     for(int x=0;x<=n;x++) {
       int liar=0;
       for(int i=0;i<n;i++)if(claim[i]>x)liar++;
       if(liar==x)return x;
     }
     return -1;
	}
};
