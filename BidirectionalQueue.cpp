#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
#include	<vector>
#include	<string>
#include	<algorithm>
using namespace std;
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
#include <assert.h>
using namespace std;
typedef long long int llint;
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
#define PB(x) push_back((x))
#define SORT(x) sort(x.begin(),x.end())
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
	#define print(x)  cerr<<(x)<<endl;
#else
    #define debug(x)
    #define hline()
	#define print(x)
#endif

struct BidirectionalQueue 
{
	int extractElements(int n, vector <int> indices);
};

int BidirectionalQueue::extractElements(int n, vector <int> want)
{
	int num[100];
	for(int i=1;i<=n;i++)num[i-1]=i;
	int p=0;
	int res=0,rem=n;
	for(int i=0;i<want.size();i++)
	{
		int ind=want[i];
		int move=0;
		while(num[p]!=ind)
		{
			if(num[p])move++;
			p=(p+1)%n;
		}
		debug(p);
		debug(num[p]);
		debug(move);
		res+=min(move,rem-move);
		rem--;
		num[p]=0;
	}
	return res;
}
