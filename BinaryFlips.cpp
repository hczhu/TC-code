
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
typedef long long int llint;
void getLowUp(llint A,llint S,llint K,llint& low,llint& up)
{
	low=max(0LL,K+A-S);
	up=min(A,K);
}

llint greedy(llint A,llint B,llint K)
{
	if(A==0)return 0;
	if(A+B<K)return -1;
	if(A+B==K)return B==0?1:-1;
	if(0==(K&1)&&1==(A&1))return -1;
	llint res=0;
	return res;
}

int next[300000];
int stack[300000];
int getNext(int next[],int pos)
{
	int top=0;
	while(next[pos]!=pos)stack[top++]=pos,pos=next[pos];
	while(top--)next[stack[top]]=pos;
	return pos;
}
int BFS(llint A,llint B,llint K)
{
	const llint S=A+B;
	queue<llint> qq;
	qq.push(A);
	llint low,up;
	for(llint i=0;i<=S+2;i++)next[i]=i;
	next[A]=A+2;
	for(int res=0;qq.size();res++)
	{
		for(int t=qq.size();t--;)
		{
			llint A=qq.front();qq.pop();
			if(A==0)return res;
			getLowUp(A,S,K,low,up);
			low=A+K-2*low;
			up=A+K-2*up;
			swap(low,up);
			assert(low>=0);
			assert(0==((up-low)&1));
			cerr<<low<<" "<<up<<endl;
			while(low<=up)
			{
				low=getNext(next,low);
				if(low>S||low>up)break;
				next[low]=low+2;
				qq.push(low);
			}
		}
	}
	return -1;
}
class BinaryFlips {
	public:
	int minimalMoves(int A, int B, int K) 
	{
		return BFS(A,B,K);
	}
};
/*
int main()
{
	BinaryFlips bb;
	int A,B,K;
	while(cin>>A>>B>>K)
	{
		cout<<bb.minimalMoves(A,B,K)<<endl;
	}
	return 0;
}*/
