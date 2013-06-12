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
const int N=2000;
double mat[N][N],bb[N];
map<vector<int>,int > mem;

void genEquation(vector<int>& state,queue<vector<int> >& qq,double mat[])
{
	mat[mem[state]]=-1.0;
	int sum=accumulate(state.begin(),state.end(),0);
	for(int i=0;i<state.size();i++)
	for(int j=0;j<state.size();j++)
	{
		vector<int> nstate=state;
		double p=1.0*nstate[i]/sum;
		nstate[i]--;
		if(nstate[j]==0)continue;
		p*=1.0*nstate[j]/(sum-1);
		nstate[j]--;
		nstate[i]+=2;
		sort(nstate.begin(),nstate.end());
		while(nstate[0]==0)nstate.erase(nstate.begin());
		if(nstate.size()==1)continue;
		if(mem.count(nstate)==0)mem[nstate]=mem.size()-1,qq.push(nstate);
		mat[mem[nstate]]+=p;
	}
}
const double eps=1e-10;
bool Guass(double mat[][N],double bb[N],double ans[],int n)
{
	for(int k=0;k<n;k++)
	{
		double best=eps;
		int ind=-1;
		for(int i=k;i<n;i++)
			if(fabs(mat[i][k])>best)
				ind=i,best=fabs(mat[i][k]);
		if(ind==-1)return false;
		for(int i=k;i<n;i++)swap(mat[k][i],mat[ind][i]);
		swap(bb[k],bb[ind]);
		for(int i=k+1;i<n;i++)
		{
			if(fabs(mat[i][k])<eps)continue;
			double cof=mat[i][k]/mat[k][k];
			for(int j=k;j<n;j++)
				mat[i][j]-=cof*mat[k][j];
			bb[i]-=cof*bb[k];
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		double sum=bb[i];
		for(int j=i+1;j<n;j++)
			sum-=ans[j]*mat[i][j];
		assert(fabs(mat[i][i])>eps);
		ans[i]=sum/mat[i][i];
	}
	return true;
}

int cnt[26];
double ans[N];
class ColorfulBalls {
	public:
	double expectedStepCount(string colors) 
	{
		queue<vector<int> > qq;
		for(int i=0;i<colors.length();i++)
			cnt[colors[i]-'A']++;
		vector<int> state;
		for(int i=0;i<26;i++)
			if(cnt[i])state.push_back(cnt[i]);
		if(state.size()==1)return 0.0;
		sort(state.begin(),state.end());
		int top=0;
		qq.push(state);
		while(qq.size())
		{
			state=qq.front();qq.pop();
			genEquation(state,qq,mat[top]);
			bb[top]=-1.0;
			top++;
		}
		debug(top);
		bool f=Guass(mat,bb,ans,top);
		assert(f);
		return ans[0];
	}
};
int main()
{
	string ss;
	for(int i=0;i<24;i++)ss.push_back('A'+i);
	ColorfulBalls cc;
	cout<<cc.expectedStepCount(ss)<<endl;
	return 0;
}
