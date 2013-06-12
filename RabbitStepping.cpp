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
int stimulate(vector<int>& rabbit,const string& color) {
  int goleft=1;
  while(SZ(rabbit)>2) {
    vector<int> next(SZ(rabbit));
    Rep(i,SZ(rabbit)) {
      if(0==rabbit[i])continue;
      int j=0;
      if(i==0)j=1;
      else if(i>=SZ(rabbit)-2)j=i-1;
      else if(color[i]=='W')j=i-1;
      else if(color[i]=='B')j=i+1;
      else j=i-goleft;
      rabbit[i]--;
      next[j]++;
    }
    goleft=-goleft;
    rabbit.swap(next);
    Rep(i,SZ(rabbit)) if(rabbit[i]>1)rabbit[i]=0;
    rabbit.pop_back();
  }
  return rabbit[0]+rabbit[1];
}
double tot=0,sum=0;
void DFS(vector<int>& selected,int pos,int r,const string& color) {
  if(SZ(selected)==r) {
    tot+=1;
    vector<int> rabbit(SZ(color),0);
    Rep(i,SZ(selected)) rabbit[selected[i]]=1;
    sum+=stimulate(rabbit,color);
    return;
  }
  while(SZ(color)-pos+SZ(selected)>=r) {
    selected.push_back(pos);
    DFS(selected,pos+1,r,color);
    selected.pop_back();
    pos++;
  }
}
class RabbitStepping {
	public:
	 double getExpected(string field, int r) {
		 debug("Start calculation.");
     vector<int> selected;
     DFS(selected,0,r,field);
     debug(tot);
     debug(sum);
     return sum/tot;
	}
};
