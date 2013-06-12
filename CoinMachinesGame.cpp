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
const int M=1000000;
int dp[M+1];
class CoinMachinesGame {
	public:
	 int maxGames(int coins, vector <int> need, vector <int> give) {
		 debug("Start calculation.");
     const int n=need.size();
     vector<pair<int,int> > all;
     for(int i=0;i<n;i++) {
       all.push_back(make_pair(need[i],give[i]));
     }
     sort(all.begin(),all.end(),less<pair<int,int> >());
     for(int i=0;i<n;i++) {
       int a=all[i].first,b=all[i].second;
       debug(a);
       for(int k=a;k<=M;k++) {
         dp[k]=max(dp[k],dp[k-a+b]+1);
       }
     }
     if(coins<=M)return dp[coins];
     int best=0;
     for(int i=1;i<n;i++) {
       if(make_pair(need[i]-give[i],need[i])<make_pair(need[best]-give[best],need[best]))
         best=i;
     }
     debug(best);
     int have=coins-M/2;
     coins=M/2;
     int ans=(have-need[best])/(need[best]-give[best]);
     have-=ans*(need[best]-give[best]);
     while(have>=need[best]) {
       have-=need[best]-give[best];
       ans++;
     }
     coins+=have;
     debug(coins);
     debug(ans);
     assert(coins<=M);
     return ans+dp[coins];
	}
};
