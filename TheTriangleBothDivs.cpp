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

class TheTriangleBothDivs {
//Review your code before submission!!!!
	public:
	string fix(string time) 
	{
		string ans="";
		for(int t=0;t<24*60;t++)
		for(int d=-9;d<=9;d++)
		{
			int h=t/60;
			int m=t%60;
			char buf[100];
			sprintf(buf,"%02d:%02d GMT%s%d",h,m,d<0?"":"+",d);
			bool ok=true;
			for(int i=0;i<time.length();i++)
			{
				if(time[i]!=buf[i]&&time[i]!='?')ok=false;
			}
			if(!ok)continue;
			h=(h+24-d)%24;
			sprintf(buf,"%02d:%02d",h,m);
			if(ans==""||ans>string(buf))ans=string(buf);
		}
		return ans;
	}
};

