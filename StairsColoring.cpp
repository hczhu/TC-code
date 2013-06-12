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
#define low(x) ((((x)^((x)-1))&x))
#define two(x)  ((1)<<(x))
#define PB(x) push_back((x))
#define SORT(x) sort(x.begin(),x.end())
// print function
template<typename T1> void print_list(const T1& a){cerr<<a<<endl;}
template<typename T1,typename T2> void print_list(const T1& a,const T2& b){cerr<<a<<" "<<b<<endl;}
template<typename T1,typename T2,typename T3> void print_list(const T1& a,const T2& b,const T3& c){cerr<<a<<" "<<b<<" "<<c<<endl;}
template<typename T1,typename T2,typename T3,typename T4> void print_list(const T1& a,const T2& b,const T3& c,const T4& d){cerr<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
template<typename T1,typename T2,typename T3,typename T4,typename T5> void print_list(const T1& a,const T2& b,const T3& c,const T4& d,const T5& e){cerr<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> void print_list(const T1& a,const T2& b,const T3& c,const T4& d,const T5& e,const T6& f){cerr<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> void print_list(const T1& a,const T2& b,const T3& c,const T4& d,const T5& e,const T6& f,const T7& g){cerr<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<endl;}

//************************************************
template<typename A,typename B>
ostream& operator<<(ostream& out,const pair<A,B>& pp)
{
	out<<"("<<pp.first<<","<<pp.second<<")";
	return out;
}
template<typename A,typename B>
istream& operator<<(istream& in,pair<A,B>& pp)
{
	in>>pp.first>>pp.second;
	return in;
}

template<typename T>
ostream& operator<<(ostream& out,const vector<T>& vect)
{
	out<<"size = "<<vect.size()<<endl;
	for(int i=0;i<vect.size();i++)out<<vect[i]<<" ";
	out<<endl;
	return out;
}
template<typename T>
istream& operator>>(istream& in,vector<T>& vect)
{
	vect.clear();
	int n;
	in>>n;
	vect.resize(n);
	for(int i=0;i<n;i++)in>>vect[i];
	return in;
}

template<typename T>
ostream& operator<<(ostream& out,const vector<vector<T> >& vect)
{
	out<<"row number="<<vect.size()<<endl;
	for(int i=0;i<vect.size();i++)
	{
		out<<"row #"<<i<<":";
		for(int j=0;j<vect[i].size();j++)
			out<<" "<<vect[i][j];
		out<<endl;
	}
	return out;
}
template<typename T>
istream& operator>>(istream& in,vector<vector<T> >& vect)
{
	vect.clear();
	int n,m;
	in>>n>>m;
	vect.resize(n);
	for(int i=0;i<n;i++)
	{
		vect[i].resize(m);
		for(int j=0;j<m;j++)in>>vect[i][j];
	}
	return in;
}



//**************************************************
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
//****************************************8
/************ bitwise functions  ************/
int countBit(int n)
{
	int re=0;
	while(n)re++,n^=low(n);
	return re;
}
// Most significant bit
int MSB(int n)
{
	if(n==0)return 0;
	while(low(n)!=n)n^=low(n);
	return n;
}
void initHash(int n,int hash[])
{
	for(int i=0;i<n;i++)
		hash[two(i)]=i;
}
void initBcnt(int n,int bcnt[])
{
	bcnt[0]=0;
	for(int i=1;i<two(n);i++)
		bcnt[i]=bcnt[i^low(i)]+1;
}


//************************************************
//**********Number functions*****************
template<typename T>
T __gcd(T n,T m,T& a,T& b)
{
	T a1=0,b1=1;
	a=1,b=0;
	// a*n+b*m=n;  a1*n+b1*m=m;
	while(m)
	{
		T c=n/m;
		T r=n-m*c;
		T t;
		t=a;a=a1;a1=t-c*a1;
		t=b;b=b1;b1=t-c*b1;
		n=m;m=r;
	}
	return n;
}

//*******************************************
const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const char dname[]="NWSE";
llint modPower(llint a,llint n,llint m)
{
	llint re=1,t=a;
	while(n)
	{
		if(n&1)re=re*t%m;
		t=t*t%m;
		n>>=1;
	}
	return re;
}

template<typename T>
vector<pair<T,int> > factorize(T n)
{
	vector<pair<T,int> > res;
	for(T t=2;t*t<=n;t++)
	{
		if(0==(n%t))
		{
			int cnt=1;
			n/=t;
			while(0==(n%t))n/=t,cnt++;
			res.push_back(make_pair(t,cnt));
		}
	}
	if(n>1)res.push_back(make_pair(n,1));
	return res;
}
llint getReverse(llint a,llint p,llint rev[]=NULL)
{
	if(rev!=NULL)return rev[a];
	llint x,y;
	assert(1==std::__gcd(a,p));
	__gcd(a,p,x,y);
	return ((x%p)+p)%p;
}
// return bino(n,m)%p, p must be a prime.
// Using the Lemma: bino(n,m)=bino(n/p,m/p)*bino(n%p,m%p) mod p
llint binomial_mod(llint n,llint m,llint p)
{
	llint res=1;
	vector<llint> up,down;
	llint nn=n,mm=m;
	while(n||m)
	{
		llint a=n%p;n/=p;
		llint b=m%p;m/=p;
		if(a<b)return 0;
		if(a>b&&b)up.push_back(a),down.push_back(b),down.push_back(a-b);
	}
	sort(up.begin(),up.end());
	reverse(up.begin(),up.end());
	sort(down.begin(),down.end());
	reverse(down.begin(),down.end());
	llint fact=1;
	for(int i=1;i<p&&(up.size()+down.size());i++)
	{
		fact*=i;fact%=p;
		llint rfact=getReverse(fact,p);
		while(up.size()&&up.back()==i)
			res*=fact,res%=p,up.pop_back();
		while(down.size()&&down.back()==i)
			res*=rfact,res%=p,down.pop_back();
	}
	return res;
}
//Solve module equation group
//x==aa[i] mod mm[i]
llint solveModuleEquations(int n,llint aa[],llint mm[])
{
	llint gg,xx,yy;
	for(int i=1;i<n;i++)
	{
		gg=__gcd(mm[0],mm[i],xx,yy);
		if((aa[i]-aa[0])%gg)return -1;
		xx*=(aa[i]-aa[0])/gg;
		mm[i]/=gg;
		xx=((xx%mm[i])+mm[i])%mm[i];
		aa[0]+=mm[0]*xx;
		mm[0]*=mm[i];aa[0]%=mm[0];
	}
	return aa[0];
}
template<typename T>
vector<llint> Chinese_remainder(const vector<T>& mod)
{
	const int n=mod.size();
	llint all=1;
	for(int i=0;i<n;i++)all*=mod[i];
	vector<llint> res(n);
	for(int i=0;i<n;i++)
	{
		if(__gcd((llint)mod[i],all/mod[i])>1)
			return vector<llint>();
		llint k=getReverse(all/mod[i],mod[i]);
		res[i]=all/mod[i]*k;
		assert(1==(res[i]%mod[i]));
	}
	return res;
}
// All factors p in n! are removed.
// p must be prime.
// degr is the number of factor p in n!
llint factorial_mod(llint n,llint p,llint& deg)
{
	deg=0;
	vector<llint> table(p);
	table[0]=1;
	for(int i=1;i<p;i++)
		table[i]=table[i-1]*i,table[i]%=p;
	llint res=1;
	while(n)
	{
		llint r=n%p;
		n/=p;
		if(n&1)res=p-res;
		res*=table[r];res%=p;
		deg+=n;
	}
	res%=p;
	return res;
}
const llint mod=1000000123;

class StairsColoring {
//Review your code before submission!!!!
	public:
	int coloringCount(int N, int K) {
		K%=mod;
		if(0==K)return 0;
		debug(mod* mod);
		vector<pair<llint,int> > fmod=factorize(mod-1);
		cerr<<fmod<<endl;
		llint aa[100],mm[100];
		for(int i=0;i<fmod.size();i++)
		{
			assert(fmod[i].second==1);
			mm[i]=fmod[i].first;
			const llint p=mm[i];
			if((N+1)%p)
			{
				aa[i]=binomial_mod(N<<1,N,p);
				debug(aa[i]);
				llint rev=getReverse((N+1)%p,p);
				debug(rev);
				aa[i]*=rev;aa[i]%=p;
				debug(aa[i]);
			}
			else
			{
				assert((N*2+1)%p);
				aa[i]=binomial_mod(N*2+1,N,p);
				debug(aa[i]);
				llint rev=getReverse((N*2+1)%p,p);
				debug(rev);
				aa[i]*=rev;aa[i]%=p;
				debug(aa[i]);
			}
			llint deg1,deg2,deg3;
			aa[i]=factorial_mod(N<<1,mm[i],deg1)*getReverse(factorial_mod(N,mm[i],deg2),mm[i])*
				getReverse(factorial_mod(N+1,mm[i],deg3),mm[i])%mm[i];
			if(deg1>deg2+deg3)aa[i]=0;
			cerr<<aa[i]<<" "<<mm[i]<<endl;
		}
		vector<llint> caa(aa,aa+fmod.size());
		vector<int> mods;
		for(int i=0;i<fmod.size();i++)mods.push_back(fmod[i].first);
		vector<llint> cc=Chinese_remainder(mods);
		assert(cc.size());
		llint ans=0;
		for(int i=0;i<fmod.size();i++)ans+=cc[i]*aa[i],ans%=mod-1;
		debug(ans);
		llint other=solveModuleEquations(fmod.size(),aa,mm);
		debug(other);
		for(int i=0;i<fmod.size();i++)
		{
			debug(fmod[i].first);
			debug(ans%fmod[i].first);
			debug(caa[i]);
			assert(caa[i]==(ans%fmod[i].first));
			assert(caa[i]==(other%mods[i]));
		}
		assert(ans==other);
		debug(ans);
		assert(modPower(K,mod-1,mod)==1);
		ans=modPower(K,ans,mod);
		return ans;
	}
};




/*
int main()
{
	StairsColoring ss;
	int n,k;
	while(cin>>n>>k)cout<<ss.coloringCount(n,k)<<endl;
	return 0;
}
*/



// Powered by FileEdit
