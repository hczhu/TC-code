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
#include <stack>
#include <stdarg.h>
//#define NDEBUG
#include <assert.h>
#include <limits>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<b;++i)

int rem[1000],add[1000],change[500][500];
int dp[100][100];
const int inf=numeric_limits<int>::max()/3;
class PalindromizationDiv1 {
	public:
	int getMinimumCost(string word, vector <string> ope) {
          fill(rem,rem+1000,inf);
          fill(add,add+1000,inf);
          For(a,'a','z'+1)For(b,'a','z'+1)change[a][b]=inf,change[a][a]=0;
          Rep(i,SZ(ope)) {
            istringstream is(ope[i]);
            string a,b,c;
            int x;
            if(ope[i][0]=='a') {
              is>>a>>b>>x;
              add[b[0]]=x;
            }
            else if(ope[i][0]=='e') {
              is>>a>>b>>x;
              rem[b[0]]=x;
            }
            else {
              is>>a>>b>>c>>x;
              change[b[0]][c[0]]=x;
            }
          }
      For(k,'a','z'+1)For(i,'a','z'+1)For(j,'a','z'+1)
          change[i][j]=min(change[i][j],change[i][k]+change[k][j]);
      For(a,'a','z'+1)For(b,'a','z'+1) {
        rem[a]=min(rem[a],change[a][b]+rem[b]);
        add[a]=min(add[a],add[b]+change[b][a]);
      }
      for(char a='a';a<='z';a++)cerr<<a<<" "<<rem[a]<<" " <<add[a]<<endl;
      cerr<<"-------------"<<endl;
      for(char a='a';a<='z';a++,cerr<<endl)for(char b='a';b<='z';b++)cerr<<change[a][b]<<" ";

      int ans=inf;
      For(len,1,SZ(word))Rep(i,SZ(word)-len) {
        int j=i+len;
        int& res=dp[i][j];res=inf;
#define Update(x) res=min(res,x)
        //if(word[i]==word[j])Update(res,dp[i+1][j-1]);
        char a=word[i],b=word[j];
        Update(rem[a]+dp[i+1][j]);
        Update(rem[b]+dp[i][j-1]);
        For(c,'a','z'+1) {
          Update(change[a][c]+change[b][c]+dp[i+1][j-1]);
          Update(change[a][c]+add[c]+dp[i+1][j]);
          Update(change[b][c]+add[c]+dp[i][j-1]);
        }
      }
      ans=dp[0][SZ(word)-1];
      return ans==inf?-1:ans;
    }
};
