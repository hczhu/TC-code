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
llint len[1001];
struct Node {
  llint ll,rr,opt;
  Node(llint a=0,llint b=0,llint c=0) : ll(a) ,rr(b) ,opt(c) {};
};
Node solveOne(const string& ss,llint ll,llint rr) {
  llint a=0,b=0,c=0;
  assert(rr<=ss.length());
  assert(ll<ss.length());
  assert(ll<rr);
  while(a<rr-ll&&ss[a+ll]=='1')a++;
  while(b<rr-ll&&ss[rr-1-b]=='1')b++;
  llint pre=0;
  for(llint i=ll;i<rr;i++) {
    if(ss[i]=='1') {
      pre++;
      c=max(c,pre);
    } else {
      pre=0;
    }
  }
  return Node(a,b,c);
}
vector<string> init;
map<pair<llint,llint>,Node> cache[1000];
Node solve(int idx,llint ll,llint rr) {
  cout<<"solve "<<idx<<" len="<<len[idx]<<" "<<ll<<" "<<rr<<endl;
  assert(ll<len[idx]);
  assert(rr<=len[idx]);
  assert(ll<rr);
  if(cache[idx].count(make_pair(ll,rr))) {
    return cache[idx][make_pair(ll,rr)];
  }
  cout<<idx<<": len="<<len[idx]<<endl;
  const int K=SZ(init);
  Node& ans=cache[idx][make_pair(ll,rr)];
  if(idx<SZ(init)) {
    return ans=solveOne(init[idx],ll,rr);
  }
  llint a=0,b=0,c=0;
  llint psum=0;
  vector<Node> son;
  vector<pair<llint,llint> > inter;
  for(int i=idx-1;i>=0;i-=K) {
    psum+=len[i];
    if(psum>ll&&psum-len[i]<rr) {
      inter.push_back(make_pair(max(ll,psum-len[i])-psum+len[i],min(psum,rr)-psum+len[i]));
      son.push_back(solve(i,inter.back().first,inter.back().second));
    }
  }
#define ILen(pp) ((pp).second-(pp).first)
  Rep(i,SZ(inter)) {
    a+=son[i].ll;
    if(son[i].ll!=ILen(inter[i])) {
      break;
    }
  }
  for(int i=SZ(inter)-1;i>=0;i--) {
    b+=son[i].rr;
    if(son[i].rr!=ILen(inter[i])) {
      break;
    }
  }
  llint pre=0;
  Rep(i,SZ(inter)) {
    c=max(c,son[i].opt);
    pre+=son[i].ll;
    c=max(c,pre);
    if(son[i].ll!=ILen(inter[i])) {
      pre=son[i].rr;
      c=max(c,pre);
    }
  }
  cout<<idx<<","<<ll<<","<<rr<<"="<<a<<" "<<b<<" "<<c<<endl;
  return ans=Node(a,b,c);
}

class MagicalGirlLevelThreeDivOne {
 public:
  long long theMaxPower(vector <string> first, int n, long long lo, long long hi) {
    debug("Start calculation.");
    for(int i=0;i<1000;i++)cache[i].clear();
    init=first;
    /*
    first.clear();
    first.resize(50,string("1"));*/
    const int K=SZ(first);
    for(int i=0;i<K;i++) {
      len[i]=SZ(first[i]);
    }
    for(int i=K;i<1000;i++) {
      len[i]=len[i-1];
      for(int j=K;i-j>=0;j+=K) {
        len[i]+=len[i-1-j];
      } 
      if(len[i]>hi&&n>=K) {
        n=i;
        break;
      }
    }
    debug(n);
    return solve(n,lo,hi+1).opt;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111", "011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; long long Arg3 = 7LL; long long Arg4 = 4LL; verify_case(0, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456789; long long Arg2 = 123456789LL; long long Arg3 = 123456789012345LL; long long Arg4 = 123456665555557LL; verify_case(1, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 987654321; long long Arg2 = 987654321LL; long long Arg3 = 987654321054321LL; long long Arg4 = 0LL; verify_case(2, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"1110", "11", "11111", "111", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 314159265; long long Arg2 = 271828182845904LL; long long Arg3 = 314159265358979LL; long long Arg4 = 15LL; verify_case(3, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long long Arg2 = 1000000000000000LL; long long Arg3 = 1000000000000000LL; long long Arg4 = 1LL; verify_case(4, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MagicalGirlLevelThreeDivOne ___test;
  ___test.run_test(-1);
}
// END CUT HERE
