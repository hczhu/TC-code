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
class StonesGame {
  vector<int> expand(int x,int N,int K) {
    vector<int> res;
    for(int i=0;i+K<=N;i++) {
      if(i<=x&&x<i+K)res.push_back(i+i+K-1-x);
    }
    return res;
  }
	public:
	 string winner(int N, int M, int K, int L) {
		 debug("Start calculation.");
     bool second=true;
     M--;L--;
     vector<int> forward=expand(M,N,K);
     vector<int> backward=expand(L,N,K);
     sort(forward.begin(),forward.end());
     sort(backward.begin(),backward.end());
     if(find(forward.begin(),forward.end(),L)!=forward.end())return "Romeo";
     vector<int> diff;
     set_difference(forward.begin(),forward.end(),backward.begin(),backward.end(),inserter(diff,diff.begin()));
     return diff.empty()?"Strangelet":"Draw";
	}
};
