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
#define All(vec) (vec).begin(),(vec).end()
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
class InternetSecurity {
	public:
	 vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold) {
		 debug("Start calculation.");
     set<string> mem(All(dangerous));
     debug(mem.size());
     vector<vector<string> > all;
     Rep(i,SZ(address)) {
       istringstream is(keyword[i]);
       string word;
       all.push_back(vector<string>());
       while(is>>word) {
         all.back().push_back(word);
       }
       debug(all.back().size());
     }
     debug(all.size());
     set<int> who;
     bool go=true;
     for(;go;) {
       go=false;
       Rep(i,SZ(all)) {
         if(who.count(i))continue;
         if(all[i].empty())continue;
         int cnt=0;
         Rep(j,SZ(all[i])) {
           if(mem.count(all[i][j]))cnt++;
         }
         if(cnt>=threshold) {
           go=true;
           Rep(j,SZ(all[i])) {
             mem.insert(all[i][j]);
           }
           all[i].clear();
           who.insert(i);
         }
       }
     }
     vector<string> res;
     Rep(i,SZ(address)) {
       if(who.count(i))res.push_back(address[i]);
     }
     return res;
	}
};
