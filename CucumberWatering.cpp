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
typedef long long int llint;
llint dp[100][100], cost[100][100];
class CucumberWatering {
 public:
  long long theMin(vector <int> x, int K) {
    debug("Start calculation.");
    const int n = SZ(x);
    typedef pair<int, int> pint;
    vector<pint> go;
    vector<llint> move;
    Rep(i, n - 1) {
      go.push_back(pint(min(x[i], x[i+1]), max(x[i], x[i+1])));
      move.push_back(go.back().second - go.back().first);
    }
    sort(All(x));
    Rep(j, n + 2) Rep(i, j - 1) {
      int e = x[j-2];
      int b = x[i];
      cerr<< b << "--->" << e << endl;
      llint& res = cost[i][j];
      res = 0;
#define IN(x) b<=(x) && (x) <= e
#define DIS(idx, xx) (((idx)>=1 && (idx)<=n) ? abs(xx - x[idx-1]): numeric_limits<int>::max())
      Rep(k, SZ(go)) {
        int x1 = go[k].first, x2 = go[k].second;
        bool in1 = IN(x1);
        bool in2 = IN(x2);
        llint d1 = min(DIS(i, x1), DIS(j, x1));
        llint d2 = min(DIS(i, x2), DIS(j, x2));
        if (in1 && in2) {
          res += min(move[k], d1 + d2);
        } else if (in1) {
          res += d1;
        } else if(in2) {
          res += d2;
        }
      }
      cerr<< i << " " << j << " with cost=" << res << endl;
    }
    K += 2;
    Rep(i, n + 2) {
      dp[2][i] = cost[0][i];
    }
    For(k, 3, K + 1) {
      llint* pre = dp[k-1];
      llint* next = dp[k];
      next[0] = 0;
      For(i, 1, n + 2) {
        next[i] = pre[i-1];
        Rep(j, i) {
          next[i] = min(next[i], pre[j] + cost[j][i]);
        }
      }
      debug(k);
      Rep(i, n + 2) cerr << next[i] << " "; cerr<<endl;
    }
    return dp[K][n+1];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 6, 8, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 6LL; verify_case(0, Arg2, theMin(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1000000000, 1000000000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 3000000000LL; verify_case(1, Arg2, theMin(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {58, 2012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; long long Arg2 = 0LL; verify_case(2, Arg2, theMin(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 58LL; verify_case(3, Arg2, theMin(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  CucumberWatering ___test;
  ___test.run_test(-1);
}
// END CUT HERE
