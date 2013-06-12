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
class TheJackpotDivOne {
	public:
	 vector<long long> find(vector<long long> money, long long jackpot) {
		 debug("Start calculation.");
	}
};
typedef long long int llint;
int main() {
  srand(time(NULL));
  int n;
  //cin>>n;
  n=50;
  vector<llint> num(n);
  //for(int i=0;i<n;i++)cin>>num[i];
  for(int i=0;i<n;i++)num[i]=(llint)(rand()%100000000)*(llint)(rand()%10000000);
  for(int i=0;i<n/2;i++)num[i]=rand()%10000;
  //llint x=num[0];
  //for(int i=0;i<n;i++)num[i]-=x;
  llint out=0;
  int cnt=0;
  for(;out<100000000000000000LL;cnt++) {
    sort(num.begin(),num.end());
    if(0==(cnt%10000)) {
      debug(cnt);
      debug(num[0]);
      debug(num.back());
    }
    if(num[0]==num.back())break;
    llint s=accumulate(num.begin(),num.end(),llint(0));
    out+=(s+n)/n-num[0];
    //debug(out);
    num[0]=(s+n)/n;
    //sort(num.begin(),num.end());
    //debug((s+n)/n);
    //x=num[0];
    //for(int i=0;i<n;i++)num[i]-=x;

    //for(int i=0;i<n;i++)cout<<num[i]<<" ";cout<<endl;
  }
  debug(out);
  debug(cnt);
  return 0;
}
