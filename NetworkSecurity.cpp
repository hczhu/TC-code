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
//#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
//#define Back(str) (str)[(str).length()-1]
#define SZ(vec) ((int)(vec).size())
//#define All(vec) (vec).begin(),(vec).end()
/*********************************
 Tips
 * Binary search
 * Ternary search
 * Bitwise tricks
 * Bipartite matching
 * Graph algorithms
 * DP
 * Subset DP
 * Greedy algorithms
 * Network flow
 * Construct the solution directly
 * Be careful to the input constraints
 * Corner cases.
**********************************/
bool con[100][100];
class NetworkSecurity {
	public:
	 int secureNetwork(vector <string> client, vector <string> server) {
		 debug("Start calculation.");
     const int n=SZ(client);
     const int m=SZ(server[0]);
     
     Rep(x,m) {
       queue<int> qq;
       bool* used=con[x];
       Rep(i,n)Rep(j,m)if(j==x&&'Y'==server[i][j]) {
         qq.push(i);
         used[i]=true;
         break;
       }
       debug(qq.size());
       while(qq.size()) {
         int v=qq.front();qq.pop();
         Rep(i,n) {
           if(!used[i]&&'Y'==client[i][v]) {
             qq.push(i);used[i]=true;
           }
         }
       }
     }
     int ans=0;
     Rep(i,n) {
       vector<bool> reach(m,false);
       Rep(j,n)if('Y'==client[i][j]) Rep(k,m)if(con[k][j])reach[k]=true;
       Rep(j,m)if('Y'==server[i][j]&&!reach[j])ans++;
     }
     return ans;
	}
};
