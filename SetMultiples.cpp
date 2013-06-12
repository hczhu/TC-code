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
template<typename T>
vector<pair<T,T> >  interval_union(vector<pair<T,T> > all) {
	vector<pair<T,T> > res;
	if(all.empty())return res;
	sort(all.begin(),all.end());
	res.push_back(all[0]);
	for(int i=1;i<all.size();i++) {
		if(all[i].first<=res.back().second) {
			res.back().second=max(res.back().second,all[i].second);
		}
		else {
			res.push_back(all[i]);
		}
	}
	return res;
}
class SetMultiples {
	public:
	 long long smallestSubset(long long A, long long B, long long C, long long D) {
		 debug("Start calculation.");
		 A=max(A,B/2+1);
		 C=max(C,D/2+1);
		 debug(A);debug(B);
		 debug(C);debug(D);
		 llint ans=B-A+1+D+1-C;
		 debug(ans);
		 if(B<2000000) {
			 for(llint x=A;x<=B;x++) {
				 llint k=(C+x-1)/x;
				 if(k*x<=D)ans--;
			 }
			 debug(ans);
			 return ans;
		 }
		 typedef pair<llint,llint> ppt;
		 vector<ppt> interval;
		 for(llint t=2;t*A<=D;t++) {
			 llint a=(C+t-1)/t;
			 llint b=D/t;
			 if(a<=b)interval.push_back(ppt(a,b));
		 }
		 interval=merge_interval(interval);
		 for(int i=0;i<interval.size();i++) {
			 llint x=max(A,interval[i].first);
			 llint y=min(B,interval[i].second);
			 if(x<=y)ans-=y+1-x;
			 cerr<<x<<"-->"<<y<<endl;
		 }
		 return ans;
	}
};
/*
int main() {
	SetMultiples sm;
	cout<<sm.smallestSubset(41, 29233, 576686, 6194477512LL)<<endl;
	return 0;
}
*/
