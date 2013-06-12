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

int SwapOne(const vector<bool>& color, int S) {
  int res = 0;
  Rep(i, SZ(color)) if (color[i]) {
    int t = 1;
    vector<int> dis;
    for(int j = i + 1 , d= 0; j < SZ(color); ++j) {
      if (!color[j]) {
        ++d;
      } else {
        dis.push_back(d);
      }
    }
    for(int j = i - 1 , d= 0; j >=0 ; --j) {
      if (!color[j]) {
        ++d;
      } else {
        dis.push_back(d);
      }
    }
    sort(All(dis));
    for (int j = 0, s= 0; j < SZ(dis) && s <=S; ++j) {
      if (dis[j] + s <= S) {
        s += dis[j];
        ++t;
      }
    }
    res=max(res, t);
  }
  return res;
}
class ColorfulChocolates {
 public:
  int maximumSpread(string ch, int S) {
    debug("Start calculation.");
    int res = 0;
    Rep(i, SZ(ch)) {
      char c = ch[i];
      vector<bool> color(SZ(ch), false);
      Rep(j, SZ(ch)) {
        color[j] = c == ch[j];
      }
      res=max(res, SwapOne(color, S));
      // debug(ch);
      // debug(res);
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDCBC"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDCBC"; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABBABABBA"; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABBABABBA"; int Arg1 = 4; int Arg2 = 5; verify_case(3, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"; int Arg1 = 77; int Arg2 = 5; verify_case(4, Arg2, maximumSpread(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ColorfulChocolates ___test;
  ___test.run_test(-1);
}
// END CUT HERE
