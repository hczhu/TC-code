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

const int B=350;
const int N=125000;
const int S=10;
int trans[S][S];
int tree[4*N][S];
void buildTree(int ind,int low,int high,int s)
{
	if(low==high)
	{
		for(int i=0;i<s;i++)
			tree[ind][i]=trans[i][0];
		return;
	}
	int mid=(low+high)>>1;
	int ll=(ind<<1)^1;
	int rr=ll+1;
	buildTree(ll,low,mid,s);
	buildTree(rr,mid+1,high,s);
	for(int i=0;i<s;i++)tree[ind][i]=tree[rr][tree[ll][i]];
}
void updateTree(int ind,int low,int high,int pos,int v,int s)
{
	if(low==high)
	{
		for(int i=0;i<s;i++)
			tree[ind][i]=trans[i][v];
		return;
	}
	int mid=(low+high)>>1;
	int ll=(ind<<1)^1;
	int rr=ll+1;
	if(pos<=mid)updateTree(ll,low,mid,pos,v,s);
	else updateTree(rr,mid+1,high,pos,v,s);
	for(int i=0;i<s;i++)tree[ind][i]=tree[rr][tree[ll][i]];
}

class Automaton {
	public:
	int numberOfMatchings(vector <string> trans, int slen, vector <int> x0, vector <int> xa, 
			vector <int> c0, vector <int> ca, int n) 
	{
		for(int i=0;i<trans.size();i++)
		for(int j=0;j<trans[i].length();j++)
			::trans[i][j]=trans[i][j]-'A';


		int initElements =x0.size();
		int letters = trans[0].length();
		vector<int> x(n),c(n);
		for (int i = 0; i < initElements; i++) 
		{
				x[i] = x0[i] % slen;
				c[i] = c0[i] % letters;
		}
		for (int i = initElements; i < n; i++) 
		{
				x[i] = 0;
				c[i] = 0;	
				for (int j = i - initElements; j < i; j++) {
					x[i] = (x[i] + xa[j - i + initElements] * x[j]) % slen;
					c[i] = (c[i] + ca[j - i + initElements] * c[j]) % letters;
				}
		}
		const int s=trans.size();
		int res=0;
		buildTree(0,0,slen-1,trans.size());
		if(tree[0][0]==s-1)res++;
		for(int i=0;i<n;i++)
		{
			updateTree(0,0,slen-1,x[i],c[i],trans.size());
			if(tree[0][0]==s-1)res++;
		}
		return res;
	}
};


// Powered by FileEdit
