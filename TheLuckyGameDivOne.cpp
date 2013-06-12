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
#define Two(x)  ((1)<<(x))
typedef long long int llint;
const int N=1000000;


int luckb[N];
int qq[N];
class TheLuckyGameDivOne {
	public:
	 int find(long long a, long long b, long long jLen, long long bLen) {
		 debug("Start calculation.");
     llint low=0;
     vector<llint> bound;
     bound.push_back(a);
     bound.push_back(b);
     if(a+jLen<=b)bound.push_back(a+jLen);
     if(a+bLen<=b)bound.push_back(a+bLen);
     if(b-jLen>=a)bound.push_back(b-jLen);
     if(b-bLen>=a)bound.push_back(b-bLen);
     set<llint> isluck;
     llint add[2]={jLen,bLen};
     for(int len=1;low<=b;len++,low=low*10+4)
     Rep(mk,Two(len)) {
       llint t=0;
       Rep(i,len) t=t*10+((mk&Two(i))?7:4);
       if(t>=a&&t<=b) {
         debug(t);
         isluck.insert(t);
         //bound.push_back(t);
         For(x,-1,2)For(y,0,2)For(z,-1,2) {
           llint tt=(t+x)+z*add[y];
           if(tt>=a&&tt<=b)bound.push_back(tt);
         }
       }
     }
     sort(All(bound));
     bound.resize(unique(All(bound))-bound.begin());
     debug(SZ(bound));
     int ll=0,luck=0;
     Rep(i,SZ(bound)) {
       luck+=isluck.count(bound[i]);
       while(bound[i]-bound[ll]>=bLen) {
         luck-=isluck.count(bound[ll]);
         ll++;
       }
       luckb[i]=luck;
       cerr<<"luckb "<<i<<" = "<<luck<<endl;
     }
     int head=0,tail=0;
     int ans=0;
     Rep(i,SZ(bound)) {
       while(head<tail&&luckb[qq[tail-1]]>=luckb[i]) {
         tail--;
       }
       qq[tail++]=i;
       while(head<tail&&bound[qq[head]]<a+bLen-1)head++;
       while(head<tail&&bound[i]-bound[qq[head]]>jLen-bLen)head++;
       if(head<tail&&bound[i]>=a+jLen-1)ans=max(ans,luckb[qq[head]]);
       /*
       debug(i);
       debug(ans);
       debug(head);debug(tail);
       For(i,head,tail)cerr<<qq[i]<<" ";cerr<<endl;
       */
     }
     return ans;
	}
};
