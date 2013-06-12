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
namespace SCC
{
#define N 200
#define M (N*N)
int begin[N],edge[M];
int etop[N];
int cnt[N+1];
int aa[M],bb[M];
void forwardStar(int n,int m)
{
	memset(cnt,0,sizeof(int)*(n+1));
	for(int i=0;i<m;i++)cnt[1+aa[i]]++;
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	for(int i=0;i<n;i++)
		begin[i]=cnt[i],etop[i]=cnt[i+1];
	for(int i=0;i<m;i++)
		edge[--cnt[aa[i]+1]]=i;
}
//The SCCs are topologically sorted.
int stack[N],low[N];
int flag[N],buffer[N];
void stronglyConnectedComponents(int n,int m,int head[],int tail[],vector<vector<int> >& scc)
{
	scc.clear();
	memcpy(aa,head,sizeof(int)*m);
	memcpy(bb,tail,sizeof(int)*m);
	forwardStar(n,m);
	memset(flag,0xff,sizeof(int)*n);
	int ff=0;
	for(int i=0;i<n;i++)
	{
		if(flag[i]!=-1)continue;
		int top=0,btop=0;
		buffer[btop++]=stack[top++]=i;
		low[i]=flag[i]=ff++;
		while(top)
		{
			int v=stack[--top],u;
			assert(v<n);
			while(begin[v]<etop[v]&&flag[u=bb[edge[begin[v]]]]!=-1)
			{
				begin[v]++;
				if(flag[u]!=-2)
					low[v]=min(low[v],low[u]);
			}
			if(begin[v]==etop[v])
			{
//				printf("Pop stack %d low=%d flag=%d\n",v,low[v],flag[v]);
				if(top)low[stack[top-1]]=min(low[stack[top-1]],low[v]);
				if(low[v]==flag[v])
				{
					vector<int> tmp;
#ifdef OUTPUT
					printf("Find SCC rooted at %d\n",v);
#endif
					do
					{
						assert(btop);
						btop--;
						tmp.push_back(buffer[btop]);
#ifdef OUTPUT
						printf("%d ",buffer[btop]);
#endif
						assert(buffer[btop]==v||low[buffer[btop]]<flag[buffer[btop]]);
						flag[buffer[btop]]=-2;
					}while(buffer[btop]!=v);
					scc.push_back(tmp);
#ifdef OUTPUT
					puts("");
#endif
				}
			}
			else
			{
				stack[top++]=v;
				begin[v]++;
				assert(flag[u]==-1);
				low[u]=flag[u]=ff++;
				stack[top++]=u;
				buffer[btop++]=u;
//				printf("Push stack %d\n",u);
			}
		}
	}
}
//Solve two SAT 
//2*i denotes i, while 2*i+1 denotes ~i
//aa[i]+bb[i] is a clause.
//sat[] return assignment
//m is the number of clauses and n is the number variants
//sat[i]==1 denotes i should be false
int head[M],tail[M];
bool twoSAT(int aa[],int bb[],int m,int n,int sat[])
{
	int top=0;
	assert(2*m<=M);
	for(int i=0;i<m;i++)
	{
		head[top]=aa[i]^1;
		tail[top++]=bb[i];
		head[top]=bb[i]^1;
		tail[top++]=aa[i];
	}
	vector<vector<int> > scc;
	stronglyConnectedComponents(2*n,top,head,tail,scc);
	memset(flag,0xff,sizeof(int)*n);
	for(int i=0;i<scc.size();i++)
	for(int j=0;j<scc[i].size();j++)
	{
		if(flag[scc[i][j]>>1]==i)
			return false;
		flag[scc[i][j]>>1]=i;
	}
	for(int i=0;i<scc.size();i++)
	for(int j=0;j<scc[i].size();j++)
		flag[scc[i][j]]=i;
	memset(buffer,0,sizeof(int)*n);
	for(int i=0;i<scc.size();i++)
	{
		int f=buffer[i];
		for(int j=0;j<scc[i].size();j++)
		{
			int v=scc[i][j];
			sat[v>>1]=f^(v&1);
			buffer[flag[v^1]]=1;
		}
	}
	return true;
}
};
int aa[50*50],bb[50*50];
int sat[100];
bool check(int x1,int y1,int x2,int y2,int up)
{
	return up>max(abs(x1-x2),abs(y1-y2));
}
class ColorfulDecoration {
//Review your code before submission!!!!
	public:
	int getMaximum(vector <int> xa, vector <int> ya, vector <int> xb, vector <int> yb) 
	{
		int low=0,high=1000000000;
		const int n=xa.size();
		while(low<high)
		{
			int mid=((low+high)>>1)+1;
			int top=0;
			for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				const int a=i<<1,b=j<<1;
				// (a,a)
				if(check(xa[i],ya[i],xa[j],ya[j],mid))aa[top]=a+1,bb[top++]=b+1;
				//(a,b)
				if(check(xa[i],ya[i],xb[j],yb[j],mid))aa[top]=a+1,bb[top++]=b;
				//(b,a)
				if(check(xb[i],yb[i],xa[j],ya[j],mid))aa[top]=a,bb[top++]=b+1;
				//(b,b)
				if(check(xb[i],yb[i],xb[j],yb[j],mid))aa[top]=a,bb[top++]=b;
			}
			if(SCC::twoSAT(aa,bb,top,n,sat))
			{
				cerr<<"check "<<mid<<" feasible"<<endl;
				low=mid;
			}
			else 
			{
				cerr<<"check "<<mid<<" failed"<<endl;
				high=mid-1;
			}
		}
		return low;
	}
};

