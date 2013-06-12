#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <assert.h>
using namespace std;
typedef long long int llint;
llint aa[100],bb[100];
class FairDiceGame
{
	public:
	string getPlayer(int n, int want)
	{
		if(n>6)return "";
		for(int i=0;i<n;i++)aa[i]=1;
		llint a=n;
		for(int k=1;k<=want;k++,a*=5)
		{
			for(int i=0;i<n;i++)aa[i]*=6;
			for(int i=0;i<n;i++)
			{
				if(aa[i]>=a)
				{
					aa[i]-=a;
					if(k==want)
					{
						string res="A";
						res[0]=res[0]+i;
						return res;
					}
					break;
				}
			}
		}
		return "";
	};
	
};
