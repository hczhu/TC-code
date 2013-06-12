#include <cstdarg>
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
#include <cassert>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
#define Throw(x) fprintf(stderr,"%s at [line:%d] [file:%s]\n",x,__LINE__,__FILE__);throw x;
typedef long long int llint;
#define Low(x) ((((x)^((x)-1))&x))
#define Two(x)  ((1)<<(x))
#define PB(x) push_back((x))
#define SORT(x) sort(x.begin(),x.end())
#define GOOD(grid,r,c) (((r)>=0&&(r)<grid.size())&&((c)>=0&&(c)<grid[0].length()))
#define BCNT(x) __builtin_popcount(x)
static const int bitindex_map[32]={};
#define BitIndex(x) (((unsigned int)(x)*0x077CB531U)>>27)
#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Back(str) (str)[(str).length()-1]
#define SZ(vec) ((int)(vec).size())

const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const char dname[]="NWSE";
//const char dname[]="URDL";
// Tool functions
template<typename T>
inline void updateMax(T& a,const T& b){a=max(a,b);}
template<typename T>
inline void updateMin(T& a,const T& b){a=min(a,b);}
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
#define Make_vector(vec,...) do{typedef typeof(vec) _T;const _T::value_type _tmp[]={ __VA_ARGS__ };vec=_T(_tmp,_tmp+sizeof(_tmp)/sizeof(_tmp[0]));}while(0)
// Convert anything to string
template<class T>
string convert(T vv)
{
	ostringstream re;
	re<<vv;
	return re.str();
}
template<typename T>
T convert(const string& ss)
{
	istringstream is(ss);
	T tmp;
	is>>tmp;
	return tmp;
}
//convert vector to string
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

//Be carefull for cut into strings!!!!
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
template<>
vector<string> parse(const string& ss,const char* cut)
{
	vector<string> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			re.push_back(s);
		}
	}
	return re;
}
/************ bitwise functions  ************/
int countBit(int n)
{
	int re=0;
	while(n)re++,n^=Low(n);
	return re;
}
// Most significant bit
int MSB(int n)
{
	if(n==0)return 0;
	while(Low(n)!=n)n^=Low(n);
	return n;
}
void initHash(int n,int hash[])
{
	for(int i=0;i<n;i++)
		hash[Two(i)]=i;
}
void initBcnt(int n,int bcnt[])
{
	bcnt[0]=0;
	for(int i=1;i<Two(n);i++)
		bcnt[i]=bcnt[i^Low(i)]+1;
}
//***********************
template<typename T>
vector<T> readVector(vector<T> type)
{
	int n;
	cin>>n;
	vector<T> res;
	T ss;
	for(int i=0;i<n;i++)
		cin>>ss,res.PB(ss);
	return res;
}

template<typename T>
vector<vector<T> > readGrid(vector<vector<T> > type)
{
	int n,m;
	cin>>n>>m;
	vector<vector<T> > res;
	for(int i=0;i<n;i++)
	{
		vector<T> vt;
		for(int j=0;j<m;j++)
		{
			T ss;
			cin>>ss;
			vt.PB(ss);
		}
		res.PB(vt);
	}
	return res;
}

//**Multiple dimensional array
template<typename T>
class vector1D : public vector<T>
{
	public:
	vector1D<T>():vector<T>(){};
	vector1D<T>(size_t a) : vector<T>(a){};
	vector1D<T>(size_t a,const T& v) : vector<T>(a,v){};
	void resize(size_t a) {vector1D<T> tmp(a);this->swap(tmp);};
	void resize(size_t a,const T& v){vector1D tmp(a,v);this->swap(tmp);};
	void print(const string& head="")const 
	{
		if(head!="")cerr<<head<<endl;
		cerr<<"size= "<<this->size()<<endl;
		for(int i=0;i<this->size();i++)cerr<<(*this)[i]<<" ";
		cerr<<endl;
	}
};

template<typename T>
class vector2D : public vector<vector<T> >
{
	public:
		vector2D<T>():vector<vector<T> >(){};
		vector2D<T>(size_t a,size_t b,const T& v):vector<vector<T> >(a,vector<T>(b,v)){};
		vector2D<T>(size_t a,size_t b):vector<vector<T> >(a,vector<T>(b)){};
		void resize(size_t a,size_t b){vector2D<T> tmp(a,b); this->swap(tmp);};
		void resize(size_t a,size_t b,const T& v){vector2D<T> tmp(a,b,v); this->swap(tmp);};
		void print(const string& head="")const 
		{
			if(head!="")cerr<<head<<endl;

			const vector2D<T>& tmp=*this;
			cerr<<tmp.size()<<" X "<<tmp[0].size()<<endl;
			for(int i=0;i<tmp.size();i++,cerr<<endl)
			for(int j=0;j<tmp[i].size();j++)cerr<<tmp[i][j]<<" ";
		};
};

