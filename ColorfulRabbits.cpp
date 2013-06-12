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
#define SZ(vec) ((int)(vec).size())
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
class ColorfulRabbits {
	public:
	 int getMinimum(vector <int> replies) {
		 debug("Start calculation.");
     map<int,int> mem;
     for(int i=0;i<SZ(replies);i++) {
       mem[replies[i]]++;
     }
     int ans=0;
     for(map<int,int>::iterator itr=mem.begin();itr!=mem.end();++itr) {
       int n=itr->first;
       int x=itr->second;
       ans+=(x+n)/(n+1)*(n+1);
       debug(ans);
       debug(n);
     }
     return ans;
	}
};
