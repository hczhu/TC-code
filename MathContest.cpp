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
/*********************************
 Tips
 * Binary search
 * Ternary search
 * Bitwise tricks
 * Bipartite matching
 * Graph algorithms
 * DP
 * Subset DP
 * Greedy algorithms
 * Network flow
 * Construct the solution directly
 * Be careful to the input constraints
 * Corner cases.
**********************************/
class MathContest {
	public:
	 int countBlack(string ball, int rep) {
		 debug("Start calculation.");
		 string all;
		 for(int i=0;i<rep;i++) {
			 all+=ball;
		 }
		 int a=0,b=all.length()-1;
		 bool color=false;
		 bool order=false;
		 int ans=0;
		 while(a<=b) {
			 char c;
			 if(order)c=all[b--];
			 else c=all[a++];
			 if(color)c=(c=='W')?'B':'W';
			 if(c=='W')order=!order;
			 else color=!color;
			 if(c=='B')ans++;
		 }
		 return ans;
	}
};
