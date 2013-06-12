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
#define NDEBUG
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
typedef long long int llint;
llint dp[55][2][55][55];
string init;
int first,first_v,KK,TT,head;
int getLive(int ll,int rr,int len) {
  if(len<=0)return 0;
  if(ll==rr) {
    assert(len&1);
    if(ll==1) return len/2+min(TT,len-len/2);
    else  {
      return len/2+1-min(len/2+1,TT);
    }
  }
  else {
    assert((1&len)==0);
    return len/2;
  }
}
#define Can(pos,x) (init[pos]=='?'||init[pos]=='0'+(x))
llint DP(int last,int last_v,int pos,int live,int pre) {
  llint& res=dp[last][last_v][pos][live];
  if(res!=-1)return res;
  res=0;
  if(pos==SZ(init)) {
    int add=0;
    if(pre==head) {
      add+=getLive(last_v,head,pos-1-last-1);
      add+=getLive(first_v,head,first-1);
      add+=pre*((first?1:0)+((last==pos-1)?0:1));
    }
    else {
      add+=getLive(last_v,first_v,pos-last-1+first);
    }
    res+=(live+add>=KK)?1:0;
  }
  else {
    // ==pre
    if(Can(pos,pre))
      res+=DP(pos,pre,pos+1,live+getLive(last_v,pre,pos-last-2)+pre*(1+(last==pos-1?0:1)),pre);
    // !=pre
    if(Can(pos,(pre^1)))
      res+=DP(last,last_v,pos+1,live,pre^1);
  }
  //cerr<<last<<" "<<last_v<<" "<<pos<<" "<<live<<"="<<res<<endl;
  return res;
}
class GameOfLifeDivOne {
	public:
	 long long theCount(string init, int T, int K) {
		 debug("Start calculation.");
     KK=K,TT=T;::init=init;
     llint ans=0;
     const int n=SZ(init);
     // 0,1,0,1
     if(0==(SZ(init)&1)) Rep(head,2) {
       bool ok=true;
       Rep(i,n) {
         if(!Can(i,head^(i&1))) ok=false;
       }
       if(ok&&SZ(init)/2>=K)ans++;
     }
     // 0,1,0,1,...,1,0
     if(SZ(init)&1) Rep(head,2) {
       bool ok=true;
       Rep(i,n) if(!Can(i,head^(i&1)))ok=false;
       if(ok&&getLive(head,head,n-2)+2*head>=K)ans++;
     }
     debug(ans);
     Rep(f,2)Rep(i,SZ(init)-1) {
       head=f;
       first=i;
       first_v=head^(i&1);
       if(!Can(i,first_v))break;
       if(!Can(i+1,first_v))continue;
       memset(dp,0xff,sizeof(dp));
       ans+=DP(i+1,first_v,i+2,first_v*2,first_v);
       debug(head);
       debug(i);
       debug(ans);
     }
     return ans;
	}
};
/*
int main() {
  GameOfLifeDivOne game;
  string init;
  int K,T;
  cin>>init>>T>>K;
  cout<<game.theCount(init,T,K)<<endl;
  return 0;
}
*/
