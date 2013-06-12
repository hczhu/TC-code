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
#define Two(x) (((llint)1)<<(x))
map<llint, double> cache[51];
llint getPerm(llint mk, const vector<int>& perm, int n) {
  llint res = 0;
  Rep(i, n) {
    if (mk&Two(i)) res ^=Two(perm[i]);
  }
  return res;
}
double DP(llint mk, llint Xor, const vector<int>& perm, int k, int n) {
  if (k==0) return  (mk&1);
  if (cache[k].count(mk)) return cache[k][mk];
  double res = 0.5 * DP(getPerm(mk, perm, n), Xor,perm,  k-1, n) +
    0.5 * DP(mk^Xor, Xor,perm,  k-1, n);
  cache[k][mk]=res;
  return res;
}
double solve(llint mk, vector<int> perm, llint Xor, int K) {
  const int n=SZ(perm);
  Rep(i, 51) cache[i].clear();
  double res = DP(mk, Xor, perm, K, n);
  // debug(res);
  // Rep(i, 51) cerr<<i<<"="<<cache[i].size() << endl;
  return res;
}

class KingXMagicSpells {
 public:
  double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
    debug("Start calculation.");
    double res = 0;
    const int n =SZ(ducks);
    Rep(i, 31) {
      llint mk = 0, Xor = 0;
      Rep(j, n) {
        if(ducks[j]&Two(i)) {
          mk^=Two(j);
        }
        if(spellOne[j]&Two(i)) {
          Xor ^= Two(j);
        }
      }
      if (mk==0 && Xor == 0) continue;
      //debug(mk);
      //debug(Xor);
      res += solve(mk, spellTwo, Xor, K) * Two(i);
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; double Arg4 = 3.5; verify_case(0, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {53, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 21.5; verify_case(1, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {123, 456, 789, 1234, 56789}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; double Arg4 = 123.0; verify_case(2, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 37, 44, 66, 72, 19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 1, 5, 4, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 11; double Arg4 = 2.888186784716797E7; verify_case(3, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KingXMagicSpells ___test;
  ___test.run_test(-1);
}
// END CUT HERE
