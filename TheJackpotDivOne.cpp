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
typedef long long int llint;
class TheJackpotDivOne {
	public:
	 vector<long long> find(vector<long long> money, long long jack) {
		 debug("Start calculation.");
     const int n=money.size();
     int cnt=0;
     for(int i=0;i<n;i++)cerr<<money[i]<<" ";cerr<<endl;
     for(;jack>0;cnt++) {
       int a=min_element(money.begin(),money.end())-money.begin();
       int b=max_element(money.begin(),money.end())-money.begin();
       if(money[a]==money[b]) {
         break;
       }
       llint sa=0,sb=0;
       for(int i=0;i<n;i++) {
         sa+=money[i]/n;
         sb+=money[i]%n;
       }
       sa+=(sb+n)/n;
       llint x=min(sa-money[a],jack);
       //debug(x);
       money[a]+=x;
       jack-=x;
     }
     debug(cnt);
     for(int i=0;i<n;i++) {
       money[i]+=jack/(n-i);
       jack-=jack/(n-i);
     }
     sort(money.begin(),money.end());
     return money;
	}
};
/*
int main() {
  srand(time(NULL));
  for(int cc=0;cc<100000;cc++) {
  int n;
  //cin>>n;
  n=50;
  vector<llint> num(n);
  //for(int i=0;i<n;i++)cin>>num[i];
  for(int i=0;i<n;i++)num[i]=(llint)(rand()%1000000000)*(llint)(rand()%1000000000);
  for(int i=0;i<n/2;i++)num[i]=rand()%100;
  TheJackpotDivOne the;
  the.find(num,1000000000000000000LL);
  }
  return 0;
}
*/
