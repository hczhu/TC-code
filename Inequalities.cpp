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
//*******************************************

class Inequalities {
//Review your code before submission!!!!
	public:
	int maximumSubset(vector <string> inq) {
		// <=, =, >=
		vector<int> le,ee,ge,all;
		for(int i=0;i<inq.size();i++)
		{
			char op[10];
			int x;
			sscanf(inq[i].c_str(),"%s %s %d",op,op,&x);
			debug(op);
			debug(x);
			x++;
			x*=2;
			string sop(op);
			if(string(op)=="=")ee.push_back(x);
			else if(sop=="<=")le.push_back(x);
			else if(sop=="<")le.push_back(x-1),x--;
			else if(sop==">=")ge.push_back(x);
			else if(sop==">")ge.push_back(x+1),x++;
			else assert(0);
			cerr<<"X"<<sop<<x<<endl;
			all.push_back(x);
		}
		int res=0;
		sort(all.begin(),all.end());
		for(int i=0;i<all.size();i++)
		for(int j=i;j<all.size();j++)
		{
			int cnt=0;
			const int ll=all[i],rr=all[j];
			for(int a=0;a<le.size();a++)if(le[a]>=rr)cnt++;
			for(int b=0;b<ee.size();b++)if(ee[b]==rr&&ee[b]==ll)cnt++;
			for(int a=0;a<ge.size();a++)if(ge[a]<=ll)cnt++;
			cerr<<ll<<" "<<rr<<"="<<cnt<<endl;
			res=max(res,cnt);
		}
		return res;
	}
};



// Powered by FileEdit
