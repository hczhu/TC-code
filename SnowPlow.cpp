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
class SnowPlow {
	public:
	 int solve(vector <string> roads) {
		 debug("Start calculation.");
     const int n=SZ(roads);
     int ans=0;
     Rep(i,n)Rep(j,n)ans+=roads[i][j]-'0',roads[i][j]=(roads[i][j]=='0'?'0':'1');
     Rep(i,n)roads[i][i]='1';
     Rep(k,n)Rep(i,n)Rep(j,n)if(roads[i][k]!='0'&&roads[k][j]!='0')roads[i][j]='1';
     Rep(i,n) {
       if(roads[0][i]=='0'&&
           (roads[i].find('1')<i||roads[i].find('1',i+1)!=string::npos))return -1;
     }
     return ans;
	}
};
