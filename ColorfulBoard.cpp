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

void transpose(vector<string>& matrix) {
  typeof(matrix) tmp(SZ(matrix[0]),string(SZ(matrix),'a'));
  Rep(i,SZ(matrix)) Rep(j,SZ(matrix[i])) {
    tmp[j][i] = matrix[i][j];
  }
  matrix.swap(tmp);
}

typedef vector<int> Vi;
bool DFS(int v,const vector<Vi>& edge,Vi& stat) {
  stat[v]=1;
  Rep(i,SZ(edge[v])) {
    if(stat[edge[v][i]]==1) return true;
    if(0==stat[edge[v][i]] && DFS(edge[v][i],edge,stat)) return true;
  }
  stat[v]=2;
  return false;
}
bool CycleExists(const vector<Vi>& edge) {
  Vi stat(SZ(edge),0);
  Rep(i,SZ(stat)) if(stat[i]==0 && DFS(i, edge,stat)) {
    return true;
  }
  return false;
}
int solve(const vector<string>& grid,const string& col) {
  const int n=SZ(grid);
  const int m=SZ(grid[0]);
  int res=m;
  vector<Vi> edge(m);
  Rep(i,n) {
    Vi same,not_same;
    set<char> diff;
    Rep(j,m) {
      if(grid[i][j]==col[j]) {
        same.push_back(j);
      } else {
        not_same.push_back(j);
        diff.insert(grid[i][j]);
      }
    }
    if(SZ(diff)>1) return n+m;
    Rep(a,SZ(same))if(*diff.begin()!=col[same[a]])Rep(b,SZ(not_same)) {
      edge[same[a]].push_back(not_same[b]);
      //cerr<<"add edge "<<same[a]<<"-->"<<not_same[b]<<endl;
    }
    res+=SZ(diff);
  }
  cerr<<"col="<<col<<" res="<<res<<endl;
  return CycleExists(edge)?n+m:res;
}
class ColorfulBoard {
 public:
  int theMin(vector <string> board) {
    debug("Start calculation.");
    int n=SZ(board);
    int m=SZ(board[0]);
    int ans=n+m;
    Rep(cc,2) {
      Rep(k,n) {
        ans=min(ans,solve(board,board[k]));
      }
      transpose(board);
      swap(n,m);
    }
    return ans==n+m?-1:ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SSS",
 "SRR",
 "SMM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theMin(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, theMin(Arg0)); }
	void test_case_2() { string Arr0[] = {"Ab",
 "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, theMin(Arg0)); }
	void test_case_3() { string Arr0[] = {"iiiii",
 "iwiwi"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, theMin(Arg0)); }
	void test_case_4() { string Arr0[] = {"ffffffffff",
 "xfxxoofoxo",
 "ffffffffff",
 "xfxxoofoxo",
 "ffffffffff",
 "ooxxoofoxo",
 "xfxxoofoxo",
 "xfxxoxfxxo",
 "ffxxofffxo",
 "xfxxoxfxxo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(4, Arg1, theMin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ColorfulBoard ___test;
  ___test.run_test(-1);
}
// END CUT HERE
