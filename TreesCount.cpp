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
int dis[100][100];
typedef long long int llint;
const llint mod=1000000007;
class TreesCount {
	public:
	 int count(vector <string> graph) {
		 debug("Start calculation.");
     const int n=SZ(graph);
     const int inf=1000000;
     Rep(i,n)Rep(j,n)dis[i][j]=graph[i][j]=='0'?inf:graph[i][j]-'0';
     Rep(i,n)dis[i][i]=0;
     Rep(k,n)Rep(i,n)Rep(j,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
     llint ans=1;
     vector<int> indeg(n);
     Rep(i,n)cerr<<i<<"="<<dis[0][i]<<endl;
     Rep(i,n)Rep(j,n) if(graph[i][j]!='0'&&dis[0][i]+graph[i][j]-'0'==dis[0][j]) {
       indeg[j]++;
     }
     Rep(i,n-1)ans*=indeg[i+1],ans%=mod;
     return ans;
	}
};
