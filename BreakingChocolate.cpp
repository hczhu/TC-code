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
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i!=b;++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
struct node_t {
  int x1,x2,y1,y2;
  node_t(int a1=0,int a2=0,int b1=0,int b2=0) :x1(a1),x2(a2),y1(b1),y2(b2){};
  bool operator<(const node_t& other)const  {
    return memcmp(this,&other,sizeof(*this))<0;
  };
};
unsigned char cache[82][82][82][82];
//unsigned char cache[82*81/2][82*81/2];
bool have[200][200];
int sum[200][200];
set<pair<int,int> >mem;
#define SUM(x1,x2,y1,y2) sum[x2][y2]-sum[x2][y1]-sum[x1][y2]+sum[x1][y1]
#define IDX(x1,x2) ((((x2-1)*(x2))>>1)+x1)
int DP(int X,int Y) {
  for(int x1=X-1;x1>=0;x1--) {
    For(x2,x1+1,X) {
      for(int y1=Y-1;y1>=0;y1--) {
        For(y2,y1+1,Y) {
          int t=SUM(x1,x2,y1,y2);
          if(t==0||t==(x2-x1)*(y2-y1)) {
            continue;
          }
          int ans=300;
          //for(int x=x1+1;x<x2&&SUM(x1,x-1,y1,y2)<t;x++) {
          for(int x=x1+1;x<x2;x++) {
            ans=min(ans,1+cache[x1][x][y1][y2]+cache[x][x2][y1][y2]);
          }
          //for(int y=y1+1;y<y2&&SUM(x1,x2,y1,y-1)<t;y++) {
          for(int y=y1+1;y<y2;y++) {
            ans=min(ans,1+cache[x1][x2][y1][y]+cache[x1][x2][y][y2]);
          }
          cache[x1][x2][y1][y2]=ans;
        }
      }
    }
  }
  //debug(IDX(0,X-1));
  //debug(IDX(0,Y-1));
  return cache[0][X-1][0][Y-1];
}
class BreakingChocolate {
	public:
	 int minSteps(int W, int H, vector <int> sx, vector <int> sy) {
     debug(sizeof(cache));
		 debug("Start calculation.");
#define Uniq(vec)  sort(All(vec));vec.resize(unique(All(vec))-vec.begin())
    /* W=H=1000000000;
     sx.clear();sy.clear();
     Rep(i,10)sx.push_back(2*i+3),sy.push_back(2*i+3);*/
     vector<int> xx,yy;
     xx.push_back(0),xx.push_back(W);
     yy.push_back(0);yy.push_back(H);
     const int n=SZ(sx);
     For(itr,mem.begin(),mem.end())debug("a");
     Rep(i,n) {
       mem.insert(make_pair(sx[i]-1,sy[i]-1));
       xx.push_back(sx[i]);xx.push_back(sx[i]-1);
       yy.push_back(sy[i]);yy.push_back(sy[i]-1);
     }
     assert(SZ(mem)==n);
     Uniq(xx);Uniq(yy);
     debug(SZ(xx));
     debug(SZ(yy));
     Rep(i,SZ(xx)-1)Rep(j,SZ(yy)-1) {
    /*   debug(xx[i]);
       debug(yy[j]);
       debug(mem.count(make_pair(xx[i],yy[j])));*/
       have[i][j]=(xx[i]+1==xx[i+1])&&(yy[j]+1==yy[j+1])&&(mem.count(make_pair(xx[i],yy[j])));
       sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+(have[i][j]?1:0);
     }
     
     Rep(i,SZ(xx)) {
       Rep(j,SZ(yy)) {
         cerr<<sum[i][j]<<" ";
       }
       cerr<<endl;
     }
     debug("________________________");
     Rep(i,SZ(xx)-1) {
       Rep(j,SZ(yy)-1) {
         cerr<<have[i][j]<<" ";
       }
       cerr<<endl;
     }
     return DP(SZ(xx),SZ(yy));
	}
};

/*
int main() {
  BreakingChocolate br;
  cout<<br.minSteps(0,0,vector<int>(),vector<int>())<<endl;
  //cerr<<(SZ(cache))<<endl;
  return 0;
}

*/
