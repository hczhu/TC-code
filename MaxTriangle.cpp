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
typedef long long int llint;


class MaxTriangle {
//Review your code before submission!!!!
	public:
	double calculateArea(int A, int B) 
	{
		const llint up=max(A,B);
		map<llint,llint> mem;
		for(llint x=0;x*x<=up;x++)mem[x*x]=x;
		vector<pair<llint,llint> > va,vb;
		for(llint x=0;x*x<=up;x++)
		{
			llint yy=A-x*x;
			if(mem.count(yy))
				va.push_back(make_pair(x,mem[yy])),
				va.push_back(make_pair(x,-mem[yy])),
				va.push_back(make_pair(-x,mem[yy])),
				va.push_back(make_pair(-x,-mem[yy]));

			yy=B-x*x;
			if(mem.count(yy))
				vb.push_back(make_pair(x,mem[yy])),
				vb.push_back(make_pair(x,-mem[yy])),
				vb.push_back(make_pair(-x,mem[yy])),
				vb.push_back(make_pair(-x,-mem[yy]));
		}
		debug(va.size());
		debug(vb.size());
		llint res=-2.0;
		for(int i=0;i<va.size();i++)
		for(int j=0;j<vb.size();j++)
		{
			//cerr<<va[i].first<<" "<<va[i].second<<" "<<vb[j].first<<" "<<vb[j].second<<endl;
			llint t=abs(va[i].first*vb[j].second-va[i].second*vb[j].first);
			if(t>0)res=max(res,t);
		}
		return 1.0*res/2;
	}
};
