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
const int maxn = 1<<20;
double d[2][maxn];
double hyp(double dx, double dy) {
  return sqrt(dx*dx+dy*dy);
}
double wrong(int l, int walk, vector<int> width, vector<int> speed) {
  int n =SZ(width);
  memset(d, 0, sizeof(d));
  int fr = 0;
  int ba =1;
  for (int i =0; i<= l; ++i) {
    d[fr][i] = i / double(walk);
  }
  for (int i = 0; i< n; ++i) {
    swap(fr, ba);
    int k =0;
    for (int j =0; j<=l; ++j) {
      for (;;) {
        double next = 1e30;
        if(k+1<=l) {
          next = d[ba][k+1]+hyp(j-k-1, width[i]) / double(speed[i]);
        }
        double cur = d[ba][k] + hyp(j-k, width[i]) / double(speed[i]);
        if (next <= cur) {
          k++;
          continue;
        }
        d[fr][j] = cur;
        break;
      }
    }
  }
  return d[fr][l];
}
class EllysRivers {
 public:
   int VSP(int idx, const vector<int>& speed, int walk) {
     if (idx < SZ(speed)) walk= max(walk, speed[idx]);
     if (idx) walk =max(walk, speed[idx-1]);
     return walk;
   }
   inline double Dis(int wid, int vd) {
     return sqrt(1.0 *wid * wid + 1.0*vd * vd);
   }
  double getMin(int m, int walk, vector <int> width, vector <int> speed) {
    // const double ans = wrong(m, walk, width, speed);
    debug("Start calculation.");
    vector<double> pre(m+1) ,next(m+1);
    const int n = SZ(speed) + 1;
    vector<int> vsp(n);
    Rep(i, n) vsp[i] = VSP(i, speed, walk);
    Rep(i, SZ(pre)) {
      pre[i] = 1.0 * i / vsp[0];
    }
    Rep(i, n - 1) {
      int last = 0;
      double rsp = 1.0 / speed[i];
      double rvp = 1.0 / vsp[i+1];
      Rep(x, m + 1) {
        next[x] = 1e30;
        double a=pre[last] + Dis(width[i], x - last)  *rsp;
        double b;
        while(last < x &&  a >= (b=pre[last + 1] + Dis(width[i], x- last -1) *rsp)) {
          last++;
          a= b;
        }
        for (int j = 0; j + last <= x && j < 1; ++j) {
          next[x] = min(next[x], pre[last + j] + Dis(width[i], x -last - j) * rsp);
        }
        if (x) next[x]=min(next[x], next[x-1] + rvp);
      }
      pre.swap(next);
    }
    printf("%.10lf\n", pre[m]);
    /*printf("%.10lf %.10lf\n", pre[m], ans);
    if (fabs(pre[m] - ans) > 1e-9) {
      assert(0);
    }*/
    return pre[m];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1e-10) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {5, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 2, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.231651964071508; verify_case(0, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10000; int Arg1 = 211; int Arr2[] = {911}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {207}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 48.24623664712219; verify_case(1, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1337; int Arg1 = 2; int Arr2[] = {100, 200, 300, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11, 12, 13, 14}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 128.57830549575695; verify_case(2, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 77; int Arg1 = 119; int Arr2[] = {11, 12, 13, 14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100, 200, 300, 400}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.3842077071089629; verify_case(3, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7134; int Arg1 = 1525; int Arr2[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 214.6509731258811; verify_case(4, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  EllysRivers ___test;
  ___test.run_test(-1);
}
// END CUT HERE
