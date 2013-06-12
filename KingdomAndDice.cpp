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

int RangeCount(const vector<int>& all, int a, int b) {
  int res = 0;
  Rep(i, SZ(all)) {
    if ( a <= all[i] && all[i] <= b) {
      ++res;
    }
  }
  return res;
}
bool dp[51][2501];
class KingdomAndDice {
 public:
  double newFairness(vector <int> first, vector <int> second, int X) {
    debug("Start calculation.");
    const int n = SZ(first);
    sort(All(second));
    vector<int> smaller(n+1, 0);
    smaller[0] = n;
    second.push_back(X + 1);
    Rep(i, n) {
      smaller[i + 1] = second[i+1] - second[i] - 1 - RangeCount(first, second[i] + 1, second[i+1]-1);
      cerr << i+1 << " smaller = " << smaller[i+1] << endl;
    }
    int sum = 0;
    int m = 0;
    Rep(i, SZ(first)) {
      if (first[i] == 0) {
        ++m;
      } else {
        sum += RangeCount(second, 1, first[i] - 1);
        debug(i);
        debug(first[i]);
        debug(sum);
      }
    }
    memset(dp, false, sizeof(dp));
    dp[0][0]= true;
    Rep(i, SZ(smaller)) {
      int cnt = smaller[i];
      for (int k = m -1; k >=0; k--) {
        for (int s = n*n; s>=0 ;s--) {
          if (dp[k][s]) {
            for (int x = 1; x<=cnt && x + k <=m; ++x) {
              dp[x+k][i+s] = true;
            }
          }
        }
      }
    }
    int ans = sum;
    Rep(s, n*n + 1) if (dp[m][s]) {
      cerr << m << " " << s <<endl;
      if (abs((s+sum) * 2 - n*n) < abs(ans*2 - n*n)) {
        ans = sum + s;
      }
    }
    debug(ans);
    return 1.0 * ans / (n*n);
  }
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 2, 7, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 3, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; double Arg3 = 0.4375; verify_case(0, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 2, 7, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 3, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; double Arg3 = 0.375; verify_case(1, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; double Arg3 = 0.5; verify_case(2, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {19, 50, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {26, 100, 37}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = 0.2222222222222222; verify_case(3, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; double Arg3 = 0.49; verify_case(4, Arg3, newFairness(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KingdomAndDice ___test;
  ___test.run_test(-1);
}
// END CUT HERE
