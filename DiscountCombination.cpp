#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <assert.h>
using namespace std;
typedef long long int llint;
#define N 30
#define EPS 1e-10
#define INF 2000000000
#define LOW(x) ((((x)^((x)-1))&x))
#define Debug(x) cout<<#x<<"=\""<<x<<"\""<<endl;
#define Hline() do{cout<<"-------------------------------"<<endl;}while(0)
class DiscountCombination
{
	public:
	int table[51][51][51];
	double money[51][51][51];
	int pay[50],dis[50];
	double minimumPrice(vector <string> discount, int price)
	{
		const int n=discount.size();
		for(int i=0;i<n;i++)
			sscanf(discount[i].c_str(),"%d %d",pay+i,dis+i);
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)
			table[i][j][k]=2000000000;
		table[0][0][0]=0;
		for(int x=0;x<n;x++)
		for(int i=n;i>=0;i--)
		for(int j=n;j>=0;j--)
		for(int k=n;k>=0;k--)
		{
			if(dis[x]==1)
				table[i+1][j][k]=min(table[i+1][j][k],table[i][j][k]+pay[x]);
			else if(dis[x]==2)
				table[i][j+1][k]=min(table[i][j+1][k],table[i][j][k]+pay[x]);
			else if(dis[x]==3)
				table[i][j][k+1]=min(table[i][j][k+1],table[i][j][k]+pay[x]);
		}
		money[0][0][0]=1.0*price;
		double re=1.0*INF;
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)
		{
			if(i)money[i][j][k]=money[i-1][j][k]*0.99;
			else if(j)money[i][j][k]=money[i][j-1][k]*0.98;
			else if(k)money[i][j][k]=money[i][j][k-1]*0.97;
			re=min(re,table[i][j][k]+money[i][j][k]);
			cout<<i<<" "<<j<<" "<<k<<" "<<re<<endl;
		}
		return re;
	};
	
};
