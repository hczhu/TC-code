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

//**************************************************

const int N=200;

int root[N];
int get_root(int a)
{
	if(root[a]==-1)return a;
	return (root[a]=get_root(root[a]));
}
template<typename T>
struct Edge
{
	int a,b;
	T c;
	Edge(int _a,int _b,T _c){a=_a;b=_b;c=_c;};
	bool operator<(const Edge<T>& other)const{return c<other.c;};
	bool operator>(const Edge<T>& other)const{return c>other.c;};
};
template<typename T>
bool cmp(const Edge<T>& e1,const Edge<T>& e2)
{
	return e1.c<e2.c;
}
class TransportationNetwork {
//Review your code before submission!!!!
	public:
	double minCost(vector <int> X, vector <int> Y, double roadCost, double airportCost) {
		const int n=X.size();
		vector<Edge<double> > all;
		for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			all.push_back(Edge<double>(i,j,roadCost*sqrt(1.0*(X[i]-X[j])*(X[i]-X[j])+1.0*(Y[i]-Y[j])*(Y[i]-Y[j]))));
		sort(all.begin(),all.end());//,cmp<double>);
		double ans=0.0;
		memset(root,0xff,sizeof(root));
		for(int i=0;i<all.size();i++)
		{
			int a=get_root(all[i].a);
			int b=get_root(all[i].b);
			if(a==b)continue;
			root[a]=b;
			ans+=all[i].c;
		}
		debug(ans);
		double another=airportCost*n;
		memset(root,0xff,sizeof(root));
		for(int i=0;i<all.size();i++)
		{
			if(all[i].c>airportCost)break;
			int a=get_root(all[i].a);
			int b=get_root(all[i].b);
			if(a==b)continue;
			root[a]=b;
			another-=airportCost;
			another+=all[i].c;
		}
		debug(another);
		ans=min(ans,another);
		return ans;
	}
};

