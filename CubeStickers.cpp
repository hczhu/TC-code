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
#include <iterator>
#include <valarray>
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
class CubeStickers {
	public:
	 string isPossible(vector <string> color) {
		 debug("Start calculation.");
     map<string,int> mem;
     for(int i=0;i<color.size();i++)mem[color[i]]++;
     int cnt=0;
     for(int i=0;i<color.size();i++) {
       if(mem[color[i]]==0)continue;
       cnt++;
       if(--mem[color[i]]>1)mem[color[i]]=1;
     }
     return cnt>=6?"YES":"NO";
	}
};
