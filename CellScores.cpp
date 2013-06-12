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

const int S=1501;
char color[S][S];
int mult[S][S];
llint top[S][S],bottom[S][S];
llint height[S],row1[S],row2[S];
int stack[S+1];
void get_bottom_right(llint height[],llint ans[],int N)
{
	height[0]=-1;
	ans[0]=0;
	int top=0;
	stack[top++]=0;
	for(int i=1;i<=N;i++)
	{
		while(height[stack[top-1]]>=height[i])top--;
		ans[i]=(llint)(i-stack[top-1])*height[i]+ans[stack[top-1]];
		stack[top++]=i;
	}
	//for(int i=1;i<=N;i++)cerr<<ans[i]<<" ";cerr<<endl;
}
class CellScores {
//Review your code before submission!!!!
	public:
	long long countScores(int N, int M, int K, int X0, int A, int B, int Y0, int C, int D) {
		int X = X0%N;
		int Y = Y0%N;
		for(int i=0;i<M+K;i++)
		{
			//cerr<<X<<" -- "<<Y<<endl;
			if(i<M)color[X+1][Y+1]=1;
			else mult[X+1][Y+1]++;
			X = (X*A+B)%N;
			Y = (Y*C+D) % N;
		}
		memset(height,0,sizeof(llint)*(N+1));
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
				height[j]=(1==color[i][j])?0:height[j]+1;
			get_bottom_right(height,row1,N);
			for(int j=1;j<=N/2;j++)swap(height[j],height[N+1-j]);
			get_bottom_right(height,row2,N);
			for(int j=1;j<=N/2;j++)swap(height[j],height[N+1-j]);
			for(int j=1;j<=N/2;j++)swap(row2[j],row2[N+1-j]);
			llint psum2=0,psum1=0;
			for(int j=1;j<=N;j++)
			{
				psum2+=row2[j];
				bottom[i][j]=psum2-psum1;
				psum1+=row1[j];
			}
		//	for(int j=1;j<=N;j++)cerr<<bottom[i][j]<<" ";cerr<<endl;
		}

		hline();
		memset(height,0,sizeof(llint)*(N+1));
		for(int i=N;i>=1;i--)
		{
			for(int j=1;j<=N;j++)
				height[j]=(1==color[i][j])?0:height[j]+1;
			get_bottom_right(height,row1,N);
			for(int j=1;j<=N/2;j++)swap(height[j],height[N+1-j]);
			get_bottom_right(height,row2,N);
			for(int j=1;j<=N/2;j++)swap(height[j],height[N+1-j]);
			for(int j=1;j<=N/2;j++)swap(row2[j],row2[N+1-j]);
			llint psum2=0,psum1=0;
			for(int j=1;j<=N;j++)
			{
				psum2+=row2[j];
				top[i][j]=psum2-psum1;
				psum1+=row1[j];
			}
			//for(int j=1;j<=N;j++)cerr<<top[i][j]<<" ";cerr<<endl;
		}
		hline();
		llint res=0;
		for(int j=1;j<=N;j++)
		{
			llint top_sum=0,bottom_sum=0;
			for(int i=1;i<=N;i++)
			{
				top_sum+=top[i][j];
				res+=(top_sum-bottom_sum)*mult[i][j];

				//cerr<<top_sum-bottom_sum<<" ";
				bottom_sum+=bottom[i][j];
			}
			//cerr<<endl;
		}
		return res;
	}
};


// Powered by FileEdit
