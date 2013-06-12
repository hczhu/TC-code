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
class FractalPicture {
	public:
	double get(int x1,int y1,int x2,int y2,int len,int dep=1) {
		assert(x1<=x2);
		assert(y1<=y2);
		if(len==1) {
			if(x2<0||x1>0||y1>=1||y2<=0||y1==y2)return 0;
			double res=1.0*(500-dep)*2/3+1.0;
			if(x1==0||x2==0)res=x1<x2?(res-1)/2+1.0:1;
//			cerr<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
//			debug(res);
			return res;
		}
		int len3=len/3;
		double res=0;
		if(x1<=0&&x2>=0&&y1<=len3*2&&y2>=0)res+=min(y2,len3*2)-max(0,y1);
//		if(res>0)debug(res);
		return res+get(x1,y1-len3*2,x2,y2-len3*2,len3,dep+1)+
			get(-y2+len3*2,x1,-y1+len3*2,x2,len3,dep+1)+
			get(y1-len3*2,-x2,y2-len3*2,-x1,len3,dep+1);
	}
	double getLength(int x1, int y1, int x2, int y2) {
		return get(x1,y1,x2,y2,81);
	}
};


/*
int main() {
	FractalPicture ff;
	cout<<ff.getLength(18,0,18,81)<<endl;
	cout<<ff.getLength(-1,0,1,53)<<endl;
	cout<<ff.getLength(14,45,22,54)<<endl;
	cout<<ff.getLength(0,54,27,54)<<endl;
	cout<<ff.getLength(-10,54,10,55)<<endl;
	cout<<ff.getLength(1,1,10,10)<<endl;
	return 0;
}

*/
