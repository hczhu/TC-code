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
typedef vector<double> vd;
class MuddyRoad {
	public:
	 double getExpectedValue(vector <int> a) {
     int n=SZ(a);
     vd r(n);
     Rep(i,n) r[i] =1.0*a[i]/100.0;
     double dpt[55];
     dpt[0]=dpt[1]=0.0;
     for(int i=2;i<=n-1;i++) {
       dpt[i]=0;
       dpt[i]+=(1-r[i-1])*min(dpt[i-2]+r[i-2],dpt[i-1]);
       dpt[i]+=r[i-1]*min(dpt[i-2]+r[i-2],dpt[i-1]+1);
     }
     return dpt[n-1];
	}
};
template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
  debug(ss);
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
  debug(re.size());
	return re;
}
int main() {
  char line[1000];
  gets(line);
  MuddyRoad muddy;
  cout<<muddy.getExpectedValue(parse<int>(string(line),","))<<endl;
  return 0;
}
