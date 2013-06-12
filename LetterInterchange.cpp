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
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif

bool cmp(vector<int> pa,vector<int> pb,const string& all)
{
	string sa("aa"),sb("aa");
	for(int i=0;i<pa.size();i++)
		sa[i]=all[pa[i]],sb[i]=all[pb[i]];
	swap(sa[0],sa[1]);
	swap(sb[0],sb[1]);
	for(int i=0,j=0;i<2||j<2;)
	{
		if(i==2)
		{
			if(all[pb[j]]!=sb[j])return all[pb[j]]<sb[j];
			j++;
		}
		else if(j==2)
		{
			if(sa[i]!=all[pa[i]])return sa[i]<all[pa[i]];
			i++;
		}
		else if(pa[i]==pb[j])
		{
			if(sa[i]!=sb[j])return sa[i]<sb[j];
			i++;j++;
		}
		else if(pa[i]<pb[j])
		{
			if(sa[i]!=all[pa[i]])return sa[i]<all[pa[i]];
			i++;
		}
		else
		{
			if(all[pb[j]]!=sb[j])return all[pb[j]]<sb[j];
			j++;
		}
	}
	return false;
}

class LetterInterchange {
//Review your code before submission!!!!
	public:
	vector <int> interchangeWhich(vector <string> s1, vector <string> s2) {
		string all=accumulate(s1.begin(),s1.end(),string(""));
		all+=accumulate(s2.begin(),s2.end(),string(""));
		debug(all);
		vector<int> res(2);
		const int n=all.length();
		res[0]=n-2,res[1]=n-1;
		int low=n-1,high=n-1;
		char best=all[n-1];
		for(int i=n-2;i>=0;i--)
		{
			vector<int> pa(2);pa[0]=i;
			if(all[i]<=best)pa[1]=low;
			else pa[1]=high;
			if(!cmp(res,pa,all))res=pa;
			if(all[i]<best)best=all[i],low=high=i;
			else if(all[i]==best)low=min(low,i),high=max(i,high);
		}
		return res;
	}
};
