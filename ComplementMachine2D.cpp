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
using std::vector;
using std::string;
using std::cerr;
using std::endl;
using std::max;
using std::min;
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
const int N=50;
int down[N][N],right[N][N];
class ComplementMachine2D {
	public:
	 int largestSubmatrix(vector <string> matrix) {
		 debug("Start calculation.");
     const int n=matrix.size();
     const int m=matrix[0].length();
     for(int i=0;i<n;i++)right[i][m-1]=m-1;
     for(int j=0;j<m;j++)down[n-1][j]=n-1;
     for(int i=n-2;i>=0;i--)
     for(int j=m-2;j>=0;j--) {
       {
        int a=(matrix[i][j]-'0')^(matrix[i+1][j]-'0');
        int b=(matrix[i][j+1]-'0')^(matrix[i+1][j+1]-'0');
        right[i][j]=(a==b?right[i][j+1]:j);
       }
       {
         int a=(matrix[i][j]-'0')^(matrix[i][j+1]-'0');
         int b=(matrix[i+1][j]-'0')^(matrix[i+1][j+1]-'0');
         down[i][j]=(a==b?down[i+1][j]:i);
       }
     }
     int ans=max(n,m);
     for(int r=0;r<n;r++)
     for(int c=0;c<m;c++) {
       for(int c2=right[r][c];c2>c;c2--) {
         int r2=n-1;
         for(int i=c;i<c2;i++)r2=min(r2,down[r][i]);
         while(r2>r&&right[r2-1][c]<c2)r2--;
         cerr<<r<<","<<c<<" "<<r2<<","<<c2<<endl;
         ans=max(ans,(r2-r+1)*(c2-c+1));
       }
     }
     return ans;
	}
};
