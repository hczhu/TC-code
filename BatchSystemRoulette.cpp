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
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<b;++i)
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
#define SZ(vec) ((int)(vec).size())
//#define All(vec) (vec).begin(),(vec).end()
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
class BatchSystemRoulette {
	public:
	 vector <double> expectedFinishTimes(vector <int> duration, vector <string> user) {
		 debug("Start calculation.");
     map<string,long long int> tot;
     Rep(i,SZ(duration)) {
       tot[user[i]]+=duration[i];
     }
     vector<double> res(SZ(user));
     Rep(i,SZ(duration)) {
       res[i]=0.5*duration[i];
       Rep(j,SZ(duration)) {
         if(tot[user[j]]==tot[user[i]])res[i]+=0.5*duration[j];
         else if(tot[user[i]]>tot[user[j]])res[i]+=duration[j];
       }
     }
     return res;
	}
};
