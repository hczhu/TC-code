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
typedef long long int llint;
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
template<typename T>
llint _lcm(const vector<T>& number) {
  llint res=1;
  for(int i=0;i<number.size();i++) {
    res*=number[i]/__gcd(number[i],res);
  }
  return res;
}
template<typename T>
T __gcd(T n,T m,T& a,T& b)
{
	T a1=0,b1=1;
	a=1,b=0;
	// a*n+b*m=n';  a1*n+b1*m=m';
	//(n',m') keeps changing.
	while(m)
	{
		T c=n/m;
		T r=n-m*c;
		T t;
		t=a;a=a1;a1=t-c*a1;
		t=b;b=b1;b1=t-c*b1;
		n=m;m=r;
	}
	return n;
}

//
template<typename T>
llint solveModuleEquations(vector<T> aa,vector<T> mm) {
  const int n=aa.size();
	llint gg,xx,yy;
	for(int i=1;i<n;i++)
	{
		gg=__gcd(mm[0],mm[i],xx,yy);
		if((aa[i]-aa[0])%gg)return -1;
		xx*=(aa[i]-aa[0])/gg;
		mm[i]/=gg;
		xx=((xx%mm[i])+mm[i])%mm[i];
		aa[0]=mm[0]*xx+aa[0];
		mm[0]*=mm[i];aa[0]%=mm[0];
	}
	return aa[0];
}
#define Two(x) ((1)<<(x))
llint count(llint n) {
  if(n==0)return 0;
  llint ans=0;
  for(int mk=1;mk<Two(9);mk++) {
    vector<llint> aa,mm;
    for(int r=1;r<=9;r++) {
      if(0==(mk&Two(r-1)))continue;
      mm.push_back(9*r);
      aa.push_back(r*r%mm.back());
    }
    llint t=solveModuleEquations(aa,mm);
    if(t==-1)continue;
    llint lcm=_lcm(mm);
    debug(t);
    debug(lcm);
    assert(t<lcm);
    llint add=0;
    add+=n/lcm;
    if((n%lcm)>=t)add++;
    if(t==0)add--;
    debug(add);
    ans+=(aa.size()&1)?add:-add;
  }
  cerr<<n<<"="<<ans<<endl;
  return ans;
}
class FoxIntegerLevelThree {
	public:
	 long long count(long long min, long long max) {
		 debug("Start calculation.");
     return ::count(max)-::count(min-1);
	}
};
