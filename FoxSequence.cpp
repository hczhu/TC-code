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
#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Back(str) (str)[(str).length()-1]
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
class FoxSequence {
	public:
    int check(const vector<int>& seq,int a,int b) {
      if(a==b)return 0;
      int res=seq[a+1]-seq[a];
      for(int i=a+2;i<=b;i++) {
        if(seq[i]-seq[i-1]!=res)return 0;
      }
      return res;
    }
	 string isValid(vector <int> seq) {
		 debug("Start calculation.");
     const int n=SZ(seq);
     for(int a=1;a<n;a++)
     for(int b=a+1;b<n;b++)
     for(int c=b;c<n;c++)
     for(int d=c+1;d<n;d++) {
       if(
           check(seq,0,a)>0&&
           check(seq,a,b)<0&&
           *max_element(seq.begin()+b,seq.begin()+c+1)==*min_element(seq.begin()+b,seq.begin()+c+1)&&
           check(seq,c,d)>0&&
           check(seq,d,n-1)<0
           )
         return "YES";
     }
     return "NO";
	}
};
