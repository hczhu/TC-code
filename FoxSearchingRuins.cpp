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
#include <limits>
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
template <int Len,typename T=int>
class range_maxer_t {
	T _tree[Len];
	inline int lowbit(int x) {
		return (x^(x-1))&x;
	}
public:
	range_maxer_t() {
		for(int i=0;i<Len;i++) {
			_tree[i]=numeric_limits<T>::min();
		}
	}
	void update(int pos,T v) {
		assert(pos>=0);
		assert(pos<Len);
		while(pos<Len) {
			_tree[pos] =max(_tree[pos],v);
			pos+=lowbit(pos+1);
		}
	}
	T query(int right_bound) {
		assert(right_bound<Len);
		T res=numeric_limits<T>::min();
		while(right_bound>=0) {
			res=max(res,_tree[right_bound]);
			right_bound-=lowbit(right_bound+1);
		}
		return res;
	}
};
range_maxer_t<1000> gg[2001],hh[2001];
int ff[3][1000][1001];
class FoxSearchingRuins {
	public:
	long long theMinTime(int W, int H, int jewelCount, int LR, int goalValue, int timeX, int timeY, vector <int> seeds) {
		vector<llint> x(jewelCount),y(jewelCount),v(jewelCount);
		x[0] = ((llint)seeds[1] * seeds[0] + seeds[2]) % W;
		y[0] = ((llint)seeds[4] * seeds[3] + seeds[5]) % H;
		v[0] = ((llint)seeds[7] * seeds[6] + seeds[8]) % seeds[9];
		for (int i=1 ;i< jewelCount;i++) {
			x[i] = ((llint)seeds[1] * x[i-1] + seeds[2]) % W;
			y[i] = ((llint)seeds[4] * y[i-1] + seeds[5]) % H;
			v[i] = ((llint)seeds[7] * v[i-1] + seeds[8]) % seeds[9];
		}
		const int n=x.size();
		typedef pair<int,int> ppt;
		map<llint,vector<ppt> > mem;
		for(int i=0;i<n;i++) {
			mem[H-1-y[i]].push_back(ppt((int)x[i],(int)v[i]));
		}
		llint ans=numeric_limits<llint>::max();
		for(map<llint,vector<ppt> >::reverse_iterator itr=mem.rbegin();itr!=mem.rend();++itr) {
			debug(itr->first);
			vector<ppt>& row=itr->second; 
			sort(row.begin(),row.end());
			vector<int> xx(row.size()),v(row.size());
			for(int i=0;i<row.size();i++) xx[i]=row[i].first,v[i]=row[i].second;
			for(int i=0;i<row.size();i++)
			for(int m=0;m<=LR;m++) {
				ff[2][i][m]=0;
				ff[2][i][m]=max(hh[m+xx[i]].query(W-1-xx[i]),ff[2][i][m]);
				ff[2][i][m]=max(ff[2][i][m],gg[W+m-xx[i]].query(xx[i]));
				ff[1][i][m]=ff[2][i][m];
				if(i&&m>=xx[i]-xx[i-1])
					ff[1][i][m]=max(ff[1][i][m],ff[1][i-1][m-(xx[i]-xx[i-1])]+v[i-1]);
			}
			for(int i=row.size()-1;i>=0;i--)	
			for(int m=0;m<=LR;m++) {
				ff[0][i][m]=ff[2][i][m];
				if(i+1<row.size()&&m>=xx[i+1]-xx[i])
					ff[0][i][m]=max(ff[0][i][m],ff[0][i+1][m-(xx[i+1]-xx[i])]+v[i+1]);
				int tt=max(ff[0][i][m],ff[1][i][m])+v[i];
				hh[m+xx[i]].update(W-1-xx[i],tt);
				gg[m-xx[i]+W].update(xx[i],tt);
				/*debug(tt);
				debug(gg[W].query(3));
				debug(m-xx[i]+W);
				debug(xx[i]);*/
				if(tt>=goalValue) {
					ans=min(ans,(llint)(H-1-itr->first)*(llint)(timeY)+(llint)m*(llint)timeX);
				}
				//cerr<<(H-1-itr->first)<<","<<xx[i]<<" "<<m<<"="<<
				//	ff[0][i][m]<<" "<<ff[1][i][m]<<" "<<ff[2][i][m]<<endl;
			}
		}
		if(ans==numeric_limits<llint>::max())ans=-1;
		return ans;
	}
};
/*
int main() {
}
*/
