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
template<typename T>
vector<T> unique(vector<T> table)
{
	SORT(table);
	return vector<T>(table.begin(),unique(table.begin(),table.end()));
}
template<typename T>
class point: complex<T>
{
	public:
		T x(){return this->real();};
		T y(){return this->imag();};
};
double Euclid_dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
template<typename T>
double Euclid_dis(const point<T>& p1,const point<T>& p2)
{
	return sqrt(1.0*(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
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
int lit[]={ 6,2, 5, 5, 4, 5, 6, 3, 7, 5};
llint low[201][20],high[201][20];
llint ten[20];
class  DigitalCounter
{
	public:
	long long nextEvent(string current)
	{
		ten[0]=1;
		for(int i=1;i<20;i++)ten[i]=ten[i-1]*10;
		memset(low,0xff,sizeof(low));
		memset(high,0xff,sizeof(high));
		debug(sizeof(low));
		debug(sizeof(high));
		low[0][0]=high[0][0]=0;
		for(int i=1;i<=200;i++)
		for(int j=1;j<=15;j++)
		{
			for(int d=0;d<10;d++)
			{
				if(lit[d]<=i&&low[i-lit[d]][j-1]!=-1)
				{
					low[i][j]=ten[j-1]*d+low[i-lit[d]][j-1];
					break;
				}
			}
			for(int d=9;d>=0;d--)
			{
				if(lit[d]<=i&&high[i-lit[d]][j-1]!=-1)
				{
					high[i][j]=ten[j-1]*d+high[i-lit[d]][j-1];
					break;
				}
			}
		}
		debug(low[103][14]);
		const int n=current.length();
		llint re=ten[n];
		llint num=0;
		int use=0;
		for(int i=0;i<n;i++)num*=10,num+=current[i]-'0',use+=lit[num%10];
		debug(num);
		debug(use);
		llint pre=0;
		int sum=0;
		for(int k=0;k<n;k++)
		{
			debug(k);
			debug(pre);
			const int d=current[k]-'0';
			for(int i=d+1;i<10;i++)
			{
				if(sum+lit[i]<=use&&low[use-sum-lit[i]][n-k-1]!=-1)
				{
					llint next=(pre*10+i)*ten[n-k-1]+low[use-sum-lit[i]][n-k-1];
					debug(use-sum-lit[i]);
					debug(n-k-1);
					debug(low[use-sum-lit[i]][n-k-1]);
					debug(next);
					assert(next>num);
					re=min(re,next-num);
				}
			}
			sum+=lit[d];
			pre*=10;pre+=d;
		}
		hline();
		debug(re);
		sum=0;pre=0;
		for(int k=0;k<n;k++)
		{
			debug(k);
			debug(pre);
			const int d=current[k]-'0';
			for(int i=0;i<d;i++)
			{
				if(sum+lit[i]<=use&&low[use-sum-lit[i]][n-k-1]!=-1)
				{
					llint next=(pre*10+i)*ten[n-k-1]+low[use-sum-lit[i]][n-k-1];
					debug(use-sum-lit[i]);
					debug(n-k-1);
					debug(low[use-sum-lit[i]][n-k-1]);
					debug(next);
					assert(next<num);
					re=min(re,ten[n]+next-num);
				}
			}
			sum+=lit[d];
			pre*=10;pre+=d;
		}
		return re;
	};
	
};
