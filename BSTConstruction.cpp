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
const int N=250010;
int p[N];
int tree[N*4];

const int inf=N+1;

void insert_tree(int pos,int v,int n)
{
	int low=0,high=n-1,ind=0;
	while(low<high)
	{
		tree[ind]=min(tree[ind],v);
		int mid=(low+high)>>1;
		ind<<=1;ind++;
		if(pos<=mid)high=mid;
		else low=mid+1,ind++;
	}
	tree[ind]=min(tree[ind],v);
}
int query(int low,int high,int b,int e,int ind)
{
	if(low==b&&high==e)return tree[ind];
	int mid=(low+high)>>1;
	ind<<=1;ind++;
	if(e<=mid)return query(low,mid,b,e,ind);
	else if(b>mid)return query(mid+1,high,b,e,ind+1);
	else return min(query(low,mid,b,mid,ind),query(mid+1,high,mid+1,e,ind+1));
}
int aa[N],bb[N];
int height[N];
bool ll[N],rr[N];
int pp[N];
class BSTConstruction {
	public:
	long long sumHeights(int n, int seed, int limit) 
	{
		
		llint X= seed;
	
		for(int i=0;i<n;i++)
		{
		   	p[i] = i;
			X = (X * (llint)295397169) % (llint)1073741789;
   			if( (X * 1000000) / 1073741789 < limit)
			{
					X = (X * 295397169) % 1073741789;
					int j = (X * (i + 1)) / 1073741789;
					swap(p[i], p[j]);
			}
		}
		set<int> stree;
		stree.insert(p[0]);
		height[p[0]]=1;
		for(int i=1;i<n;i++)
		{
			set<int>::iterator suc=stree.lower_bound(p[i]),pred;
			if(suc==stree.begin())height[p[i]]=height[*suc]+1,ll[*suc]=true,pp[p[i]]=*suc;
			else if(suc==stree.end())height[p[i]]=height[*(--suc)]+1,rr[*suc]=true,pp[p[i]]=*suc;
			else
			{
				pred=suc;pred--;
				cerr<<(*pred)<<" "<<(*suc)<<endl;
				if(!rr[*pred])rr[*pred]=true,height[p[i]]=height[*pred]+1,pp[p[i]]=*pred;
				else ll[*suc]=true,height[p[i]]=height[*suc]+1,pp[p[i]]=*suc;
			}
			cerr<<p[i]<<"-->"<<pp[p[i]]<<endl;
			stree.insert(p[i]);
		}
		return accumulate(height,height+n,(llint)0);
		memset(tree,0x33,sizeof(tree));
		for(int i=0;i<n;i++)insert_tree(p[i],i,n);
		debug("insert ended");
		llint res=0;
		aa[0]=0,bb[0]=n-1;
		for(int i=0;i<n;i++)
		{
			int a=aa[i],b=bb[i];
			int v=p[i];
			assert(a<=v&&v<=b);
			res+=b-a+1;
			int ll=inf;
			if(v-1>=a)ll=query(0,n-1,a,v-1,0);
			assert(ll>i);
			if(ll<inf)aa[ll]=a,bb[ll]=v-1;
			int rr=inf;
			if(v+1<=b)rr=query(0,n-1,v+1,b,0);
			assert(rr>i);
			if(rr<inf)aa[rr]=v+1,bb[rr]=b;
			cerr<<v<<" "<<a<<"---"<<b<<endl;
			cerr<<v<<" "<<(ll<inf?p[ll]:-1)<<" "<<(rr<inf?p[rr]:-1)<<endl;
		}
		return res;
	}
};


// Powered by FileEdit
