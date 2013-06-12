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
class YetAnotherHamiltonianPath {
	public:
    int prefix(int i,int j,const vector<string>& label) {
      int p=0;
      while(label[i].length()>p&&label[j].length()>p&&label[i][p]==label[j][p])p++;
      return p;
    }
	 int leastCost(vector <string> label) {
		 debug("Start calculation.");
     int ans=0;
     for(int i=0;i<label.size();i++) {
#define SQ(x) ((x)*(x))
       ans+=(i<2?1:2)*SQ(label[i].length());
     }
     ans+=SQ(prefix(0,1,label));
     sort(label.begin(),label.end());
     for(int i=0;i<label.size();i++) {
       int p=prefix(i,(i+1)%label.size(),label);
       ans-=p*p;
     }
     return ans;
	}
};
