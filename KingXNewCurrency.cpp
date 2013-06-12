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
//#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define debug(x)
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<(b);++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
bool bad[1000000];
int inv[211][210];
bool fea[1000000];
bool used[201];
class KingXNewCurrency {
 public:
  int howMany(int A, int B, int X) {
    debug("Start calculation.");
    int up_y = A*B + X -1;
    bool constrain=false;
    Rep(y, X+1)Rep(k, X+1) {
      int& ans = inv[y][(y*k)%X];
      if (ans == 0) ans = k;
    }
    Rep(a, A+1)Rep(b, B+1) {
      fea[a*B+b*A]=true;
    }
    int g=__gcd(A,B);
    Rep(i, X+1) fea[(A-1)*(B-1)+i]=true;
    Rep(i, (A-1)*(B-1)+X) if(fea[i]&&0==(i%g) ){
      const int a=i%X;
      if(a==0||used[a])continue;
      used[a]=true;
      up_y=min(up_y, i);
      constrain = true;
      debug(i);
      debug(a);
      For(y,1,up_y+1) {
        int k = inv[y%X][a];
        if (k==0 || y*k > i) {
          bad[y]=true;
          debug(y);
        }
      }
    }
    debug(up_y);
    return constrain?up_y - count(bad+1, bad+up_y + 1, true):-1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 5; int Arg3 = 5; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 13; int Arg3 = 1; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 44; int Arg3 = 2; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 96; int Arg2 = 3; int Arg3 = 65; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KingXNewCurrency ___test;
  ___test.run_test(1);
}
// END CUT HERE
