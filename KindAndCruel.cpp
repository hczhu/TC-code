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
class KindAndCruel {
	public:
	 int crossTheField(string fd, int K, int C) {
		 debug("Start calculation.");
     const int n=fd.length();
     vector<bool> cur(n,false),next(n,false);
     cur[0]=true;
     for(int ans=1;ans<=50*50*51;ans++) {
       next=vector<bool>(n,false);
       for(int i=0;i<n;i++) {
#define Good(x,t) (fd[x]=='.'||(fd[x]=='K'&&((t)%K))||(fd[x]=='C'&&(((t)%C)==0)))
         if(!cur[i])continue;
         if(Good(i,ans))next[i]=true;
         if(i&&Good(i-1,ans))next[i-1]=true;
         if(i+1<n&&Good(i+1,ans))next[i+1]=true;
#undef Good
       }
       cur.swap(next);
       if(cur.back())return ans;
     }
     return -1;
	}
};
