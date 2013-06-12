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
template<typename T>
class point2D
{
	public:
	T _x,_y;
	T x()const{return _x;};
	T& x(){return _x;};
	T y()const{return _y;};
	T& y(){return _y;};
	point2D(){};
	point2D(T x,T y):_x(x),_y(y){};
	point2D(T x):_x(x),_y(0){};
	point2D(const point2D& other):_x(other._x),_y(other._y){};
	const point2D& operator=(const point2D<T>& other){_x=other._x,_y=other._y;return *this;};
	bool operator==(const point2D<T>& other)const{return _x==other._x&&_y==other._y;};
	double length()const {return sqrt(1.0*_x*_x+1.0*_y*_y);};
	double dnorm()const {return 1.0*_x*_x+1.0*_y*_y;};
	T norm()const
	{
		return	_x*_x+_y*_y;
	};
	bool operator<(const point2D& other)const
	{
		return x()<other.x()||(x()==other.x()&&y()<other.y());
	}
	point2D operator+=(const point2D& other)
	{
		_x+=other._x;
		_y+=other._y;
		return *this;
	};
	point2D operator+(const point2D& other)const
	{
		point2D res=*this;
		res+=other;
		return res;
	};
	
	point2D operator-=(const point2D& other)
	{
		_x-=other._x;
		_y-=other._y;
		return *this;
	};
	point2D operator-(const point2D& other)const
	{
		point2D res=*this;
		res-=other;
		return res;
	};

	point2D operator*=(const point2D& other)
	{
		point2D res=(*this)*other;
		*this=res;
		return *this;
	};
	point2D operator*(const point2D& other)const
	{
		point2D res;
		res._x=_x*other._x-_y*other._y;
		res._y=_x*other._y+_y*other._x;
		return res;
	};
	point2D conjugate()const
	{
		return point2D(_x,-_y);
	}
	point2D negate()const
	{
		return point2D(-_x,-_y);
	}
	point2D<double> operator/(const point2D<T>& other)const
	{
		assert(other.dnorm()>0.0);
		point2D<double> res=*this;
		res*=other.conjugate();
		res._x/=other.dnorm();
		res._y/=other.dnorm();
		return res;
	}
	point2D<double> operator/=(const point2D<T>& other)
	{
		*this=(*this)/other;
		return *this;
	}
	point2D<double> operator/(const T& other)
	{
		assert(fabs(1.0*other)>0.0);
		point2D res=*this;
		res._x/=other;
		res._y/=other;
		return res;
	}
	point2D<double> operator/=(T& other)
	{
		*this=(*this)/other;
		return *this;
	}
};
template<typename T>
ostream& operator<<(ostream& out,const point2D<T>& other)
{
	out<<"("<<other.x()<<","<<other.y()<<")";
	return out;
}
template<typename T>
istream& operator>>(istream& in,point2D<T>& other)
{
	in>>other.x()>>other.y();
	return in;
}



template<typename T>
T cross(const point2D<T>& p1,const point2D<T>& p2)
{
	return p1.x()*p2.y()-p1.y()*p2.x();
}
typedef long long int llint;

template<typename T>
llint llcross(const point2D<T>& p1,const point2D<T>& p2)
{
	return (llint)p1.x()*(llint)p2.y()-(llint)p2.x()*(llint)p1.y();
};

template<typename T>
int sigcross(point2D<T> p1,point2D<T> p2)
{
	llint re=llcross(p1,p2);
	if(re<0)return -1;
	if(re>0)return 1;
	return 0;
}

// nocolinear=true means remove all points on the edges of convex hull.
// Be carefull to the points on the same coordanates.

template<typename T>
vector<point2D<T> > convexHull(vector<point2D<T> > all,bool nocolinear=true)
{
	if(all.size()<2)return all;
	sort(all.begin(),all.end());
	vector<int>  qq;
	qq.push_back(0);
	int cut=1;
	if(nocolinear)cut=0;
	for(int i=1;i<all.size();i++)
	{
		// If all[qq.back()]==all[qq[qq.size()-2]], then all point2D<T> s will be pushed to the stack
		while(qq.size()>=2&&llcross(all[i]-all[qq.back()],
					all[qq.back()]-all[qq[qq.size()-2]])>=cut)
			qq.pop_back();
		qq.push_back(i);
	}
	vector<point2D<T> > res;
	vector<bool> used(all.size(),false);
	for(int i=0;i<qq.size();i++)
		res.push_back(all[qq[i]]),used[qq[i]]=true;
	used[0]=used[all.size()-1]=false;
	qq.clear();
	qq.push_back(all.size()-1);
	for(int i=all.size()-2;i>=0;i--)
	{
		if(used[i])continue;
		while(qq.size()>=2&&llcross(all[i]-all[qq.back()],
									all[qq.back()]-all[qq[qq.size()-2]])>=cut)
			qq.pop_back();
		qq.push_back(i);
	}
	for(int i=1;i+1<qq.size();i++)res.push_back(all[qq[i]]);
	return res;
}
template<typename T>
T convex_area(const vector<point2D<T> >& convex)
{
	const int n=convex.size();
	T ret=0;
	for(int i=0;i<n;i++)ret+=cross(convex[i],convex[(i+1)%n]);
	if(ret<0)ret=-ret;
	//ret/=2;
	return ret;
}
typedef point2D<int> point;
vector<point> all;
class BatmanAndRobin {
	public:
	double minArea(vector <int> x, vector <int> y) 
	{
		const int n=x.size();
		if(n==1)return 0.0;
		double ans=1e10;
		for(int i=0;i<n;i++)all.push_back(point(x[i],y[i]));
		for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
		{
			if(a==b)continue;
			vector<point> one,other;
			for(int i=0;i<n;i++)
			{
				if(sigcross(all[a]-all[b],all[i]-all[b])>=0)one.push_back(all[i]);
				else other.push_back(all[i]);
			}
			one=convexHull(one);
			other=convexHull(other);
			int x=convex_area(one);
			int y=convex_area(other);
			if(x<y)swap(x,y);
			ans=min(ans,0.5*x);
		}
		return ans;
	}
};
