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
#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif
// 3D point
template<typename T>
class point3D
{
	public:
	T _x,_y,_z;
	T x()const{return _x;};
	T y()const{return _y;};
	T z()const{return _z;};
	T& x(){return _x;};
	T& y(){return _y;};
	T& z(){return _z;};

	point3D(int xx=0,int yy=0,int zz=0):_x(xx),_y(yy),_z(zz){};
	point3D operator+(const point3D& other)const
	{
		point3D res=*this;
		res+=other;
		return res;
	};
	point3D operator+=(const point3D& other)
	{
		_x+=other._x;
		_y+=other._y;
		_z+=other._z;
		return *this;
	}
	point3D operator-(const point3D& other)const
	{
		point3D res=*this;
		res-=other;
		return res;
	};
	point3D operator-=(const point3D& other)
	{
		_x-=other._x;
		_y-=other._y;
		_z-=other._z;
		return *this;
	};
	point3D operator*(T k)const
	{
		point3D res=*this;
		res*=k;
		return res;
	};
	point3D operator*=(T k)
	{
		_x*=k;
		_y*=k;
		_z*=k;
		return *this;
	};
	point3D<T> operator*(const point3D<T>& other)const
	{
		point3D res;
		res._x=_y*(other._z)-_z*(other._y);
		res._y=-_x*(other._z)+_z*(other._x);
		res._z=_x*(other._y)-_y*(other._x);
		return res;
	};

	point3D operator*=(const point3D& other)
	{
		point3D res=(*this)*other;
		*this=res;
		return *this;
	};
	T norm()const
	{
		return	_x*_x+_y*_y+_z*_z;
	};
	double dnorm()const
	{
		return 1.0*_x*_x+1.0*_y*_y+1.0*_z*_z;
	}
	double length()const
	{
		return sqrt(dnorm());
	};

};
template<typename T1,typename T2>
T1 dot(point3D<T1> p1,point3D<T2> p2)
{
	return p1.x()*p2.x()+p1.y()*p2.y()+p1.z()*p2.z();
}
template<typename T>
ostream& operator<<(ostream& out,const point3D<T>& other)
{
	out<<"("<<other.x()<<","<<other.y()<<","<<other.z()<<")";
	return out;
}

typedef long long int llint;
typedef point3D<llint> point;
class ConstructPolyline {
	public:
	long long maximizeLength(vector <int> x, vector <int> y, vector <int> z) 
	{
/*		while(x.size()<50)
			x.push_back(10000-(rand()%20000)),
			y.push_back(10000-(rand()%20000)),
			z.push_back(0);*/
		int n=x.size();
		vector<point> all;
		for(int i=0;i<n;i++)
		{
			point v(x[i],y[i],z[i]);
			bool ok=true;
			for(int j=0;j<all.size();j++)
			{
				if((v*all[j]).norm()==0)
				{
					ok=false;
					if(dot(all[j],v)<0)v*=-1;
					all[j]+=v;
					break;
				}
			}
			if(ok)all.push_back(v);
		}
		debug(all.size());
		if(all.size()==1)return (all[0]).norm();
		llint ans=0;
		for(int i=0;i<all.size();i++)cerr<<all[i]<<" ";cerr<<endl;
		for(int i=0;i<all.size();i++)
		for(int j=i+1;j<all.size();j++)
		{
			const point dir=all[i]*all[j];
			hline();
			debug(dir);
			debug(all[i]);
			debug(all[j]);
			vector<point> plane;
			point sum(0,0,0);
			for(int k=0;k<all.size();k++)
			{
				llint sig=dot(dir,all[k]);
				if(sig==0)plane.push_back(all[k]);
				else if(sig>0)sum+=all[k];
				else sum-=all[k];
			}
			debug(sum);
			debug(plane.size());
			for(int k=(int)(plane.size())-1;k>=0;k--)
				plane.push_back(plane[k]*-1);
			for(int a=0;a<plane.size();a++)
			{
				point psum=plane[a];
				for(int b=0;b<plane.size();b++)
				{
					point dd=plane[b]*plane[a];
					llint ss=dot(dd,dir);
					if(ss>0)psum+=plane[b];
				}
				psum+=sum;
				ans=max(ans,psum.norm());
			}
			debug(all[i]);
			debug(all[j]);
			debug(ans);
		}
		return ans;
	}
};
/*
int main()
{
	ConstructPolyline con;
	cout<<con.maximizeLength(vector<int>(),vector<int>(),vector<int>());
	return 0;

}
*/
