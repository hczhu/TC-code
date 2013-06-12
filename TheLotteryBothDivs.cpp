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
class TheLotteryBothDivs {
	public:
	 double find(vector <string> good) {
		 const int total=999999999+1;
		 debug("Start calculation.");
		 int ans=0;
		 for(int i=0;i<good.size();i++) {
			 bool take=true;
			 for(int j=0;j<good.size();j++) {
				 if(i==j)continue;
				 if(good[j]==good[i]&&j>i)take=false;
				 if(good[j].length()<good[i].length()&&
						 good[i].substr(good[i].length()-good[j].length())==good[j])take=false;
			 }
			 if(take) {
				 debug(good[i]);
				 int t=1;
				 for(int k=good[i].length();k<9;k++)t*=10;
				 debug(t);
				 ans+=t;
			 }
		 }
		 return 1.0*ans/total;
	}
};
