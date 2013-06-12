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
#define Low(x) (((x)^((x)-1))&(x))
typedef long long int llint;
bool AddMatch(vector<int>& have, int add) {
  for (int i = 0; add && i < SZ(have); ++i) {
    if (Low(add) == Low(have[i])) {
      add ^= have[i];
    }
  }
  if (add) {
    have.push_back(add);
    for (int i = SZ(have)-1; i && Low(have[i]) < Low(have[i-1]); --i) {
      swap(have[i], have[i-1]);
    }
  }
  return add;
}

struct Pile {
  int matches, red, blue;
  Pile(int a,int b, int c) : matches(a), red(b), blue(c) {}
};

class MyLess {
  public:
    MyLess(double x) : x_(x) {}
    bool operator()(const Pile& a, const Pile& b) {
      return a.red + x_ *a.blue < b.red + x_ * b.blue;
    }
  private:
    double x_;
};

int diamonds = -1;
llint solveOne(const vector<Pile>& piles) {
  vector<int> have;
  llint red_sum = 0, blue_sum = 0;
  Rep(i, SZ(piles)) {
    if (AddMatch(have, piles[i].matches)) {
      red_sum += piles[i].red;
      blue_sum += piles[i].blue;
    }
  }
  //debug(diamonds);
  //debug(SZ(have));
  assert(diamonds == -1 || diamonds == SZ(have));
  diamonds = SZ(have);
  return red_sum * blue_sum;
}

class MagicMatchesGame {
 public:
  long long minimumArea(vector <int> matches, vector <int> red, vector <int> blue) {
    debug("Start calculation.");
    const int n = SZ(matches);
    // r1 + b1 * x = r2 + b2 * x
    vector<double> cutoff;
    Rep(i,n)For(j, i+1, n) if((red[i]-red[j])*(blue[j]-blue[i])>0) {
      cutoff.push_back(1.0*(red[i]-red[j])/(blue[j]-blue[i]));
    }
    debug(SZ(cutoff));
    sort(All(cutoff));
    vector<double> values;
    values.push_back(0);
    For(i, 1, SZ(cutoff)) {
      values.push_back((cutoff[i-1]+cutoff[i])/2);
    }
    values.push_back(1000000.0);
    debug(SZ(values));
    vector<Pile> piles;
    Rep(i, n) piles.push_back(Pile(matches[i], red[i], blue[i]));
    llint ans = numeric_limits<llint>::max();
    diamonds = -1;
    Rep(i, SZ(values)) {
      //debug(values[i]);
      sort(All(piles), MyLess(values[i]));
      ans = min(ans, solveOne(piles));
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 24LL; verify_case(0, Arg3, minimumArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9,8,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 153LL; verify_case(1, Arg3, minimumArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,11,12,23,21,52,65}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {23,10,31,18,13,10,13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2255LL; verify_case(2, Arg3, minimumArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1037, 2220, 6908, 4179, 4243, 4396, 679, 179, 163, 818, 9767, 5199, 3973, 2065, 8060}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {724, 123, 178, 262, 628, 981, 882, 814, 752, 495, 906, 904, 265, 329, 470}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {664, 134, 254, 798, 290, 753, 941, 264, 200, 369, 547, 628, 120, 833, 928}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 42628758LL; verify_case(3, Arg3, minimumArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10095, 16913, 10198, 12528, 15264, 19224, 16442, 14595, 12060, 11858, 17900, 19304, 10619, 15818, 11670}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9419, 9448, 9722, 9030, 9591, 9451, 9871, 9124, 9012, 9047, 9024, 9984, 9163, 9852, 9203}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9706, 9436, 9454, 9585, 9592, 9145, 9356, 9797, 9523, 9032, 9178, 9472, 9594, 9637, 9256}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 17324432487LL; verify_case(4, Arg3, minimumArea(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 100000000LL; verify_case(5, Arg3, minimumArea(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MagicMatchesGame ___test;
  ___test.run_test(-1);
}
// END CUT HERE
