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
typedef pair<int,int> pp;
class DrawingLines {
	public:
	double countLineCrossings(int n, vector <int> start, vector <int> end) 
	{
		vector<pp> all;
		for(int i=0;i<start.size();i++)
			all.push_back(pp(start[i],end[i]));
		sort(all.begin(),all.end());
		double ans=0;
		const int m=all.size();
		for(int i=0;i<all.size();i++)
		for(int j=i+1;j<m;j++)
			if(all[i].second>all[j].second)ans++;
		debug(ans);
		ans+=(n-m)*(n-m-1)/2*0.5;
		debug(ans);
		for(int i=0;i<m;i++)
		{
			int x=all[i].first;
			int y=all[i].second;
			int pre=y-1,next=n-y;
			for(int j=0;j<m;j++)
			{
				if(all[j].second<y)pre--;
				if(all[j].second>y)next--;
			}
			cerr<<x<<" "<<y<<" "<<pre<<" "<<next<<endl;
			ans+=1.0*(x-1-i)*next/(pre+next);
			ans+=1.0*(n-x-(m-1-i))*pre/(pre+next);
			debug(ans);
		}
		return ans;
	}
};
