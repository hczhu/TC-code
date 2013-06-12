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
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int N = 50;
int have[2][N][N], need[2][N][N];
vector<string> grid;
bool Valid(int r, int c) {
  return r>=0 && r < SZ(grid) && c >=0 && c < SZ(grid[r]) && '.'==grid[r][c];
}
void DP(int r, int c, int pd) {
  vector<pair<int,int> > son;
  Rep(d, 4)if (d != (pd^1) && Valid(r+dir[d][0], c+ dir[d][1])) {
    son.push_back(make_pair(r+dir[d][1], c+dir[d][1]));
    DP(son.back().first, son.back().second, d);
  }
#define IDX(ppi) [(ppi).first][(ppi).second]
  // have[0][r][c]
  {
    int& res = have[0][r][c];
    int put = 1, not_put = 0;
    Rep(i, SZ(son)) {
      put += have[]IDX(son[i]);
    }
  }
  cerr << r << "," << c << "=" << have[0][r][c] << " " << have[1][r][c]
    << " " << need[0][r][c] << " " << need[1][r][c] <<endl;
}

class FoxBomb {
 public:
  int getMinimumCost(vector <string> grid) {
    debug("Start calculation.");
    ::grid = grid;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#..."
,"..##"
,"#.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMinimumCost(Arg0)); }
	void test_case_1() { string Arr0[] = {".#.#.#."
,"......."
,".#.#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, getMinimumCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"######################################"
,"######################################"
,"###.....................##############"
,"###.###################.###....#...###"
,"###.###################.###.######.###"
,"###.###################.###.######.###"
,"###.###################.###.######.###"
,"###.###################.###.######.###"
,"###.###################.###.######.###"
,"###.........####........###.######.###"
,"###########.###########.###........###"
,"###########.###########.##########.###"
,"###########.###########.##########.###"
,"###########.###########.##########.###"
,"###########.###########.##########.###"
,"##..........##..........##########.###"
,"#######################............###"
,"######################################"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getMinimumCost(Arg0)); }
	void test_case_3() { string Arr0[] = {".#."
,"..."
,"#.#"
,"..."
,".#."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getMinimumCost(Arg0)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getMinimumCost(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxBomb ___test;
  ___test.run_test(-1);
}
// END CUT HERE
