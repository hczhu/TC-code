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
#define Two(x) ((1)<<(x))
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef pair<int,int> Pii;
Pii trans[6][51][26];
int match[6][51];
void ConstructAuto(const Vs& word) {
  Rep(i, SZ(word)) Rep(j,SZ(word[i])+1){
    string pre=word[i].substr(0,j);
    Rep(k,SZ(word)) if(SZ(pre)>=SZ(word[k])&&
        pre.substr(SZ(pre)-SZ(word[k])) == word[k]) match[i][j]|=Two(k);
    //cerr<<"matching "<<i<<" "<<j<<"="<<match[i][j]<<endl;
    Rep(c,26) {
      pre.push_back('a'+c);
      int best=0, idx=0;
      Rep(k,SZ(word)) {
        int t=0;
        for(t=SZ(pre); pre.substr(SZ(pre)-t)!=word[k].substr(0,t);t--);
        if(t>best) best=t, idx=k;
      }
      trans[i][j][c]=Pii(idx,best);
      //if(c==0)cerr<<i<<" "<<j<<" "<<((char)(c+'a'))<<"="<<trans[i][j][c].first<<" "<<trans[i][j][c].second<<endl;
      pre.erase(--pre.end());
    }
  }
}
int dp[51][6][51][1<<6];
const int mod=1000000009;
class RequiredSubstrings {
 public:
  int solve(vector <string> words, int C, int L) {
    memset(dp,0,sizeof(dp));
    memset(match,0,sizeof(match));
    debug("Start calculation.");
    ConstructAuto(words);
    debug(sizeof(dp));
    dp[0][0][0][0]=1;
    const int n=SZ(words);
    Rep(ll,L)Rep(i,SZ(words))Rep(j,SZ(words[i])+1)Rep(mk, Two(n)) {
      const int add=dp[ll][i][j][mk];
      if(0==add)continue;
      //cerr<<ll<<" "<<i<<" "<<j<<" "<<mk<<"="<<add<<endl;
      const Pii* tr=trans[i][j];
#define Update(x,y) x=(x+(y))%mod
#define Subscrib(pp) [(pp).first][(pp).second]
      Rep(c,26) {
        Update(dp[ll+1]Subscrib(tr[c])[mk|match[tr[c].first][tr[c].second]],add);
        //cerr<<"-->"<<ll+1<<" "<<tr[c].first<<" "<<tr[c].second<<" "<<(mk|match[tr[c].first][tr[c].second])<<endl;
      }
    }
    int ans=0;
    Rep(i,SZ(words))Rep(j,SZ(words[i])+1) Rep(mk,Two(n)){
      int cnt=0;
      Rep(x,n)if(mk&Two(x))cnt++;
      if(cnt==C)ans+=dp[L][i][j][mk],ans%=mod;
      //if(cnt==C)cerr<<L<<" "<<i<<" "<<j<<" "<<mk<<"="<<dp[L][i][j][mk]<<endl;
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","aa","aaa","aaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 50; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"abcdefgh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 7; int Arg3 = 31810104; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"abcdefgh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; int Arg3 = 0; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 24; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ab","bc","xy","yz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 2; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  RequiredSubstrings ___test;
  ___test.run_test(-1);
}
// END CUT HERE
