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
const int up=500;
bool visited[2][up+1];
class SquareSeries {
	public:
    int forward(string pat) {
      if(pat.empty())return 0;
      int res=1;
      for(int i=1;i<pat.length()&&res>0;i++) {
        if(pat[i]!=pat[i-1])res++;
        else res--;
      }
      return res;
    }
    int backward(string pat,int res) {
      if(pat.empty())return 0;
      for(int i=pat.length()-1;i>0&&res>0;i--) {
        if(pat[i]==pat[i-1])res++;
        else res--;
      }
      return res;
    }
    typedef pair<string,int> ppt;
	 string completeIt(string pat, int last) {
		 debug("Start calculation.");
     const string cannot="...";
     int pos=pat.find('?');
     string prefix=pat.substr(0,pos);
     string suffix=pat.substr(pos+1);
     if(forward(prefix+suffix)==last)return prefix+suffix;
     if(forward(prefix+"B"+suffix)==last)return prefix+"B"+suffix;
     if(forward(prefix+"W"+suffix)==last)return prefix+"W"+suffix;
     int sb=backward("B"+suffix,last);
     int sw=backward("W"+suffix,last);
     debug(sb);
     debug(sw);
     string name="BW";
     queue<ppt> Q;
     int ww,bb;
     bb=forward(prefix+"B");
     ww=forward(prefix+"W");
     if(bb)Q.push(ppt("B",bb)),visited[0][bb]=true;
     if(ww)Q.push(ppt("W",ww)),visited[1][ww]=true;
#define Tail(str) (str[str.length()-1])
     int hash[1000];hash['B']=0,hash['W']=1;
     for(int step=1;Q.size();step++) {
       debug(step);
       vector<ppt> leaf[2];
       for(int k=Q.size();k>0;k--) {
         ppt v=Q.front();Q.pop();
         cerr<<v.first<<" "<<v.second<<endl;
         if(Tail(v.first)=='B'&&v.second==sb)return prefix+v.first+suffix;
         if(Tail(v.first)=='W'&&v.second==sw)return prefix+v.first+suffix;
         for(int i=0;i<2;i++) {
           ppt next=v;
           next.second+=(name[i]==Tail(next.first))?-1:1;
           next.first.push_back(name[i]);
           if(next.second>0&&next.second<=up&&!visited[i][next.second]) {
             leaf[i].push_back(next);
             visited[i][next.second]=true;
           }
         }
         if(k==1||v.first<Q.front().first) {
           for(int i=0;i<2;i++) {
             while(leaf[i].size()) {
               Q.push(leaf[i].back());
               leaf[i].pop_back();
             }
           }
         }
       }
     }
     return cannot;
	}
};
/*
int main() {
  SquareSeries sq;
  string ss;
  int last;
  cin>>ss>>last;
//  cout<<sq.completeIt(ss,last)<<endl;
  ss=sq.completeIt(ss,last);
  assert(ss=="..."||sq.forward(ss)==last);
  debug(ss);
  return 0;
}
*/
