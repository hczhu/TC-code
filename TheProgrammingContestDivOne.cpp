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
llint aa[1000],bb[1000],cc[1000];
int sindex[1000];
bool cmp(int a,int b) {
	return cc[a]*bb[b]<cc[b]*bb[a];
}
int dp[51][100001];
int get_score(int idx,int t) {
	if(aa[idx]<bb[idx]*t)return 0;
	return aa[idx]-bb[idx]*t;
}
class TheProgrammingContestDivOne {
	public:
	 int find(int T, vector <int> aa, vector <int> bb, vector <int> cc) {
		 debug("Start calculation.");
		 const int n=aa.size();
		 for(int i=0;i<n;i++) {
			 ::aa[i]=aa[i];
			 ::bb[i]=bb[i];
			 ::cc[i]=cc[i];
			 sindex[i]=i;
		 }
		 sort(sindex,sindex+n,cmp);
		 for(int i=1;i<=n;i++) {
			 int *cur=dp[i];
			 int *pre=dp[i-1];
			 int idx=sindex[i-1];
			 debug(idx);
			 for(int t=0;t<=T;t++) {
				 cur[t]=pre[t];
				 if(t>=cc[idx]) {
					 cur[t]=max(cur[t],pre[t-cc[idx]]+get_score(idx,t));
				 }
			 }
		 }
		 return *max_element(dp[n],dp[n]+T+1);
	}
};
