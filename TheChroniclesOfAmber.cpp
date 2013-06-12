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
#define Squ(x) ((x)*(x))
int dis[50][50];
vector<int> edge[50];
bool check(int n) {
  Rep(i,n) {
    cerr<<i<<":";
      Rep(j,SZ(edge[i]))cerr<<" "<<edge[i][j];
    cerr<<endl;
  }
  debug("-----------------------");
  vector<int> indeg(n);
  Rep(i,n)if(edge[i].empty())return false;
  Rep(i,n)Rep(j,SZ(edge[i]))indeg[edge[i][j]]++;
  Rep(i,n)if(SZ(edge[i])!=1||indeg[i]!=1)return true;
  Rep(i,n)if(edge[i][0]!=i)return false;
  return true;
}
class TheChroniclesOfAmber {
	public:
	 double minimumTime(vector <int> px, vector <int> py, vector <int> dx, vector <int> dy) {
		 debug("Start calculation.");
     const int n=SZ(px);
     vector<int> ans;
     Rep(i,n)Rep(j,n) {
       dis[i][j]=Squ(px[i]-dx[j])+Squ(py[i]-dy[j]);
       ans.push_back(dis[i][j]);
     }
     sort(All(ans));
     ans.resize(unique(All(ans))-ans.begin());
     debug(SZ(ans));
     int low=0,high=SZ(ans)-1;
     while(low<high) {
       int mid=(low+high)>>1;
       Rep(i,n)edge[i].clear();
       Rep(i,n)Rep(j,n)if(dis[j][i]<=ans[mid])edge[i].push_back(j);
       cerr<<"check "<<ans[mid]<<endl;
       if(check(n)) high=mid;
       else low=mid+1;
     }
     return sqrt(1.0*ans[low]);
	}
};
