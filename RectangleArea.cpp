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

typedef vector<string> grid;
grid trans(const grid& a) {
  grid b;
  for(int i=0;i<a[0].length();i++) {
    string t(a.size(),'a');
    for(int j=0;j<a.size();j++)t[j]=a[j][i];
    b.push_back(t);
  }
  return b;
}
grid merge_line(grid& a,int x,int y) {
  if(x>y)swap(x,y);
  grid b;
  for(int i=0;i<a.size();i++) {
    if(i==y)continue;
    for(int j=0;j<a[i].length();j++) {
      if(i==x)a[x][j]=(a[x][j]=='Y')?'Y':a[y][j];
    }
    b.push_back(a[i]);
  }
  debug(b.size());
  return b;
}
class RectangleArea {
	public:
	int minimumQueries(vector <string> A) {
          int Y;
          while(true) {
            bool f=false;
            for(int cc=0;cc<2;cc++) {
              Y=0;
              for(int c=0;c<A[0].length();c++) {
                int pre=-1;
                for(int r=0;r<A.size();r++) {
                  debug(r);
                  debug(c);
                  if(A[r][c]=='Y') {
                    Y++;
                    if(pre!=-1) {
                      f=true;
                      cerr<<pre<<" VS "<<r<<endl;
                      A=merge_line(A,pre,r);
                      goto end;
                    }
                    pre=r;
                  }
                }
              }
              A=trans(A);
            }
end:        
            debug(A.size());
            debug(A[0].length());
            for(int i=0;i<A.size();i++)debug(A[i]);
            if(!f)break;
          }
          return A.size()+A[0].length()-1-Y;
	}
};
