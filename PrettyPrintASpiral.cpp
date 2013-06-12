#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
#include	<vector>
#include	<string>
#include	<algorithm>
#define pb push_back
using namespace std;
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
typedef long long int llint;
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
#define PB(x) push_back((x))
#define SORT(x) sort(x.begin(),x.end())
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
	#define print(x)  cerr<<(x)<<endl;
#else
    #define debug(x)
    #define hline()
	#define print(x)
#endif
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
const char dname[]="NWSE";
//const char dname[]="URDL";
const double PI=acos(-1.0);
/********define ends************************/

//*************debug functions****************************//
#ifndef NDEBUG
template<typename T>
void printArray(const vector<T>& table)
{
	hline();
	cerr<<"Array size="<<table.size()<<endl;
	for(int i=0;i<table.size();i++)
		cerr<<table[i]<<" ";
	cerr<<endl;
	hline();
}
template<typename T>
void printArray(T table[],int n)
{
	hline();
	cerr<<"Array size="<<n<<endl;
	for(int i=0;i<n;i++)
		cerr<<table[i]<<" ";
	cerr<<endl;
	hline();
}

template<typename T>
void printArray(const vector<vector<T> >& table)
{
	hline();
	cerr<<"2D array size="<<table.size()<<"*"<<table[0].size()<<endl;
	for(int i=0;i<table.size();i++,cerr<<endl)
	for(int j=0;j<table[i].size();j++)
		cerr<<table[i][j]<<" ";
	hline();
}
#else 
template<typename T>
void printArray(const vector<T>& table){}
template<typename T>
void printArray(T table[],int n){}
template<typename T>
void printArray(const vector<vector<T> >& table,int n){}
#endif
/***********debug ends****************************/

/******************* Tool functions**************************/
template<typename T>
inline vector<T> erase(vector<T> table,int ind)
{
	assert(ind<table.size());
	table.erase(table.begin()+ind);
	return table;
}
/************ I/O functions ********************/
template<class T>
string convert(vector<T> vv)
{
	ostringstream re;
	for(int i=0;i<vv.size();i++)
	{
		if(i)re<<" ";
		re<<vv[i];
	}
	return re.str();
}
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}




struct PrettyPrintASpiral 
{
	vector <string> getWindow(int row1, int col1, int row2, int col2);
};
int getNum(int r,int c)
{
	if(r==0&&c==0)return 1;
	int sq=max(abs(r),abs(c));
	int begin=(sq*2-1)*(2*sq-1)+1;
	debug(begin);
	int re=begin;
	if(r==sq)
	{
		re+=6*sq-1+c+sq;
	}
	else if(r==-sq)
	{
		re+=2*sq-1+sq-c;
	}
	else if(c==sq)
	{
		re+=sq-1-r;
	}
	else if(c==-sq)
	{
		re+=4*sq-1+r+sq;
	}
	else debug(0);
	debug(r);
	debug(c);
	debug(re);
	return re;
}


vector<string> PrettyPrintASpiral::getWindow(int row1, int col1, int row2, int col2)
{
	for(int r=-2;r<=2;r++,cout<<endl)
	for(int c=-2;c<=2;c++)
		cout<<getNum(r,c)<<" ";
	vector<vector<string> > vv;
	for(int r=row1;r<=row2;r++)
	{
		vector<string> row;
		for(int c=col1;c<=col2;c++)
			row.PB(convert(getNum(r,c)));
		vv.PB(row);
	}
	int len=0;
	for(int i=0;i<vv.size();i++)
	for(int j=0;j<vv[i].size();j++)
		len=max(len,(int)vv[i][j].length());
	debug(len);
	vector<string> res;
	for(int i=0;i<vv.size();i++)
	{
		string ss;
		for(int j=0;j<vv[i].size();j++)
		{
			while(vv[i][j].length()<len)
				vv[i][j]=" "+vv[i][j];
			if(j)ss+=" ";
			ss+=vv[i][j];
		}
		debug(ss);
		res.PB(ss);
	}
	return res;

}
