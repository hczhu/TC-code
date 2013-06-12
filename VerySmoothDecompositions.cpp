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
const int B=10000;
void Divide(vector<int>& num, int d, int& rem) {
  rem=0;
  for(int i=SZ(num)-1;i>=0;i--) {
    num[i]+=B*rem;
    rem=num[i]%d;
    num[i]/=d;
  }
  while(SZ(num)>1&&num.back()==0)num.pop_back();
}
class VerySmoothDecompositions {
 public:
  int solve(vector <string> digits) {
    debug("Start calculation.");
    string all=accumulate(All(digits),string(""));
    vector<int> num;
    debug(all);
    for(int i=SZ(all)-4;i+3>=0;i-=4) {
      int t=0;
      Rep(j,4)if(i+j>=0)t=t*10+(all[i+j]-'0');
      num.push_back(t);
      debug(t);
    }
    const int prime[]={2,3,5,7,11,13};
    const int P=6;
    int pcnt[P]={0};
    Rep(i,P) {
      for(;;) {
        int rem=0;
        const vector<int> org=num;
        Divide(num,prime[i],rem);
        if(rem) {
          num=org;
          break;
        }
        pcnt[i]++;
      }
      debug(pcnt[i]);
    }
    if(SZ(num)>1||num[0]!=1) return 0;

    return 1;
  } 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"36"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arr0[] = {"1","21"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { string Arr0[] = {"1024"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(5, Arg1, solve(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  VerySmoothDecompositions ___test;
  ___test.run_test(-1);
}
// END CUT HERE
