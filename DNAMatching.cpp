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
char hash[1000];
bool equal(string a,string b)
{
	hash['A']='T';
	hash['T']='A';
	hash['C']='G';
	hash['G']='C';
	if(a.length()!=b.length())return false;
	for(int i=0;i<a.length();i++)
	{
		if(hash[a[i]]!=b[b.length()-1-i])return false;
	}
	return true;
}
class DNAMatching {
//Review your code before submission!!!!
	public:
	int getMaxSize(vector <string> dna) 
	{
		int res=0;
		for(int i=0;i<dna.size();i++)
		{
			bool pick=true;
			for(int j=0;j<i;j++)
				if(equal(dna[i],dna[j]))pick=false;
			if(pick)res++;
		}
		return res;
	}
};

