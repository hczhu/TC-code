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

//************************************************

template<typename T>
ostream& operator<<(ostream& out,const vector<T>& vect)
{
	out<<"size = "<<vect.size()<<endl;
	for(int i=0;i<vect.size();i++)out<<vect[i]<<" ";
	out<<endl;
	return out;
}



//**************************************************

//*******************************************

///*******************************************


vector<string> get_smallest(const vector<string>& A,const vector<string>& B)
{
	vector<string> res=A;
	for(int i=0;i<A.size();i++)
	for(int j=0;j<A[0].length();j++)
	{
		if(A[i][j]!='?'&&B[i][j]!='?'&&A[i][j]!=B[i][j])
			return vector<string>();
		if(A[i][j]!='?'&&B[i][j]!='?'&&A[i][j]==B[i][j])
			continue;
		if(A[i][j]==B[i][j])res[i][j]=(A[i][j]=='?'?'0':res[i][j]);
		else if(A[i][j]=='?')res[i][j]=B[i][j];
		else if(B[i][j]=='?')res[i][j]=A[i][j];
		else assert(0);
	}
	cerr<<"A="<<endl;
	cerr<<A<<endl;
	cerr<<"B="<<endl;
	cerr<<B<<endl;
	cerr<<"res="<<endl;
	cerr<<res<<endl;
	return res;
}
class TwistedMatrix {
//Review your code before submission!!!!
	public:
	vector <string> solve(vector <string> A, vector <string> B) 
	{
		const int n=A.size();
		const int m=A[0].length();
		char tmp;
		vector<string> res;
		for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
		{
			tmp=A[i][j];A[i][j]=A[i-1][j];A[i-1][j]=A[i-1][j-1];A[i-1][j-1]=A[i][j-1];A[i][j-1]=tmp;
			cerr<<"After rotate "<<endl;
			cerr<<A<<endl;
			vector<string> t=get_smallest(A,B);
			if(t.size()&&(res.empty()||res>t))res=t;
			tmp=A[i][j];A[i][j]=A[i-1][j];A[i-1][j]=A[i-1][j-1];A[i-1][j-1]=A[i][j-1];A[i][j-1]=tmp;
			tmp=A[i][j];A[i][j]=A[i-1][j];A[i-1][j]=A[i-1][j-1];A[i-1][j-1]=A[i][j-1];A[i][j-1]=tmp;
			t=get_smallest(A,B);
			if(t.size()&&(res.empty()||res>t))res=t;
			tmp=A[i][j];A[i][j]=A[i-1][j];A[i-1][j]=A[i-1][j-1];A[i-1][j-1]=A[i][j-1];A[i][j-1]=tmp;
		}
		return res;
	}
};

