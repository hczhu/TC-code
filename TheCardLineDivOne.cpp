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
#include <hashmap>
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
typedef long long int llint;
int hash[1000];
const llint mod=1234567891;
map<vector2D<int>, llint> mem[9];
inline llint modMult(llint a,llint b)
{
	return a*b%(llint)mod;
}
void transpose(vector2D<int>& key)
{
	for(int i=0;i<3;i++)
	for(int j=i+1;j<3;j++)
		swap(key[i][j],key[j][i]);
}
llint DP(vector2D<int>& key,int pos)
{
//	key.print();
	if(key[0][0]==13)return 1;
	if(mem[pos].count(key))return mem[pos][key];
	llint ans=0;
	int a=pos/3;
	int b=pos%3;
	if(a&&key[a][b])
	{
		int mm=key[a][b]*a;
		key[a][b]--;key[a-1][b]++;
		ans+=modMult(DP(key,(a-1)*3+b),mm);ans%=mod;
		key[a][b]++;key[a-1][b]--;
	}
	if(b&&key[a][b])
	{
		key[a][b]--;key[a][b-1]++;
		transpose(key);
		ans+=modMult(DP(key,(b-1)*3+a),b);ans%=mod;
		transpose(key);
		key[a][b]++;key[a][b-1]--;
	}
	for(int x=1;x<3;x++)
	for(int y=0;y<3;y++)
	{
		if(0==key[x][y])continue;
		if(a==x&&y==b)continue;
		int mm=x*(key[x][y]);
		key[x][y]--;key[x-1][y]++;
		ans+=modMult(DP(key,(x-1)*3+y),mm);
		key[x][y]++;key[x-1][y]--;
	}
//	key.print();
//	cerr<<pos<<" "<<ans<<endl;
	mem[pos][key]=ans;
	return ans;
}
const string name="23456789TJQKA";
class TheCardLineDivOne {
//Review your code before submission!!!!
	public:
	int count(vector <string> cards) {
		debug(mod*2);
		vector1D<int> red(13,0),black(13,0);
		for(int i=0;i<name.length();i++)hash[name[i]]=i;
		for(int i=0;i<cards.size();i++)
		{
			if(cards[i][1]=='S'||cards[i][1]=='C')red[hash[cards[i][0]]]++;
			else black[hash[cards[i][0]]]++;
		}
		red.print();
		black.print();
		llint ans=0;
		vector2D<int> key(3,3,0);
		int sum=0;
		for(int i=0;i<name.length();i++)
			key[red[i]][black[i]]++;
		vector2D<int> tmp(3,3,0);
		tmp[0][0]=13;
		mem[0][tmp]=1;
		for(int x=0;x<3;x++)
		for(int y=0;y<3;y++)
		{
			if(0==key[x][y])continue;
			if(x)
			{
				const int mm=key[x][y]*x;
				key[x][y]--;key[x-1][y]++;
				ans+=modMult(DP(key,(x-1)*3+y),mm);ans%=mod;
				key[x][y]++;key[x-1][y]--;
			}
			if(y)
			{
				const int mm=key[x][y]*y;
				key[x][y]--;key[x][y-1]++;
				transpose(key);
				ans+=modMult(DP(key,(y-1)*3+x),mm);ans%=mod;
				transpose(key);
				key[x][y]++;key[x][y-1]--;
			}
		}
		return ans;
	}
};


// Powered by FileEdit
