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
#include <bitset>

using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
typedef bitset<50> Bits;

int get_seq(int a,int b,int step,int upper=200000000) {
  int x=a,y=b;
  for(int i=0;i<step&&y<=upper;i++) {
    int z=x+y;
    x=y,y=z;
  }
  return y;
}
int get_next(int a,int b,int gap) {
  if(gap==1) return b;
  assert(gap>1);
  assert(a<b);
  int low=1,high=b;
  while(low<high) {
    int mid=(low+high)>>1;
    if(get_seq(a,mid,gap-1,b+10)>=b)high=mid;
    else low=mid+1;
  }
  return get_seq(a,low,gap-1,b+10)==b?low:0;
}
Bits generate(int a,int b,int gap,map<int,int>& mem) {
  int mid=get_next(a,b,gap);
  Bits res;
  if(mid==0) {
    //cerr<<a<<" "<<b<<" "<<gap<<"="<<res<<endl;
    return res;
  }
  int upper=(mem.rbegin()->first);
  int x=a,y=mid;
  if(mid>a&&mem.count(mid)) return res;
  assert(mem.count(a));
  res.set(mem[a]);
  while(y<=upper) {
    if(y>x&&mem.count(y))res.set(mem[y]);
    int z=x+y;
    x=y,y=z;
  }
  //cerr<<a<<" "<<b<<" "<<gap<<"="<<res<<endl;
  return res;
}
class SubFibonacci {
	public:
	 int maxElements(vector <int> S) {
		 debug("Start calculation.");
     sort(All(S));
     const int n=SZ(S);
     if(n<=4) return n;
     map<int,int> mem;
     Rep(i,n)mem[S[i]]=i;
     vector<Bits> cand;

     //debug(get_seq(S[3],1,1,S[5]+10));
     Rep(j,n)Rep(i,j)for(int gap=1;get_seq(S[i],1,gap-1,S[j]+10)<=S[j];gap++) {
       Bits bit=generate(S[i],S[j],gap,mem);
       //debug(S[i]);
       //debug(S[j]);
       //debug(gap);
       //if(i==3&&j==5&&gap==2)assert(0);
       if(bit.count()>2)cand.push_back(bit);
     }
     int res=min(4,n);
     debug(SZ(cand));
     Rep(cut,n+1) {
       int a=min(2,cut),b=min(2,n-cut);
       Rep(i,SZ(cand)) {
         int xa=0;
         Rep(x,cut)if(cand[i][x])xa++;
         a=max(xa,a);
         int xb=0;
         For(x,cut,n)if(cand[i][x])xb++;
         b=max(b,xb);
       }
       res=max(res,a+b);
       //cerr<<cut<<" "<<a<<" "<<b<<endl;
     }
     return res;
	}
  




// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 1, 20, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxElements(Arg0)); }
	void test_case_1() { int Arr0[] = {19, 47, 50, 58, 77, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxElements(Arg0)); }
	void test_case_2() { int Arr0[] = {512}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxElements(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 5, 7, 10, 13, 15, 20, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maxElements(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, maxElements(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main() {
  SubFibonacci ___test; 
  ___test.run_test(-1); 
}
// END CUT HERE
