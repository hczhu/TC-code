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

class  PaperAndPaint
{
	public:
	long long computeArea(int width, int height, vector <int> xfold, vector <int> cnt, 
			vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2)
	{
		vector<int> xx;
		xx=xfold;
		xx.push_back(0);
		xx.push_back(width);
		for(int i=0;i<x1.size();i++)
		{
			if(x1[i]+xfold[i]<width)xx.push_back(x1[i]+xfold[i]);
			if(xfold[i]-x1[i]>0)xx.push_back(xfold[i]-x1[i]);
		}
		for(int i=0;i<x2.size();i++)
		{
			if(x2[i]+xfold[i]<width)xx.push_back(x2[i]+xfold[i]);
			if(xfold[i]-x2[i]>0)xx.push_back(xfold[i]-x2[i]);
		}
		sort(xx.begin(),xx.end());
		llint res=0;
		for(int i=1;i<xx.size();i++)
		{
			int bx=xx[i-1],ex=xx[i];
			if(bx==ex)continue;
		//	hline();
		//	cerr<<bx<<"----"<<ex<<endl;
			vector<pair<int,int> > seg;
			for(int j=0;j<cnt.size();j++)
			{
				int ll=bx,rr=ex;
				if(rr<=xfold[j])rr=xfold[j]-rr,ll=xfold[j]-ll,swap(ll,rr);
				else if(ll>=xfold[j])rr-=xfold[j],ll-=xfold[j];
				else assert(0);
				const int dy=height/(1+cnt[j]);
			//	cerr<<"transfromed "<<ll<<" "<<rr<<endl;
				if(x1[j]>=rr||x2[j]<=ll)continue;
				assert(x1[j]<=ll&&x2[j]>=rr);
				seg.push_back(make_pair(y1[j],y2[j]));
				int by=y1[j],ey=y2[j];
			//	cerr<<"add "<<by<<" "<<ey<<endl;
				for(int k=1;k<=cnt[j];k++)
				{
					llint sub=(llint)k*(llint)dy*2;
					by=sub-by;ey=sub-ey;
					swap(by,ey);
					seg.push_back(make_pair(by,ey));
			//		cerr<<"add "<<by<<" "<<ey<<endl;
				}
			}
			sort(seg.begin(),seg.end());
			for(int j=0;j<seg.size();j++)
			{
				int k=j+1;
				int rr=seg[j].second;
				while(k<seg.size()&&seg[k].first<=rr)
					rr=max(rr,seg[k].second),k++;
				res+=(llint)(ex-bx)*(llint)(rr-seg[j].first);
				j=k-1;
			}
			debug(res);
		}
		res=(llint)height*(llint)width-res;
		return res;
		
	};
	
};
