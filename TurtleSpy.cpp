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
bool dp[2][360];
class TurtleSpy {
 public:
  double maxDistance(vector <string> com) {
    debug("Start calculation.");
    int forward = 0, backward = 0;
    vector<int> rotate;
    Rep(i, SZ(com)) {
      istringstream is(com[i]);
      string op;
      int v;
      is >> op >> v;
      debug(op);
      debug(v);
      if ("forward" == op) {
        forward += v;
      } else if("backward" == op) {
        backward += v;
      } else if ("right" == op) {
        rotate.push_back(v);
      } else {
        rotate.push_back(360 - v);
      }
    }
    debug(SZ(rotate));
    bool *pre = dp[0];
    bool *next=dp[1];
    memset(pre, false, sizeof(next[0]) * 360);
    pre[0]=true;
    Rep(i, SZ(rotate)) {
      memset(next, false, sizeof(next[0]) * 360);
      int add = rotate[i];
      Rep(j, 360) if (pre[j]) {
        next[j] = true;
        next[(j+add)%360]=true;
      }
      swap(next, pre);
    }
    double ans = abs(forward - backward);
    const double PI = acos(-1.0);
    Rep(i, 360) if (pre[i]) {
      debug(i);
      double th=1.0*i/180.0*PI;
      debug(th);
      double v=sqrt(forward*forward + backward*backward - 2.0 * forward * backward * cos(th));
      debug(v);
      ans = max(ans, v);
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"forward 100", "backward 100", "left 90" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 141.4213562373095; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 40.58520737741619; verify_case(2, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TurtleSpy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
