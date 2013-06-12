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
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<(b);++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
#define Two(x) (1<<(x))
int dp[1<<16];
class FoxAndPhotography {
 public:
  int getMinimumSwaps(vector <int> h1, vector <int> h2) {
    debug("Start calculation.");
    const int n =SZ(h1);
    const int inf = 100000;
    fill(dp, dp+Two(n), inf);
    dp[0] = 0;
    Rep(mk, Two(n) - 1) {
      // cerr << mk << "=" << dp[mk] << endl;
      int pos = 0;
      Rep(i, n) if (mk&Two(i))++pos;
      const int h = h1[pos];
      int less = 0;
      Rep(i, n) if ( 0== (mk&Two(i))) {
        if (h2[i] > h) {
          dp[mk^Two(i)] = min(dp[mk^Two(i)], dp[mk] + pos - less);
        }
      } else {
        ++less;
      }
    }
    return dp[Two(n) - 1] >= inf ? -1:dp[Two(n) - 1];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {140, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {160, 150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {140, 140, 140, 140}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {190, 190, 190, 190}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {170, 170, 170}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {160, 170, 180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {140, 141, 142, 143}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {144, 143, 142, 141}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {140, 170, 140, 170, 140, 170, 140, 170, 140, 170}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {180, 180, 180, 180, 180, 150, 150, 150, 150, 150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(4, Arg2, getMinimumSwaps(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndPhotography ___test;
  ___test.run_test(-1);
}
// END CUT HERE
