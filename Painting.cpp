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
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
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
vector<string> grid;
int used[100][100];
bool check(int r,int c,int X,int Y) {
  for(int i=0;i<X;i++)
  for(int j=0;j<Y;j++)
    if(grid[r+i][c+j]!='B')return false;
  return true;
}
class Painting {
	public:
	 int largestBrush(vector <string> pic) {
		 debug("Start calculation.");
     grid=pic;
     const int n=pic.size();
     const int m=pic[0].length();
     int low=1,high=min(n,m);
     int ff=0;
     int bb=0;
     for(int i=0;i<n;i++)bb+=count(pic[i].begin(),pic[i].end(),'B');
     while(low<high) {
       ff++;
       int cnt=bb;
       int mid=(low+high)>>1;mid++;
       for(int r=0;r+mid<=n;r++)
       for(int c=0;c+mid<=m;c++) {
         if(check(r,c,mid,mid)) {
           for(int i=0;i<mid;i++)
           for(int j=0;j<mid;j++) {
             if(ff!=used[i+r][j+c]) {
               used[i+r][j+c]=ff;
               cnt--;
             }
           }
         }
       }
       assert(cnt>=0);
       if(cnt==0)low=mid;
       else high=mid-1;
     }
     return low;
	}
};
