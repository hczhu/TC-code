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
llint GetMax(llint K, llint clear, const vector<int>& blur) {
  llint res= K * clear;
  llint pre = 0;
  const int n = SZ(blur);
  const llint sum = accumulate(All(blur), int(0));
  Rep(i, SZ(blur)) if(i <= K) {
    llint whole = (K - i) / n;
    llint t = max(whole * sum, n * clear * whole);
    res= max(res, pre + t + (K - whole * n - i) * clear);
    pre += blur[i];
  }
  cerr << K << " " << clear << "=" << res << endl;
  return res;
}

class BlurredDartboard {
 public:
  int minThrows(vector <int> pt, int P) {
    debug("Start calculation.");
    int clear = 0;
    const int N = SZ(pt);
    vector<bool> have(N + 1,false);
    Rep(i, N) {
      if (pt[i]) {
        clear = max(clear, pt[i]);
        have[pt[i]] = true;
      }
    }
    vector<int> blur;
    Rep(i, N) if (!have[i+1]) {
      blur.push_back(i+1);
    }
    debug(blur.size());
    if (blur.empty()) {
      return (P + clear - 1)/clear;
    }
    int low = 1, high = P;
    while(low < high) {
      int mid = (low + high) >> 1;
      if (GetMax(mid, clear, blur) >= P) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 3, 4, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 2; verify_case(0, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 5; verify_case(1, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 7, 8, 1, 3, 2, 6, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2012; int Arg2 = 252; verify_case(2, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2012; int Arg2 = 307; verify_case(3, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = 84656087; verify_case(4, Arg2, minThrows(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  BlurredDartboard ___test;
  ___test.run_test(-1);
  int P;
  cin >> P;
  vector<int> pt;
  int x;
  while(cin>>x) {
    pt.push_back(x);
  }
  BlurredDartboard board;
  cout << board.minThrows(pt, P) << endl;
}
// END CUT HERE
