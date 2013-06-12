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
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif

bool DFS(int pos,vector<int>& pick,const string& sig,set<int> remain) {
  if(pos==sig.length()) return true;
  int bigger_than=0;
  for(int i=pos+1;i<sig.length()&&sig[i]=='D';i++) bigger_than++;
  for(set<int>::iterator itr=remain.begin();itr!=remain.end();itr++) {
    if(bigger_than==0&&((pick.back()<*itr&&sig[pos]=='I')||(pick.back()>*itr&&sig[pos]=='D'))) {
      pick.push_back(*itr);
      set<int> next=remain;
      next.erase(next.find(*itr));
      if(DFS(pos+1,pick,sig,next))return true;
      pick.pop_back();
    }
    if(bigger_than)bigger_than--;
  }
  return false;
}
class PermutationSignature {
 public:
  vector <int> reconstruct(string signature) {
    /*
    signature.clear();
    srand(time(NULL));
    for(int i=0;i<50;i++) {
      signature+=(rand()%2)?"D":"I";
    }*/
    debug(signature);
    for(int i=1;i<=signature.length()+1;i++) {
      vector<int> ans(1,i);
      set<int> remain;
      for(int j=1;j<=signature.length()+1;j++) {
        if(j!=i)remain.insert(j);
      }
      if(DFS(0,ans,signature,remain)) return ans;
    }
    return vector<int>();
  }
};
