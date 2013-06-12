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
typedef long long int llint;
template<typename T>
llint _lcm(const vector<T>& number) {
  llint res=1;
  for(int i=0;i<number.size();i++) {
    res*=number[i]/__gcd(static_cast<llint>(number[i]),res);
  }
  return res;
}
class AllButOneDivisor {
	public:
	 int getMinimum(vector <int> divisors) {
		 debug("Start calculation.");
     int res=-1;
     for(int i=0;i<divisors.size();i++) {
       int tmp=1;
       swap(tmp,divisors[i]);
       llint lcm=_lcm(divisors);
       swap(tmp,divisors[i]);
       if((lcm%divisors[i])&&(res==-1||res>lcm))res=lcm;
     }
     return res;
	}
};
