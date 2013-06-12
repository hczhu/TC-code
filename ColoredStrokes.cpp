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
#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Back(str) (str)[(str).length()-1]
#define SZ(vec) ((int)(vec).size())
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
char grid[100][100];
bool check(int n,int m) {
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++) {
    if(grid[i][j]!='.') {
      int dx=0,dy=1;
      char ch='R';
      if(grid[i][j]=='B')dx=1,dy=0,ch='B';
      while(grid[i][j]==ch||grid[i][j]=='G') {
        grid[i][j]=grid[i][j]==ch?'.':(char)('R'+'B'-ch);
        i+=dx;
        j+=dy;
      }
      return true;
    }
  }
  return false;
}
class ColoredStrokes {
	public:
	 int getLeast(vector <string> picture) {
		 debug("Start calculation.");
     int hash[1000];
     hash['R']=hash['B']=1;hash['G']=2;
     const int n=picture.size();
     const int m=picture[0].length();
     for(int i=0;i<n;i++)for(int j=0;j<m;j++) {
       grid[i][j]=picture[i][j];
     }
     int ans=0;
     while(check(n,m))ans++;
     return ans;


	}
};
