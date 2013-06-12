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
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
//#define SZ(vec) ((int)(vec).size())
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
class CubePacking {
	public:
	 int getMinimumVolume(int Ns, int Nb, int L) {
		 debug("Start calculation.");
     for(llint add=0;add<L*L;add++) {
       llint s=Ns+(llint)L*(llint)L*(llint)L*(llint)Nb+add;
       debug(s);
       for(llint x=1;x*x*x<=s;x++)if(0==(s%x))
       for(llint y=x;x*y*y<=s;y++)if(0==(s/x%y)) {
         llint z=s/x/y;
         if((x/L)*(y/L)*(z/L)>=Nb) {
           debug(add);
           return s;
         }
       }
     }
     assert(0);
     return -1;
	}
};

/*
int main() {
  int a,b,c;
  //cin>>a>>b>>c;
  a=167730;
  b=869019;
  c=2;
  CubePacking cube;
  cout<<cube.getMinimumVolume(a,b,c)<<endl;
}
*/
