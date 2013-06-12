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


const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

class CubeWalking {
//Review your code before submission!!!!
	public:
	string finalPosition(string movement) 
	{
		int x=1,y=1,d=0;
		for(int i=0;i<movement.length();i++)
		{
			char a=movement[i];
			if(a=='L')d=(d+1)%4;
			else if(a=='R')d=(d+3)%4;
			else x=(x+3+dir[d][0])%3,y=(y+3+dir[d][1])%3;
			cerr<<x<<" "<<y<<endl;
		}
		if(x==1&&y==1)return "GREEN";
		if(x==y||(x+y)==2)return "RED";
		return "BLUE";
	}
};


// Powered by FileEdit
