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
typedef long long int llint;
bool check4(llint a,llint b,llint c,llint d)
{
	if(b==0)return false;
	//no 2
	if(a==0&&c==0)
	{
		if(b==d)return true;
		if(b>d&&0==(d%(b-d)))return true;
	}

	// one 2
	if(a==0&&c&&c==b+d)
	{
		if(b==d)return true;
		if(b>d&&0==(d%(b-d)))return true;
	}

	// at least two 2
	if(a&&c)
	{
		if(a>=c&&(0==(a%c))&&c==b+d)
		{
			if(b==d)return true;
			if(b>d&&0==(d%(b-d)))return true;
		}
	}

	return false;
}
class ModuloFourDivisor {
//Review your code before submission!!!!
	public:
	int countQuadruplets(vector<long long> A, vector<long long> B, vector<long long> C, vector<long long> D) {
		int res=0;
		for(int a=0;a<A.size();a++)
		for(int b=0;b<B.size();b++)
		for(int c=0;c<C.size();c++)
		for(int d=0;d<D.size();d++)
		{
			if(check4(A[a],B[b],C[c],D[d]))res++;
		}
		return res;
	}
};

