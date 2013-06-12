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
// sum of {1^1,2^2,3^2,...,n^2}
double seq2(int n) {
  return n>0?1.0*n*(n+1)*(2*n+1)/6:0;
}
// Sum{a^2,(a+1)^2,...,b^2}
double sum2(int a,int b) {
  if(a>b)return 0;
  return seq2(b)-seq2(a-1);
}
//Sum{a,a+1,...,b}
double sum1(int a,int b) {
  if(a>b)return 0.0;
  return 1.0*(a+b)*(b-a+1)/2.0;
}
// Sum{  max(0,y-x) |  a<=x<=b && c<=y<=d }
double interval_delta_sum(int a,int b,int c,int d) {
  double ans=0.0;
  int cb=min(c-1,b);
  if(a<=cb) {
    ans+=1.0*(c+d)*(d-c+1)*(cb-a+1)/2.0-(d-c+1)*sum1(a,cb);
  }
  int ac=max(a,c);
  int bd=min(b,d);
  if(ac<=bd) {
    ans+=(sum2(d-bd,d-ac)+sum1(d-bd,d-ac))/2.0;
  }
  //ans/=1.0*(b-a+1)*(d-c+1);
  //cerr<<a<<" "<<b<<","<<c<<" "<<d<<"="<<ans<<endl;
  return ans;
}
class AlternatingLane {
	public:
	 double expectedBeauty(vector <int> low, vector <int> high) {
		 debug("Start calculation.");
     const int n=low.size();
     double ans=0.0;
     for(int i=0;i<n;i++)
     for(int j=i+1;j<i+2&&j<n;j++) {
       int a=low[i],b=high[i];
       int c=low[j],d=high[j];
       double de=1.0*(b-a+1)*(d-c+1);
       ans+=interval_delta_sum(a,b,c,d)/de;
       ans+=interval_delta_sum(-b,-a,-d,-c)/de;
       debug(i);
       debug(j);
       debug(ans);
     }
     return ans;
	}
};
