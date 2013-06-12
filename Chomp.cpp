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
int table[101][101][101];
bool win[101][101][101];
class Chomp
{
	public:
	int moves(int n)
	{
	 win[0][0][0]=true;
    for(int i=0;i<=n;i++)
    for(int j=i;j<=n;j++)
    for(int k=max(j,1);k<=n;k++)
    {
        win[i][j][k]=false;
        for(int x=1;x<=k;x++)
        {
            if((x<=i&&!win[i-x][j][k])||(x<=j&&!win[min(j-x,i)][j-x][k])||(x<=k&&!win[min(i,k-x)][min(j,k-x)][k-x]))
            {
                win[i][j][k]=true;
                break;
            }
        }
        if(win[i][j][k])
        {
            table[i][j][k]=i+j+k;
            for(int x=1;x<=k;x++)
            {
                if(x<=i&&!win[i-x][j][k])
                    table[i][j][k]=min(table[i][j][k],table[i-x][j][k]+1);
                if(x<=j&&!win[min(i,j-x)][j-x][k])
                    table[i][j][k]=min(table[i][j][k],table[min(i,j-x)][j-x][k]+1);
                if(x<=k&&!win[min(i,k-x)][min(j,k-x)][k-x])
                    table[i][j][k]=min(table[i][j][k],table[min(i,k-x)][min(j,k-x)][k-x]+1);
            }
        }
        else
        {
            table[i][j][k]=0;
            for(int x=1;x<=k;x++)
            {
                if(x<=i)table[i][j][k]=max(table[i][j][k],table[i-x][j][k]+1);
                if(x<=j)table[i][j][k]=max(table[i][j][k],table[min(i,j-x)][j-x][k]+1);
                if(x<=k)table[i][j][k]=max(table[i][j][k],table[min(i,k-x)][min(j,k-x)][k-x]+1);
            }
        }
    }
    return win[n][n][n]?table[n][n][n]:-table[n][n][n];	
	};
	
};
