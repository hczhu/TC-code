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
typedef long long int llint;
class SlimeXSlimesCity {
	public:
	 int merge(vector <int> pop) {
		 debug("Start calculation.");
     int ans=0;
     sort(pop.begin(),pop.end());
     for(int i=0;i<pop.size();i++) {
       bool ok=true;
       llint s=accumulate(pop.begin(),pop.begin()+i+1,llint(0));
       for(int j=i+1;ok&&j<pop.size();j++) {
         if(s<pop[j])ok=false;
         s+=pop[j];
       }
       if(ok) {
         debug(pop[i]);
         ans++;
       }
     }
     return ans;
	}
};
