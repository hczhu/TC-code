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

const int M=2000;
int next[M+1];
int cnt[M+1];

int get_next(int a)
{
	return next[a]==-1?a:(next[a]=get_next(next[a]));
}
class Sheep {
	public:
	int minCapacity(int numSheep, int maxRuns, vector <string> part1, vector <string> part2, vector <string> part3, vector <string> part4) {
		string all=accumulate(part1.begin(),part1.end(),string(""))
					+accumulate(part2.begin(),part2.end(),string(""))
					+accumulate(part3.begin(),part3.end(),string(""))
					+accumulate(part4.begin(),part4.end(),string(""));
		debug(all);
		vector<int> weight;
		istringstream is(all);
		int x;
		while(is>>x)weight.push_back(x);

	//	while(numSheep<2000)numSheep++,weight.push_back(1+(rand()%2000));
	
		assert(weight.size()==numSheep);
		const int upper=accumulate(weight.begin(),weight.end(),0);
		const int lower=*max_element(weight.begin(),weight.end());
    int ans=upper;
    for(int r=0;r<lower;r++) {
      int low=((lower-r)+lower-1)/lower;
      int high=((ans-r)+lower-1)/lower;
			while(low<high)
			{
				int mid=(low+high)>>1;
				memset(cnt,0,sizeof(cnt));
				memset(next,0xff,sizeof(next));
				for(int i=0;i<weight.size();i++)
				{
					cnt[weight[i]]++;
				}
				for(int i=1;i<=M;i++)
				{
					next[i]=cnt[i]?-1:i-1;
				}
				int n=numSheep;
				for(int k=0;k<maxRuns&&n>0;k++)
				{
					int rem=mid*lower+r;
					int w;
					while((w=get_next(min(rem,M))))
					{
						assert(w<=M);
						assert(w<=rem);
						rem-=w;
						assert(cnt[w]>0);
						cnt[w]--;n--;
						if(cnt[w]==0)next[w]=w-1;
					}
					assert(next[0]==-1);
				}

				debug(low);
				debug(high);
				debug(mid);
				debug(n);
				if(n==0)high=mid;
				else low=mid+1;
			}
      ans=min(low*lower+r,ans);
    }
		return ans;
	}
};
