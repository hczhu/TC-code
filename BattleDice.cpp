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

double dice_win_dice(int d1[],int d2[],int n)
{
	double win=0.0,tie=0.0;
	const double add=1.0/n/n;
	for(int i=0,j=0;i<n;i++)
	{
		while(j<n&&d2[j]<d1[i])j++;
		win+=add*j;
	}
	for(int i=0,a=0,b=0;i<n;i++)
	{
		while(a<n&&d2[a]<d1[i])a++;
		while(b<n&&d2[b]<=d1[i])b++;
		tie+=(b-a)*add;
	}
	return win/(1.0-tie);
}

int stack[100];

double win[3][3];
double mywin(int dice1[],int dice2[],int dice[],int n)
{
	win[0][2]=dice_win_dice(dice1,dice,n);
	win[2][0]=1.0-win[0][2];
	win[1][2]=dice_win_dice(dice2,dice,n);
	win[2][1]=1.0-win[1][2];
	double worst=1.0;
	for(int j=0;j<3;j++)
	{
		double my=max(win[(j+1)%3][j],win[(j+2)%3][j]);
		worst=min(worst,my);
	}
	return worst;
}
double best=-1;
vector<int> res;
int dice1[10],dice2[10];
int n;
void genAll(int pos,int m,int rem,int top)
{
	for(int i=0;i<rem;i++)stack[top+i]=pos;
	if(pos==m)
	{
		double t=mywin(dice1,dice2,stack,n);
		if(t>best)best=t,res=vector<int>(stack,stack+rem+top);
		return;
	}
	for(int i=rem;i>=0;i--)
		genAll(pos+1,m,rem-i,top+i);
}
class BattleDice {
	public:
	vector <int> die3(vector <int> die1, vector <int> die2, int range) 
	{
		n=die1.size();
		sort(die1.begin(),die1.end());
		sort(die2.begin(),die2.end());
		copy(die1.begin(),die1.end(),dice1);
		copy(die2.begin(),die2.end(),dice2);
		win[0][1]=dice_win_dice(dice1,dice2,n);
		win[1][0]=1.0-win[0][1];
		debug(win[0][1]);
		genAll(1,range,n,0);
		return res;
	}

};
/*
int main()
{
	genAll(1,15,10,0);
	debug(dtop);
	return 0;
}
*/
