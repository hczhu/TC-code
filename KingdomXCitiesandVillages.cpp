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
llint vc[100][100],vv[100][100];
llint min_vc[100];
llint get_dis(llint a,llint b){
	return a*a+b*b;
}
bool myless(int v,int v1,int v2) {
	return vv[v][v1]<vv[v][v2] ||
			(vv[v][v1]==vv[v][v2]&&v1<v2);
}
class KingdomXCitiesandVillages {
	public:
	 double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
		 debug("Start calculation.");
		 const int m=cityX.size();
		 const int n=villageX.size();
		 for(int i=0;i<n;i++) {
			 for(int j=0;j<m;j++)vc[i][j]=get_dis(villageX[i]-cityX[j],villageY[i]-cityY[j]);
			 min_vc[i]=*min_element(vc[i],vc[i]+m);
			 for(int j=0;j<n;j++)
				 vv[i][j]=get_dis(villageX[i]-villageX[j],villageY[i]-villageY[j]);
		 }
		 double ans=0.0;
		 for(int i=0;i<n;i++) {
			 int smaller=0;
			 for(int j=0;j<n;j++)if(i!=j&&vv[i][j]<min_vc[i])smaller++;
			 debug(i);
			 debug(smaller);
			 ans+=sqrt(1.0*min_vc[i])/(smaller+1);

			 for(int j=0;j<n;j++) {
				 if(i==j)continue;
				 if(min_vc[i]<=vv[i][j])continue;
				 int smaller=0;
				 for(int k=0;k<n;k++) {
					 if(k==i||k==j)continue;
					 if(myless(i,k,j))smaller++;
				 }
				 debug(i);
				 debug(j);
				 debug(smaller);
				 ans+=sqrt(1.0*vv[i][j])/(smaller+1)/(smaller+2);
			 }
		 }
		 return ans;
	}
};
