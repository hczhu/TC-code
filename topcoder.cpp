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
vector<int> xx,yy;

bool iscover(int height,int bx,int ex,int by,int ey,int xfold,int cnt,int x1,int y1,int x2,int y2)
{
	assert(ex<=xfold||bx>=xfold);
	if(ex<=xfold)bx=xfold-bx,ex=xfold-ex,swap(bx,ex);
	else bx-=xfold,ex-=xfold;
	int dy=height/(1+cnt);
	int ind=by/dy;
	by%=dy;
	ey%=dy;
	if(ind&1)by=dy-by,ey=dy-ey,swap(by,ey);
	return x1<=bx&&x2>=ex&&y1<=by&&y2>=ey;
}
class  PaperAndPaint
{
	public:
	long long computeArea(int width, int height, vector <int> xfold, vector <int> cnt, 
			vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2)
	{
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

		yy.push_back(0);
		yy.push_back(height);
		for(int i=0;i<cnt.size();i++)
		{
			int d=height/(1+cnt[i]);
			int pre=0;
			for(int i=0;i<cnt[i];i++)
			{
				pre+=d;
				yy.push_back(pre);
			}
			int dy=y1[i];
			pre=0;
			yy.push_back(dy);
			for(int j=1;j<=cnt[i];j++)
			{
				pre+=d;
				dy+=2*(pre-dy);
				yy.push_back(dy);
			}
			dy=y2[i];
			pre=0;
			yy.push_back(dy);
			for(int j=1;j<=cnt[i];j++)
			{
				pre+=d;
				dy+=2*(pre-dy);
				yy.push_back(dy);
			}

		}
		sort(xx.begin(),xx.end());
		sort(yy.begin(),yy.end());
		debug(xx.size());
		llint res=0;
		debug(yy.size());
		for(int i=1;i<xx.size();i++)
		for(int j=1;j<yy.size();j++)
		{
			bool f=false;
			for(int k=0;k<cnt.size();k++)
			{
				if(iscover(height,xx[i-1],xx[i],yy[i-1],yy[i],xfold[i],cnt[i],x1[i],x2[i],y1[i],y2[i]))
				{
					f=true;
					break;
				}
			}
			if(f)res+=(llint)(xx[i]-xx[i-1])*(yy[i]-yy[i-1]);
		}
		
		
	};
	
};