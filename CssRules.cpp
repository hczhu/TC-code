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
const int N=201;
const int M=1<<9;
const string colors[]={"black","blue","gray","green","red","white","yellow"};
int name2idx[1000];
map<string,int> color2id;
bool solved[N];
int dp[N][M];
struct tag_t {
  int id,name,color;
};
tag_t parseTag(const char* ptr){
  assert(*ptr=='<');
  tag_t res;
  res.name=name2idx[*(ptr+1)];
  const char* p=strchr(ptr,':')+1;
  string cc(p,strchr(p,'\'')-p);
  assert(color2id.count(cc));
  res.color=color2id[cc];
  return res;
}
int buf[M];
int sorted_buf[M];
bool cmp(int a,int b) {
  return buf[a]<buf[b];
}
tag_t all_tag[N];
int diff[M][M];
class CssRules {
 public:
  int getMinimalCssRuleCount(vector <string> xthml) {
    name2idx['b']=0;
    name2idx['u']=1;
    name2idx['i']=2;
    for(int i=0;i<7;i++) {
      color2id[colors[i]]=i;
    }
    for(int a=0;a<M;a++)
      for(int b=0;b<M;b++) {
        diff[a][b]=0;
        int c=a^b;
        while(c) diff[a][b]+=c&0x7?1:0,c>>=3;
      }
    for(int i=0;i<M;i++) sorted_buf[i]=i;
    int tag_cnt=1;
    const string text=accumulate(xthml.begin(),xthml.end(),string(""));
    vector<int> st;
    int ans=0;
    const char *cur=text.c_str(),*next;
    tag_t tag;
    while(next=strchr(cur,'<')) {
      if(*(next+1)=='/') {
        memset(buf,0,sizeof(buf));
        int id=-1;
        for(int i=st.size()-1;i>=0;i--) {
          if(!solved[st[i]]) {
            id=st[i];
            break;
          }
        }
        assert(id!=-1);
        while(solved[st.back()]) {
          int son=st.back();
          st.pop_back();
          for(int i=0;i<M;i++) buf[i]+=dp[son][i];
        }
        sort(sorted_buf,sorted_buf+M,cmp);
        for(int i=0;i<M;i++) {
          dp[id][i]=buf[i];
          int& re=dp[id][i];
          for(int j=0;j<M&&buf[sorted_buf[j]]<re;j++) {
            re=min(re,diff[sorted_buf[j]][i]+buf[sorted_buf[j]]);
          }
          re+=((i>>(all_tag[id].name*3))&0x7)==all_tag[id].color?0:1;
        }
        solved[id]=true;
        cout<<"solved #"<<id<<endl;
      }
      else {
        tag=parseTag(next);
        tag.id=tag_cnt;
        all_tag[tag_cnt++]=tag;
        st.push_back(tag.id);
      }
      cur=next+1;
    }
    while(st.size()) {
      ans+=dp[st.back()][M-1];
      st.pop_back();
    }
    return ans;
  }
};
