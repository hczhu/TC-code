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
//*******************************************
const int mod=1000000007;
const int N=2510;
int dp[N][N];
string all;
int Isum[N];
int n;
int DP(int a,int b)
{
	assert(0<a&&a<b&&b<=n);
	//if(b>n)return Isum[n]==Isum[a]?1:0;
	if(dp[a][b]!=-1)return dp[a][b];
	int& res=dp[a][b];
	res=0;
	int c=2*b-a;
	if(c<=n&&(all[c]=='?'||all[c]=='I')&&Isum[c-1]==Isum[b])
		res=DP(b,c);
	if(Isum[n]==Isum[b])res++;
	res%=mod;
	cerr<<a<<" "<<b<<" "<<res<<endl;
	return res;
}
class IOIString {
//Review your code before submission!!!!
	public:
	int countIOIs(vector <string> mask) {
		debug(2*mod);
		all=".";
		for(int i=0;i<mask.size();i++)all+=mask[i];
		//all=".";for(int i=0;i<2500;i++)all+="?";
		n=all.length()-1;
		debug(all);
		memset(dp,0xff,sizeof(dp));
		for(int i=1;i<all.length();i++)Isum[i]=Isum[i-1]+(all[i]=='I'?1:0);
		int ans=0;
		bool haveI=false;
		for(int a=1;a<all.length();a++)
		{
			if(all[a]=='?'||all[a]=='I')
			{
				bool anotherI=false;
				for(int b=a+1;b<all.length();b++)
				{
					if((all[b]=='?'||all[b]=='I')&&((a+b)&1))
					{
						ans+=DP(a,b);
						cerr<<a<<" -- "<<b<<"="<<ans<<endl;
					}
					if(all[b]=='I')
					{
						anotherI=true;
						break;
					}
				}
				if(!anotherI)ans++;
			}
			if(all[a]=='I')
			{
				haveI=true;
				break;
			}
		}
		if(!haveI)ans++;
		debug(ans);
		int sum=1;
		for(int i=1;i<all.length();i++)
			if(all[i]=='?')sum*=2,sum%=mod;
		debug(sum);
		ans=(sum+mod-ans)%mod;
		return ans;
	}
};

int main()
{
	IOIString IOI;
	vector<string> mask;
	string ss;
	while(cin>>ss)
	{
		mask.push_back(ss);
	}
	cout<<IOI.countIOIs(mask)<<endl;
	return 0;
}

// Powered by FileEdit
