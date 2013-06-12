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
const llint mod=1000000007LL;
template<typename T,int N>
void init_bino(T com[N][N],bool take_mod=false,long long int mod=1000000000000000000LL)
{
	if(take_mod)
	{
		assert(mod>0);
		com[0][0]=1%mod;
		for(int i=1;i<N;i++)
		{
			com[i][0]=com[i][i]=1%mod;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
		}
	}
	else
	{
		com[0][0]=1;
		for(int i=1;i<N;i++)
		{
			com[i][0]=com[i][i]=1;
			for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j]);
		}
	}
}
llint bino[100][100];
llint dp[100][100];
class AdjacentSwaps {
  typedef vector<int> Vi;
  llint DP(const Vi& p,int st,int end) {
    if(end-st==1)return 1;
    if(dp[st][end]!=-1) return dp[st][end];
    llint& res=dp[st][end];
    res=0;
    assert(end-st>=2);
    Vi sub(p.begin()+st,p.begin()+end);
    sort(All(sub));
    map<int,int> order;
    set<int> mem;
    Rep(i,SZ(sub)) order[sub[i]]=i;
    For(i,st,end) {
      mem.insert(order[p[i]]);
      typeof(mem.rbegin()) itr=mem.rbegin(); itr++;
      if(*mem.rbegin()==SZ(mem) && (mem.size()==1 || (*(itr))==SZ(mem)-2)) {
        //cerr<<st<<","<<end<<"-->"<<i<<endl;
        llint add=DP(p,st,i+1)*DP(p,i+1,end)%mod;
        add = add*bino[end-st-2][i-st]%mod;
        res+=add;
      }
    }
    res%=mod;
    //cerr<<st<<","<<end<<"="<<res<<endl;
    return res;
  }
 public:
  int theCount(vector <int> p) {
    debug("Start calculation.");
    init_bino(bino,true,mod);
    memset(dp,0xff,sizeof(dp));
    return DP(p,0,SZ(p));
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 716743312; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  AdjacentSwaps ___test;
  ___test.run_test(-1);
}
// END CUT HERE
