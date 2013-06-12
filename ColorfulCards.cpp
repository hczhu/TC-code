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
int primeSieve(int factor[],int prime[],int n)
{
	int top=0;
	memset(factor,0,sizeof(int)*(n+1));
  factor[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(0==factor[i])prime[top++]=i;
		for(int j=0;j<top&&prime[j]*i<=n;j++)
		{
			factor[prime[j]*i]=prime[j];
			if(0==(i%prime[j]))break;
		}
	}
	return top;
}
int fact[10000],prime[10000];
int aa[10000],bb[10000];
bool check(string color,int a,int b) {
  if(color.empty())return true;
  if(a>b)return false;
  for(int i=0,j=a;i<color.length();i++) {
    while(j<=b&&(color[i]=='R'&&fact[j])||(color[i]=='B'&&fact[j]==0))j++;
    if(j>b)return false;
    j++;
  }
  return true;
}
class ColorfulCards {
	public:
	 vector <int> theCards(int N, string colors) {
		 debug("Start calculation.");
     int top=primeSieve(fact,prime,N);
     debug(top);
     const int n=colors.length();
     vector<int> res(colors.length(),-1);
     aa[1]=0;
     for(int i=2;i<=N;i++)aa[i]=aa[i-1]+(fact[i]==0?1:0);
     for(int i=0;i<n;i++) {
       int cnt=0;
       int pre=0,next=0;
       for(int j=0;j<=i;j++)if(colors[j]=='R')pre++;
       for(int j=i+1;j<n;j++)if(colors[j]=='R')next++;
       debug(i);
       debug(pre);
       debug(next);
       for(int x=1;x<=N&&cnt<2;x++) {
         if((colors[i]=='R'&&0==fact[x])||(colors[i]=='B'&&fact[x])) {
           if(check(colors.substr(0,i),1,x-1)&&check(colors.substr(i+1),x+1,N)) {
             res[i]=x;
             cnt++;
             debug(x);
           }
         }
       }
       debug(cnt);
       assert(cnt>0);
       if(cnt>1) {
         res[i]=-1;
       }
     }
     return res;
	}
};
