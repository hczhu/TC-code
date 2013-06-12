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
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
vector<int> cards;

int dp[512][51];

bool DP(int mk,int same) {
  if(mk==511) return true;
  int& res=dp[mk][same];
  if(res)return 1==res;
  res=2;
  vector<int> next;
  int tot=0;
  Rep(i,SZ(cards)) if((cards[i]|mk)!=mk)next.push_back(cards[i]);else tot++;
  assert(tot>=same);
  if(same&&!DP(mk,same-1))res=1;
  Rep(i,SZ(next)) if(2==res) {
    int nsame=same;
    int nmk=mk|next[i];
    assert(nmk!=mk);
    Rep(j,SZ(next)) if((nmk|next[j])==nmk)nsame++;
    assert(nsame>same);
    nsame--;
    if(!DP(nmk,nsame)) {
      res=1;
      break;
    }
  }
  return 1==res;
}

class FiveHundredEleven {
	public:
	 string theWinner(vector <int> cards) {
		 debug("Start calculation.");
     ::cards=cards;
     return DP(0,count(All(cards),0))?"Fox Ciel":"Toastman";
	}
};
