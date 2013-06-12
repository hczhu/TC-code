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

int mem[41][21][21][21][21];
const int inf=1000000;
#define two(x) ((1)<<(x))
int row[100];
bool zero[5];
int DP(vector<int> sum,int pos,int n)
{
	int mm=*max_element(sum.begin(),sum.end());
	if(pos==n)return mm==0?0:inf;
	if(mm>n-pos)return inf;
	if(mem[pos][sum[0]][sum[1]][sum[2]][sum[3]])
		return mem[pos][sum[0]][sum[1]][sum[2]][sum[3]]-1;
	int& res=mem[pos][sum[0]][sum[1]][sum[2]][sum[3]];
	res=inf;
	for(int i=0;i<5;i++)
	{
		bool ok=true;
		vector<int> nsum=sum;
		for(int j=0;j<5;j++)
		{
			nsum[j]-=(zero[j]?1:0)^((row[pos]>>j)&1);
			if(nsum[j]<0)
			{
				ok=false;
				break;
			}
		}
		if(ok)res=min(res,DP(nsum,pos+1,n)+i);
		row[pos]<<=1;
		row[pos]^=(row[pos]>>5)&1;
	}
	res++;
	return res-1;
}

class BinaryMatrix {
	public:
	vector <string> getMaximalLexicographically(vector <string> matrix, vector <int> columns, int maxMoveCount) 
	{
		const int n=matrix.size();
		int all=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			all+=matrix[i][j]-'0',row[i]^=((matrix[i][j]-'0')<<j);
		if(all!=accumulate(columns.begin(),columns.end(),0))
			return vector<string>();
		vector<string> res;
		for(int i=0;i<5;i++)
		{
			if(columns[i]>n)return res;
			if(columns[i]>n/2)
			{
				zero[i]=true;
				columns[i]=n-columns[i];
			}
		}
		int need=DP(columns,0,n);

		debug(need);
		if(need>maxMoveCount) return res;
		int rem=maxMoveCount;
		for(int pos=0;pos<n;pos++)
		{
			hline();
			int add=0;
			string best="00000";best[0]--;
			for(int i=0;i<5;i++)
			{
				vector<int> nsum=columns;
				for(int j=0;j<5;j++)nsum[j]-=(zero[j]?1:0)^(matrix[pos][j]-'0');
				if(*min_element(nsum.begin(),nsum.end())>=0&&matrix[pos]>best&&DP(nsum,pos+1,n)+i<=rem)
					best=matrix[pos],add=i;
				char last=matrix[pos][4];
				for(int j=3;j>=0;j--)
					matrix[pos][j+1]=matrix[pos][j];
				matrix[pos][0]=last;
			}
			debug(pos);
			debug(rem);
			debug(best);
			res.push_back(best);
			rem-=add;
			for(int i=0;i<5;i++)columns[i]-=(zero[i]?1:0)^(best[i]-'0');
		}	
		return res;
	}
};
