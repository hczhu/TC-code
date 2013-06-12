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
#define Foreach(itr,con) typedef typeof(con) _type_of_ ## con; for(_type_of_ ## con::iterator itr=con.begin();itr!=con.end();++itr)
template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
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
	return re;
}
typedef long long int llint;
typedef vector<string> IP;
llint get_union(vector<IP> ip,int pos=0) {
  debug(pos);
  debug(SZ(ip));
  if(ip.empty())return 0;
  map<string,vector<IP> > rindex;
  Rep(i,SZ(ip)) {
    rindex[ip[i][pos]].push_back(ip[i]);
  }
  if(pos==3) {
    return rindex.count("*")?1000:SZ(rindex);
  }
  if(0==rindex.count("*"))rindex["*"]=vector<IP>();
  llint ans=0;
  Foreach(itr,rindex) {
    vector<IP> next=itr->second;
    if(itr->first!="*") {
      copy(All(rindex["*"]),back_inserter(next));
    }
    llint t=get_union(next,pos+1);
    if(itr->first=="*")t*=1000LL-(SZ(rindex)-1);
    ans+=t;
  }
  /*
  Rep(i,SZ(ip)) {
    copy(All(ip[i]),ostream_iterator<string>(cerr,"."));
    cerr<<" ";
  }
  cerr<<endl<<pos<<"="<<ans<<endl;*/
  return ans;
}
class IPv444 {
	public:
	 long long getMaximumMoney(vector <string> request, vector <int> price) {
		 debug("Start calculation.");
     typedef pair<int,string> ppt;
     const int n=SZ(request);
     vector<ppt> all(n);
     Rep(i,n) {
       all[i]=ppt(price[i],request[i]);
     }
     sort(All(all));
     reverse(All(all));
     llint ans=0;
     llint out=0;
     vector<IP> current;
     Rep(i,n) {
       current.push_back(parse<string>(all[i].second,"."));
       assert(4==SZ(current.back()));
       llint nn=get_union(current);
       debug(nn);
       ans+=(nn-out)*(llint)all[i].first;
       out=nn;
     }
     return ans;
	}
};
