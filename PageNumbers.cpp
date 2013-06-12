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
#define NDEBUG
#include <assert.h>
using namespace std;
int ten[10];
class  PageNumbers
{
	public:
	vector <int> getCounts(int n)
	{
		ten[0]=1;
		for(int i=1;i<10;i++)ten[i]=10*ten[i-1];
		vector<int> res(10,0);
		int top=0,dig[20];
		while(n)dig[top++]=n%10,n/=10;
		for(int i=1;i<top;i++)
		{
			for(int k=1;k<10;k++)res[k]+=ten[i-1];
			for(int j=1;j<i;j++)
			for(int k=0;k<10;k++)
				res[k]+=9*ten[i-2];
		}
		for(int i=top-1;i>=0;i--)
		{
			int d=dig[i];
			for(int k=(i==top-1)?1:0;k<d;k++)
			{
				res[k]+=ten[i];
				for(int j=top-1;j>i;j--)
					res[dig[j]]+=ten[i];
				if(i)
				{
					for(int j=0;j<10;j++)
						res[j]+=i*ten[i-1];
				}
			}
		}
		for(int i=0;i<top;i++)res[dig[i]]++;
		return res;
	};
	
};
