
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


bool contain(int x1,int y1,int r1,int x2,int y2,int r2)
{
	return r1>r2&&(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<(r1-r2)*(r1-r2);
}
int pp[100];
class CirclesCountry {
	public:
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
	{
		const int n=X.size();
		memset(pp,0xff,sizeof(pp));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(!contain(X[i],Y[i],R[i],X[j],Y[j],R[j]))
				continue;
			bool f=true;
			for(int k=0;k<n;k++)
				if(contain(X[i],Y[i],R[i],X[k],Y[k],R[k])&&
					contain(X[k],Y[k],R[k],X[j],Y[j],R[j]))
					f=false;
			if(f)
			{
				cerr<<i<<" contains "<<j<<endl;
				pp[j]=i;
			}
		}
		for(int i=0;i<n;i++)
			if(pp[i]==-1)pp[i]=n;
		for(int i=0;i<n;i++)cerr<<pp[i]<<" ";cerr<<endl;
		int a=n,best=1000000;
		for(int i=0;i<n;i++)
			if(contain(X[i],Y[i],R[i],x1,y1,0)&&best>R[i])
				a=i,best=R[i];
		debug(a);
		int b=n;best=1000000;
		for(int i=0;i<n;i++)
			if(contain(X[i],Y[i],R[i],x2,y2,0)&&best>R[i])
				b=i,best=R[i];
		debug(b);

		vector<int>  pa,pb;
		while(a!=n)pa.push_back(a),a=pp[a];pa.push_back(n);
		while(b!=n)pb.push_back(b),b=pp[b];pb.push_back(n);
		reverse(pa.begin(),pa.end());
		reverse(pb.begin(),pb.end());
		hline();
		for(int i=0;i<pa.size();i++)cerr<<pa[i]<<"<--";cerr<<endl;
		for(int i=0;i<pb.size();i++)cerr<<pb[i]<<"<--";cerr<<endl;
		int res=0;
		while(pa.size()!=pb.size())
		{
			if(pa.size()>pb.size())pa.pop_back();
			else pb.pop_back();
			res++;
		}
		debug(pa.size());
		while(pa.back()!=pb.back())
		{
			pa.pop_back();
			pb.pop_back();
			res++;
			res++;
		}
		return res;
	}
};
