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
typedef long long int llint;
const llint inf=1000000000000000001LL;
llint dp[1<<8][51];
int bcnt[1<<9];
#define two(x)  ((1)<<(x))
bool check(const string& str,int n,int d)
{
	if(str.length()<n)return true;
	int cnt[26]={0};
	int have=0;
	for(int i=0;i<n-1;i++)
	{
		if(cnt[str[i]-'a']++==0)have++;
	}
	for(int i=n-1;i<str.length();i++)
	{
		if(cnt[str[i]-'a']++==0)have++;
		if(i>=n&&cnt[str[i-n]-'a']--==1)have--;
		if(have>d)return false;
	}
	return true;

}
llint cnt[51];
int get_mask(const string& str,int n)
{
	const int len=str.length();
	bool have[26]={false};
	int mk=0;
	for(int i=1;i<n&&len-i>=0;i++)
	{
		if(!have[str[len-i]-'a'])mk^=two(n-1-i);
		have[str[len-i]-'a']=true;
	}
	return mk;
}
class NextHomogeneousStrings {
//Review your code before submission!!!!
	public:
	string getNext(int d, int n, string seed, long long k) 
	{
		debug(k);
		for(int i=0;i<two(n);i++)
		for(int j=0;j<n;j++)
			if(two(j)&i)bcnt[i]++;
		for(int mk=0;mk<two(n-1);mk++)
			if(bcnt[mk]<=d)dp[mk][0]=1;
		const int m=seed.length();
		for(int i=1;i<=seed.length();i++)
		for(int pre=0;pre<two(n-1);pre++)
		{
			llint x=bcnt[pre];
			if(x>d)continue;
			llint& res=dp[pre][i];
			//pick new character
			if(bcnt[pre]+1<=d)
			{
				for(int j=0;j<26-x;j++)
				{
					res+=dp[(pre>>1)^two(n-2)][i-1];
					if(res>inf)res=inf;
				}
			}
			for(int j=0;j<n-1;j++)
			{
				if(two(j)&pre)
				{
					res+=dp[((two(j)^pre)>>1)^two(n-2)][i-1];
					if(res>inf)res=inf;
				}
			}
			//cerr<<pre<<" "<<i<<"="<<res<<endl;
			assert(res>=0&&res<=inf);
		}
		cnt[m]=check(seed,n,d)?1:0;
		for(int i=m-1;i>=0;i--)
		{
			if(!check(seed.substr(0,i),n,d))continue;
			cnt[i]=cnt[i+1];
			int pre=get_mask(seed.substr(0,i),n);
			debug(i);
			debug(pre);
			for(char x=seed[i]+1;x<='z';x++)
			{
				string tmp=seed.substr(0,i);
				tmp.push_back(x);
				if(!check(tmp,n,d))continue;
				int next=pre;
				for(int j=n-2;j>=0&&i-(n-1-j)>=0;j--)
				{
					if(seed[i-(n-1-j)]==x)
					{
						assert(next&two(j));
						next^=two(j);
						break;
					}
				}
				if(bcnt[next]+1>d)continue;
				next>>=1;next^=two(n-2);
				cnt[i]+=dp[next][m-i-1];
				cnt[i]=min(cnt[i],inf);
				assert(cnt[i]>=0);
			}
		}
		debug("cnt");
		debug(k);
		for(int i=0;i<=m;i++)cerr<<cnt[i]<<" ";cerr<<endl;
		if(cnt[0]<=k)return "";
		string ret="";
		while(ret.length()<m)
		{
			assert(k>=0);
			const int len=ret.length();
			char start='a';
			if(ret==seed.substr(0,ret.length()))
			{
				if(k<cnt[len+1])
				{
					ret.push_back(seed[len]);
					//cerr<<ret<<" "<<k<<endl;
					continue;
				}
				k-=cnt[len+1];
				start=seed[len]+1;
			}
			bool f=false;
			for(char x=start;x<='z';x++)
			{
				string tmp=ret;tmp.push_back(x);
				if(!check(tmp,n,d))continue;
				int mk=get_mask(tmp,n);
				if(dp[mk][m-len-1]>k)
				{
					ret=tmp;
					f=true;
					break;
				}
				k-=dp[mk][m-len-1];
			}
			//cerr<<ret<<" "<<k<<endl;
			assert(f);
		}
		assert(ret.length()==seed.length());
		return ret;
	}
};

/*
int main()
{
	debug(inf+inf);
	NextHomogeneousStrings next;
	int n,d;
	string seed;
	llint k;
	cin>>d>>n>>seed>>k;
	debug(seed);
	debug(k);
	cout<<next.getNext(d,n,seed.substr(1,seed.length()-2),k)<<endl;
	return 0;
}
*/
