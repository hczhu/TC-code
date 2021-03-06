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
class ThreePoints {
 public:
  long long countColoring(int N, int xzero, int xmul, int xadd, int xmod, int yzero, int ymul, int yadd, int ymod) {
    debug("Start calculation.");
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 8; int Arg3 = 6; int Arg4 = 11; int Arg5 = 5; int Arg6 = 7; int Arg7 = 8; int Arg8 = 11; long long Arg9 = 8LL; verify_case(0, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 9; int Arg2 = 6; int Arg3 = 8; int Arg4 = 10; int Arg5 = 4; int Arg6 = 8; int Arg7 = 5; int Arg8 = 10; long long Arg9 = 2LL; verify_case(1, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 3; int Arg3 = 71; int Arg4 = 100; int Arg5 = 78; int Arg6 = 12; int Arg7 = 50; int Arg8 = 100; long long Arg9 = 263LL; verify_case(2, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 300000; int Arg1 = 99097861; int Arg2 = 102766912; int Arg3 = 95284952; int Arg4 = 123456789; int Arg5 = 443104491; int Arg6 = 971853214; int Arg7 = 569775557; int Arg8 = 987654321; long long Arg9 = 749410681185726LL; verify_case(3, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ThreePoints ___test;
  ___test.run_test(-1);
}
// END CUT HERE
