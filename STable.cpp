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
#define Foreach(itr,con) typedef typeof(con) _type_of_ ## con; for(_type_of_ ## con::iterator itr=con.begin();itr!=con.end();++itr)
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
typedef long long int llint;
const int N=50;
llint len[N][N];
int rank[N][N];
char head[N][N];
typedef pair<char,int> ppt;
typedef pair<int,int> xyt;

string recur(const int r,const int c,llint pos,llint ll) {
  assert(ll<=len[r][c]-pos);
  assert(pos<len[r][c]);
  if(0==ll)return "";
  if(0==r*c) {
    assert(ll==1);
    assert(pos==0);
    string res(1,head[r][c]);
    return res;
  }
     const int dr[2]={0,-1};
     const int dc[2]={-1,0};
       int a=0,b=1;
       if(rank[r+dr[a]][c+dc[a]]>rank[r+dr[b]][c+dc[b]]) {
         swap(a,b);
       }
       //debug(r);debug(c);debug(a);
       int ra=r+dr[a],ca=c+dc[a];
       int rb=r+dr[b],cb=c+dc[b];
       string res="";
       if(pos<len[ra][ca]) {
         res+=recur(ra,ca,pos,min(ll,len[ra][ca]-pos));
         assert(SZ(res)==min(ll,len[ra][ca]-pos));
       }
       if(pos+ll>len[ra][ca]) {
         string t=recur(rb,cb,max(0LL,pos-len[ra][ca]),pos+ll-max(pos,len[ra][ca]));
         res+=t;
       }
       cerr<<r<<" "<<c<<" "<<pos<<" "<<ll<<"="<<res<<endl;
       assert(ll==SZ(res));
       return res;
}
class STable {
	public:
	 string getString(string ss, string tt, long long pos) {
		 debug("Start calculation.");
     const int n=SZ(ss);
     const int m=SZ(tt);
     Rep(i,n) {
       len[i+1][0]=1;
       rank[i+1][0]=head[i+1][0]=ss[i];
     }
     Rep(i,m) {
       len[0][i+1]=1;
       rank[0][i+1]=head[0][i+1]=tt[i];
     }
     For(s,2,n+m+1) {
       map<ppt,xyt> mem;
       Rep(a,s+1) {
         int b=s-a;
         if(a>n||b>m)continue;
         if(a*b) {
           head[a][b]=min(head[a-1][b],head[a][b-1]);
           len[a][b]=len[a-1][b]+ len[a][b-1];
           rank[a][b]=(min(rank[a-1][b],rank[a][b-1])<<10)^max(rank[a-1][b],rank[a][b-1]);
         }
         mem[ppt(head[a][b],rank[a][b])]=xyt(a,b);
       }
       int rr=0;
       Foreach(itr,mem) {
         int a=itr->second.first;
         int b=itr->second.second;
         rank[a][b]=rr++;
       }
     }
     Rep(a,n+1) {
       Rep(b,m+1)cerr<<rank[a][b]<<" ";cerr<<endl;
     }
     debug("len");
     Rep(a,n+1) {
       Rep(b,m+1)cerr<<len[a][b]<<" ";cerr<<endl;
     }
     debug("head");
     Rep(a,n+1) {
       Rep(b,m+1)cerr<<head[a][b]<<" ";cerr<<endl;
     }
     llint ll=min(50LL,len[n][m]-pos);
     debug(ll);
     return recur(n,m,pos,ll);
	}
};
/*
int main() {
  STable st;
  string aa,bb;
  int pos;
  cin>>aa>>bb>>pos;
  cout<<st.getString(aa,bb,pos)<<endl;
}
*/
