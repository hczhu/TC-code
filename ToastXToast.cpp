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
class ToastXToast {
	public:
	 int bake(vector <int> X, vector <int> Y) {
		 debug("Start calculation.");
		 int a1=*min_element(X.begin(),X.end());
		 int b1=*max_element(X.begin(),X.end());
		 int a2=*min_element(Y.begin(),Y.end());
		 int b2=*max_element(Y.begin(),Y.end());
		 if(b1<a2)return 1;
		 if(a2<a1||b1>b2)return -1;
		 return 2;
	}
};
