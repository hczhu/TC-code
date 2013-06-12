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

typedef long long int llint;
vector<int> all;
int sum(llint n)
{
	int res=0;
	while(n)res+=n%10,n/=10;
	return res;
}
void DFS(llint prefix)
{
	if(prefix>1000000000)return;
	if(sum(prefix)*sum(prefix)==sum(prefix*prefix))
	{
		all.push_back(prefix);
		debug(prefix);
	}
	for(int d=(prefix?0:1);d<=3;d++)
	{
		DFS(prefix*10+d);
	}
}
class RabbitNumber {
	public:
	int theCount(int low, int high) 
	{
		int res=0;
		DFS(0);
		for(int i=0;i<all.size();i++)
			if(all[i]>=low&&all[i]<=high)res++;
		return res;
	}
};
/*
int main()
{
	DFS(0);
	debug(all.size());
	return 0;
}
*/