template<typename T>
class vector3D : public vector<vector2D<T> > 
{
	public:
		vector3D<T>():vector<vector<vector<T> > >(){};
		vector3D<T>(size_t a,size_t b,size_t c):vector<vector2D<T> >(a,vector2D<T>(b,c)){};
		vector3D<T>(size_t a,size_t b,size_t c,const T& v):vector<vector2D<T> >(a,vector2D<T>(b,c,v)){};
		void resize(size_t a,size_t b,size_t c){vector3D<T> tmp(a,b,c); this->swap(tmp);};
		void resize(size_t a,size_t b,size_t c,const T& v){vector3D<T> tmp(a,b,c,v); this->swap(tmp);};
		void print(const string& head="")const 
		{
			if(head!="")cerr<<head<<endl;

			const vector3D<T>& tmp=*this;
			cerr<<tmp.size()<<" X "<<tmp[0].size()<<" X "<<tmp[0][0].size()<<endl;
			for(int i=0;i<tmp.size();i++)
			{
				hline();
				for(int x=0;x<tmp[i].size();x++,cerr<<endl)
				for(int y=0;y<tmp[i][x].size();y++)cerr<<tmp[i][x][y]<<" ";
			}
		};
};

template<typename T>
class vector4D : public vector<vector3D<T> > 
{
	public:
		vector4D<T>():vector<vector3D<T> >(){};
		vector4D<T>(size_t a,size_t b,size_t c,size_t d):vector<vector3D<T> >(a,vector3D<T>(b,c,d)){};
		vector4D<T>(size_t a,size_t b,size_t c,size_t d,const T& v):vector<vector3D<T> >(a,vector3D<T>(b,c,d,v)){};
		void resize(size_t a,size_t b,size_t c,size_t d){vector4D<T> tmp(a,b,c,d); this->swap(tmp);};
		void resize(size_t a,size_t b,size_t c,size_t d,const T& v){vector3D<T> tmp(a,b,c,d,v); this->swap(tmp);};
		void print(const string& head) const 
		{
			if(head!="")cerr<<head<<endl;
			hline();
			const vector4D<T>& tmp=*this;
			cerr<<tmp.size()<<" X "<<tmp[0].size()<<" X "<<tmp[0][0].size()<<" X "<<tmp[0][0][0].size()<<endl;
			for(int i=0;i<tmp.size();i++)
			for(int j=0;j<tmp[i].size();j++)
			{
				hline();
				for(int x=0;x<tmp[i][j].size();x++,cerr<<endl)
				for(int y=0;y<tmp[i][j][x].size();y++)cerr<<tmp[i][j][x][y]<<" ";
			}
		};
};
template<int N,typename T>
int print(T t, ... ) {
	va_list pvar;
	va_start(pvar,t);
	cerr<<t;
	for(int i=1;i<N;i++) {
		cerr<<" "<<va_arg(pvar,int);
	}
	cerr<<endl;
	return N;
}
template<int N,typename T>
T max(T t, ... ) { 
	va_list pvar; va_start(pvar,t);
	for(int i=1;i<N;i++) {
		t=max(t,va_arg(pvar,typeof(T)));
	}
	return t;
}
template<int N,typename T>
T min(T t, ... ) {
	va_list pvar;
	va_start(pvar,t);
	for(int i=1;i<N;i++) {
		t=min(t,va_arg(pvar,typeof(T)));
	}
	return t;
}
#define Min(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define Max(out, ... ) do{typeof(out) X[]={__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define uMin(out, ... ) do{typeof(out) X[]={out,__VA_ARGS__};out=*min_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
#define uMax(out, ... ) do{typeof(out) X[]={out,__VA_ARGS__};out=*max_element(X,X+sizeof(X)/sizeof(X[0]));}while(0)
int print(int aa[]) {
	return 0;
}

template<typename T>
vector<pair<T,T> >  interval_union(vector<pair<T,T> > all) {
	vector<pair<T,T> > res;
	if(all.empty())return res;
	sort(all.begin(),all.end());
	res.push_back(all[0]);
	for(int i=1;i<all.size();i++) {
		if(all[i].first<=res.back().second) {
			res.back().second=max(res.back().second,all[i].second);
		}
		else {
			res.push_back(all[i]);
		}
	}
	return res;
}

#define Union(out,...) do{typeof(out) _v; Make_vector(_v,__VA_ARGS__);out=interval_union(_v);}while(0)
int main()
{
	typedef pair<int,int> ppt;
	vector<ppt> un;
	Union(un,ppt(1,2),ppt(0,1),ppt(3,4));
	assert(un.size()==2);
	assert(un[0]==ppt(0,2));
	assert(un[1]==ppt(3,4));
	print<4>("hahhaha=", 100,200,300 );
	assert(max<4>(-1,2,100,-1)==100);
	assert(min<5>(-1,2,-100,1000,-1)==-100);
	debug(min<5>(-1,2,-100,1000,-1));

	int t;
	Max(t,1,2,3,4,5);
	debug(t);
	assert(t==5);
	double tt;
	Max(tt,1.1,2,3,4,-1.1);
	debug(tt);
	assert(tt==4);
	debug(BCNT(1023));
	unsigned int magic=0x077CB531U;
	for(unsigned int i=(1U)<<31;i>0;i>>=1) 
		cout<<((magic&i)?1:0);
	cout<<endl;
	//for(int i=0;i<10;i++)assert(BitIndex((1<<i))==i);
	return 0;
}
