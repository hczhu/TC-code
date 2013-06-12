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
// Convert anything to string
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
typedef long long int llint;
#define Two(x)  ((1LL)<<(x))
llint getN(llint n) {
  return Two(n)+((n)*8-1)*Two(n-1);
}
llint DFS(string& num,int pos,bool smaller,bool no) {
  if(pos==SZ(num))return 1;
  if(smaller) return no?Two(SZ(num)-pos):(getN(SZ(num)-pos)+Two(SZ(num)-pos-1));
  llint res=0;
  Rep(i,10) {
    if(pos==0&&i==0)continue;
    if(no&&i!=4&&i!=7)continue;
    if(!smaller&&i>num[pos]-'0')continue;
    res+=DFS(num,pos+1,smaller||(i<num[pos]-'0'),no||(i!=4&&i!=7));
  }
  cerr<<num<<" "<<pos<<" "<<smaller<<" "<<no<<"="<<res<<endl;
  return res;
}
llint get(llint n) {
  string sn=convert(n);
  //reverse(All(sn));
  llint ans=DFS(sn,0,false,false);
  For(i,1,SZ(sn))ans+=getN(i);
  debug(getN(2));
  debug(getN(3));
  debug(getN(1));
  //ans+=SZ(sn)>1?getN(SZ(sn)-1):0;
  cerr<<n<<"="<<ans<<endl;
  return ans;
}
class TheAlmostLuckyNumbersDivOne {
	public:
	 long long find(long long a, long long b) {
		 debug("Start calculation.");
     return get(b)-get(a-1);
	}
};
/*
bool check(int n) {
  int no=0;
  while(n) {
    int d=n%10;n/=10;
    if(d!=4&&d!=7)no++;
  }
  return no<=1;
}
int main() {
  TheAlmostLuckyNumbersDivOne the;
  debug(get(140));
  debug(get(139));
  //int n;
  For(n,1,200) {
    debug(n);
    debug(get(n));
    int ans=get(n);
    Rep(i,n) {
      if(check(i+1)) {
        ans--;
      }
    }
    debug(ans);
    assert(ans==0);
  }
  return 0;
}
*/
