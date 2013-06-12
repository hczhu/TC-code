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
double dp[100000];
class FoxListeningToMusic {
	public:
	 vector <double> getProbabilities(vector <int> length, int T) {
		 debug("Start calculation.");
     dp[0]=1.0;
     double ef=1.0/length.size();
     for(int k=1;k<=T;k++) {
       for(int i=0;i<length.size();i++) {
         if(k>=length[i]) {
           dp[k]+=dp[k-length[i]]*ef;
         }
       }
     }
     vector<double> res(length.size(),0.0);
     double ans=0.0;
     for(int i=0;i<length.size();i++)
     for(int k=T;k+length[i]>T&&k>=0;k--) {
       res[i]+=dp[k]*ef;
     }
     return res;
	}
};
