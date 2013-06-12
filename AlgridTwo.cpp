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
typedef long long int llint;
const llint mod=1000000007;
llint pp[10000];
class AlgridTwo {
	public:
	 int makeProgram(vector <string> output) {
		 debug("Start calculation.");
		 pp[0]=1;
		 for(int i=1;i<1000;i++) {
			 pp[i]=(pp[i-1]<<1)%mod;
		 }
		 const int n=output.size();
		 const int m=output[0].length();
		 const string color="WB";
		 llint ans=1;
		 for(int i=0;i<n-1;i++) {
			 string line(m,'*');
			 for(int j=0;j<m-1;j++) {
				 if(output[i][j]=='W'&&output[i][j+1]=='W') {
				 }
				 else if(output[i][j]=='W'&&output[i][j+1]=='B') {
					 line[j]=line[j+1]='W';
				 }
				 else if(output[i][j]=='B'&&output[i][j+1]=='W') {
					 line[j]=line[j+1]='B';
				 }
				 else {
					 swap(line[j],line[j+1]);
				 }
			 }
			 debug(i);
			 debug(line);
			 int cnt=0;
			 for(int j=0;j<m;j++) {
				 if(line[j]=='*')cnt++;
				 else if(line[j]!=output[i+1][j])return 0;
			 }
			 debug(cnt)
			 ans*=pp[m-cnt];
			 ans%=mod;
			 debug(ans);
		 }
		 return ans;
	}
};
