#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;

//The most common functions
typedef long long int llint;
typedef unsigned long long int ullint;

//calculate Sum{ (A*i + B)/M |  0 <= i <=C   }
// A and B may be negative.  M > 0
// The algorithm is to transform the summation to Sum{Count( (A*i +B)/M>=k )|1<=k}
llint floorSummation(llint A,llint B,llint C,llint M) {
  assert(M>0);
  if(C<0) return 0;
  llint res=(A/M)*(C*(C+1)/2);A%=M;
  res+=(C+1)*(B/M);B%=M;
  if(A<0) {
    res-=C*(C+1)/2;
    A+=M;
  }
  if(B<0) {
    res-=C+1;
    B+=M;
  }
  if(A==0) return (C+1)*(B/M)+res;
  assert(A>0);
  assert(B>=0);
  const llint upper=(A*C+B)/M;
  res+=(C+1)*upper-floorSummation(M,M+A-1-B,upper-1,A);
  return res;
}
class ModuleSequence {
 public:
  llint countElements(llint K,llint N,llint A,llint B,llint lower,llint upper) {
    // lower<=(X%N)<=upper <==> (X-lower)/N - (X-upper-1)/N = 1  
    //  #[lower<=(X%N)<=upper] <==>  Sum{ (X-lower)/N - (X-upper-1)/N }
    K%=N;
    return floorSummation(K,-lower,B,N)-floorSummation(K,-lower,A-1,N)-
        (floorSummation(K,-upper-1,B,N)-floorSummation(K,-upper-1,A-1,N));
  };
};
/*
int main() {
  llint K,N,A,B,lower,upper;
  while(cin>>K>>N>>A>>B>>lower>>upper) {
    ModuleSequence mm;
    cout<<mm.countElements(K,N,A,B,lower,upper)<<endl;
  }
  return 0;
}
*/
