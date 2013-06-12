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
#define Two(x)  (((llint)1)<<(x))
set<llint> gAll;
typedef pair<int,int> pii;
map<pii,int> point2idx;


void solve(vector<pii> all,int nlow,int nhigh) {
  vector<int> left_bound, right_bound;
  Rep(i,SZ(all)) {
    int y=all[i].second;
    left_bound.push_back(y);
    left_bound.push_back(y+1);
    left_bound.push_back(y-nlow);
    left_bound.push_back(y-1-nlow);

    right_bound.push_back(y);
    right_bound.push_back(y-1);
    right_bound.push_back(y+nlow);
    right_bound.push_back(y+nlow+1);
  }
  sort(All(left_bound));
  sort(All(right_bound));
  left_bound.resize(unique(All(left_bound))-left_bound.begin());
  right_bound.resize(unique(All(right_bound))-right_bound.begin());
  debug(left_bound.size());
  debug(right_bound.size());
  Rep(ll, SZ(left_bound)) Rep(rr, SZ(right_bound)) {
    int y1=left_bound[ll];
    int y2=right_bound[rr];
    if (y2-y1>=nlow && y2-y1<=nhigh) {
      vector<pii> subset;
      Rep(i,SZ(all)) {
        if (y1<=all[i].second && all[i].second<=y2) {
          subset.push_back(all[i]);
        }
      }
      int side=y2-y1;
      //cerr<<y1<<"-->"<<y2<<" "<<subset.size()<<endl;
      sort(All(subset));
      llint mask = 0;
      int leave=0, enter=0;
      while(leave < SZ(subset) || enter<SZ(subset)) {
        int cur=numeric_limits<int>::max();
        if(leave < SZ(subset)) cur=min(cur, subset[leave].first);
        if(enter < SZ(subset)) cur = min(cur, subset[enter].first-side);
        int have =1;
        while(enter < SZ(subset) && subset[enter].first-side==cur) {
          mask ^=Two(point2idx[subset[enter]]);
          enter++;
          have=0;
        }
        while(leave < SZ(subset) && subset[leave].first < cur + have ) {
          mask ^=Two(point2idx[subset[leave]]);
          leave++;
        }
        gAll.insert(mask);
        //debug(mask);
      }
    }
  }

}

class RangeSquaredSubsets {
 public:
  long long countSubsets(int nlow, int nhigh, vector <int> x, vector <int> y) {

    const int n=SZ(x);
    Rep(i,n) {
      x[i]*=2;
      y[i]*=2;
    }
    nlow <<= 1; nhigh <<= 1;
    vector<pii> all(n);
    gAll.clear();
    point2idx.clear();
    Rep(i,n) {
      all[i]=pii(x[i],y[i]);
      point2idx[all[i]]=i;
    }
    solve(all,nlow,nhigh);
    point2idx.clear();
    Rep(i,n) {
      all[i]=pii(y[i],x[i]);
      point2idx[all[i]]=i;
    }
    solve(all,nlow,nhigh);

    return gAll.size()-gAll.count(0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 5LL; verify_case(0, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 5LL; verify_case(1, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 100; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 6LL; verify_case(2, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 100000000; int Arr2[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-1,0,1,1,-1,0,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 21LL; verify_case(3, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 64; int Arg1 = 108; int Arr2[] = {-56,-234,12,324,-12,53,0,234,1,12,72}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,34,2,235,234,234,342,324,234,234,234}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 26LL; verify_case(4, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  RangeSquaredSubsets ___test;
  ___test.run_test(-1);
}
// END CUT HERE
