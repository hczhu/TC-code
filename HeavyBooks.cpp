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
typedef pair<int, int> pii;
pii dp[51][51];
bool Better(const pii& a, const pii& b) {
  if (a.first -a. second != b.first -b.second) {
    return a.first - a. second < b.first - b.second;
  }
  return a.first + a.second  > b.first + b.second;
}
class HeavyBooks {
 public:
  vector <int> findWeight(vector <int> books, vector <int> moves) {
    debug("Start calculation.");
    moves.resize(6);
    moves[0]= 8;
    const int m = SZ(moves);
    const int n = SZ(books);
    srand(time(NULL));
    Rep(i, m - 1) moves[i+1] = rand() %  (1 +moves[0]);
    For(i, 2, m) if (moves[i] > moves[i-1] && moves[i-1] > moves[i-2])
      moves[i]=moves[i-1];
    vector<int> have[2];
    have[1].resize(moves[0]);
    Rep(i, SZ(have[1]))have[1][i] = i;
    Rep(i, SZ(moves)) {
      vector<int>& from = have[i&1];
      vector<int>& to = have[(i&1)^1];
      for (int j = 0; j < moves[i] && from.size(); ++j) {
        to.push_back(from.back());
        from.pop_back();
      }
      sort(All(to));
    }
    Rep(i, SZ(have[0]))cerr<<have[0][i] << " "; cerr<<endl;
    Rep(i, SZ(have[1]))cerr<<have[1][i] << " "; cerr<<endl;
    int sum[2] = {0,0};
    sum[1] = moves[0];
    sort(All(books),greater<int>());
    for (int i = 1; i < m; ++i) {
      moves[i] = min(moves[i], sum[i&1]);
      sum[i&1] -= moves[i];
      sum[(i&1)^1] += moves[i];
    }
    Rep(i, m) cerr<<moves[i] <<" ";cerr<<endl;
    for(;;) {
      bool f=false;
      for (int i = m - 1; i - 2 > 0; --i) {
        if (moves[i] > moves[i-1]) {
          int d = moves[i] - moves[i-1];
          moves[i-2] += d;
          moves[i] -= d;
          f=true;
        }
      }
      if (!f) break;
    }
    Rep(i, m) cerr<<moves[i] <<" ";cerr<<endl;
    vector<int> belong(moves[0]);
    moves.push_back(0);
    int last = 0;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = moves[i + 1]; j < moves[i]; ++j) {
        belong[last++] = (i&1) ^ 1;
      }
    }
    debug(last);
    debug(SZ(belong));
    assert(last == SZ(belong));
    Rep(i, SZ(have[0]))assert(belong[moves[0]- 1 -have[0][i]] == 0);
    Rep(i, SZ(have[1]))assert(belong[moves[0]- 1- have[1][i]] == 1);
    Rep(i, SZ(have[0]))belong[moves[0]- 1 -have[0][i]] = 0;
    Rep(i, SZ(have[1]))belong[moves[0]- 1- have[1][i]] = 1;
    Rep(i, SZ(belong)) cerr << belong[i] << " "; cerr<<endl;
    for(int k =1; k <= n; ++k) {
      pii *pre = dp[k - 1];
      pii *cur = dp[k];
      for (int i = 1; i <= k && i <= moves[0]; ++i) {
        cur[i] = pii(pre[i-1].first + books[k-1] * (belong[i-1]^1),
            pre[i-1].second + books[k-1]*belong[i-1]);
        if (i < k && Better(pre[i], cur[i])) {
          cur[i] = pre[i];
        }
      }
      cerr<< k<< "=" <<cur[k].first << "," << cur[k].second <<endl;
    }
    vector<int> res(2);
    res[0] = dp[n][moves[0]].first;
    res[1] = dp[n][moves[0]].second;
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {5,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findWeight(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 100, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {110, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findWeight(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {155870,565381}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 565381 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findWeight(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {500,500,500,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1,1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {500, 1500 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findWeight(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1000000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findWeight(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {110, 100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, findWeight(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  HeavyBooks ___test;
  ___test.run_test(-1);
}
// END CUT HERE
