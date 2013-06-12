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
//INT_MAX INT_MIN
#include <limits.h>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define debug(x)
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<(b);++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
#define Two(x) ((1)<<(x))
typedef long long int llint;
llint table[2][1<<21];
void Enum(const string s, llint table[]) {
  debug(s);
  const int n = SZ(s);
  Rep(mk, Two(n - 1 )) {
    int red = 1, blue = 1;
    int lr = 0, lb = 0;
    Rep(i, n) {
      if (Two(i)&mk) {
        ++lr;
        red <<= 1; red ^= (s[i]=='x'?1:0);
      } else {
        ++lb;
        blue <<= 1; blue ^= (s[i]=='x'?1:0);
      }
    }
    if (lr < lb) {
      swap(lr, lb);
      swap(red, blue);
    }
    debug(mk);
    debug(red);
    debug(blue);
    const int low = Two(lr -lb) - 1;
    debug(((red & low) ^ (low + 1)));
    if ( (red^(blue << (lr -lb))) == (red & low)) {
      debug("Added");
      ++table[(red & low) ^ (low + 1)];
    }
  }
  debug("-------------------");
}
class SPartition {
 public:
  long long getCount(string s) {
    debug("Start calculation.");
    const int n = SZ(s);
    assert(0==(n&1));
    memset(table, 0, sizeof(table));
    Enum(s.substr(0, n/2), table[0]);
    reverse(All(s));
    Enum(s.substr(0, n/2), table[1]);
    llint ans = 0;
    Rep(a, Two(n/2 + 1)) if (table[0][a]){
      debug(a);
      debug(table[0][a]);
      int b = 1;
      for (int x = a; x>1; b<<=1, b ^= (x&1), x>>=1);
      debug(b);
      debug(table[1][b]);
      ans += (table[0][a] * table[1][b]) << (a==1?1:0);
    }
    return ans<<1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxox"; long long Arg1 = 2LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arg0 = "oooxxx"; long long Arg1 = 0LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arg0 = "xoxxox"; long long Arg1 = 4LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arg0 = "xo"; long long Arg1 = 0LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { string Arg0 = "ooooxoox"; long long Arg1 = 8LL; verify_case(4, Arg1, getCount(Arg0)); }
	void test_case_5() { string Arg0 = "ooxxoxox"; long long Arg1 = 8LL; verify_case(5, Arg1, getCount(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SPartition ___test;
  ___test.run_test(-1);
}
// END CUT HERE
