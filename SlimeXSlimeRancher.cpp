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
#define NDEBUG
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
typedef pair<llint,int> ppt;
vector<ppt> vec[3];
vector<int> tmp[3];
llint dp[151][151][151];
bool have[3][1000];
map<llint,int> conv;
int n;
const llint inf=100000000000000000LL;
void add_one(int idx,int num,llint s[3],int cnt[3]) {
  assert(!have[idx][num]);
  s[idx]+=tmp[idx][num];
  have[idx][num]=true;
  cnt[idx]++;
  if(have[0][num]&&have[1][num]&&have[2][num]) {
    for(int i=0;i<3;i++)s[i]-=tmp[i][num],have[i][num]=false,cnt[i]--;
  }
}
void remove_one(int idx,int num,llint s[3],int cnt[3]) {
  if(!have[idx][num]) {
    for(int i=0;i<3;i++)assert(!have[i][num]);
    for(int i=0;i<3;i++) if(i!=idx) s[i]+=tmp[i][num],have[i][num]=true,cnt[i]++;
  }
  else {
    have[idx][num]=false;
    s[idx]-=tmp[idx][num];
    cnt[idx]--;
    assert(cnt[idx]>=0);
    assert(s[idx]>=0);
  }

}
llint DP(int idx[3],llint s[3],int cnt[3]) {
  if(idx[0]==n&&idx[1]==n&&idx[2]==n)return 0;
  llint& res=dp[idx[0]][idx[1]][idx[2]];
  if(res>=0)return res;
  res=inf;
  for(int i=0;i<3;i++) {
    if(idx[i]<n) {
      //cerr<<i<<" "<<idx[i]<<" "<<vec[i][idx[i]].first<<" "<<cnt[i]<<" "<<s[i]<<endl;
      llint add=cnt[i]?(vec[i][idx[i]].first-vec[i][idx[i]-1].first)*cnt[i]:0;
      assert(add>=0);
      add_one(i,vec[i][idx[i]].second,s,cnt);idx[i]++;
      res=min(res,DP(idx,s,cnt)+add);
      idx[i]--;remove_one(i,vec[i][idx[i]].second,s,cnt); 
    }
  }
  //cerr<<idx[0]<<" "<<idx[1]<<" "<<idx[2]<<"="<<res<<endl;
  return res;
}
class SlimeXSlimeRancher {
	public:
	 long long train(vector <string> aa, vector <string> bb, vector <string> cc) {
		 debug("Start calculation.");
     tmp[0]=parse<int>(accumulate(aa.begin(),aa.end(),string("")));
     tmp[1]=parse<int>(accumulate(bb.begin(),bb.end(),string("")));
     tmp[2]=parse<int>(accumulate(cc.begin(),cc.end(),string("")));
     const int n=tmp[0].size();
     ::n=n;
     for(int i=0;i<3;i++) {
       for(int j=0;j<n;j++) {
         vec[i].push_back(ppt(tmp[i][j],j));
       }
       sort(vec[i].begin(),vec[i].end());
       //sort(tmp[i].begin(),tmp[i].end());
     }
     memset(dp,0xff,sizeof(dp));
     int idx[]={0,0,0};
     llint s[]={0,0,0};
     int cnt[]={0,0,0};
     return DP(idx,s,cnt);
	}
};
