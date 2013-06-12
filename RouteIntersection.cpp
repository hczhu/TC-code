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
//INT_MAX INT_MIN
#include <limits.h>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
class RouteIntersection {
	public:
	 string isValid(int N, vector <int> coords, string moves) {
		 debug("Start calculation.");
     const int m=SZ(coords);
     map<int,int> hash;
     Rep(i,m)hash[coords[i]]=i;
     set<vector<int> > mem;
     vector<int> pos(m,0);
     mem.insert(pos);
     Rep(i,m) {
       int add=1;
       if(moves[i]=='-')add=-1;
       pos[hash[coords[i]]]+=add;
       if(mem.count(pos))return "NOT VALID";
       mem.insert(pos);
     }
     return "VALID";
	}
};
