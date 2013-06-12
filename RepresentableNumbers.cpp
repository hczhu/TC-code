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
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
void generate(vector<int>& all,int cur,int X) {
  if(cur)all.push_back(cur);
  if(cur>X/10)return;
  for(int d=1;d<10;d+=2) {
    int t;
    if((t=cur*10+d)<=X) {
      generate(all,t,X);
    }
  }
}
class RepresentableNumbers {
	public:
	 int getNext(int X) {
		 debug("Start calculation.");
     vector<int> all;
     generate(all,0,X*3);
     debug(all.size());
     sort(All(all));
     int ans=3*X;
     int p=SZ(all);
     Rep(i,SZ(all)) {
       while(p-1>=0&&all[p-1]+all[i]>=X)p--;
       if(p<SZ(all)) {
         ans=min(ans,all[p]+all[i]);
       }
     }
     return ans;
	}
};
