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
#define Low(x) ((((x)^((x)-1))&x))
#define Two(x)  ((1)<<(x))
#define BitIndex(x) (((unsigned int)(x)*0x077CB531U)>>27)
char subset_cnt[1<<16][26];
int common_len[1<<16];
int dp[1<<16];
class PrefixTree {
	public:
	int getNumNodes(vector <string> words) 
	{
		
		/*
		srand(time(NULL));
		words.clear();
		for(int i=0;i<16;i++)
		{
			words.push_back(string(50,'a'));
			for(int j=0;j<50;j++)words[i][j]='a'+(rand()%26);
		}*/
		const int n=words.size();
		for(int i=0;i<n;i++)
		for(int j=0;j<words[i].length();j++)
			subset_cnt[Two(i)][words[i][j]-'a']++;
		for(int j=0;j<26;j++)subset_cnt[0][j]=100;
		for(int mk=1;mk<Two(n);mk++)
		{
			int low=Low(mk);
			for(int j=0;j<26;j++)
				subset_cnt[mk][j]=min(subset_cnt[mk^low][j],subset_cnt[low][j]);
			common_len[mk]=accumulate(subset_cnt[mk],subset_cnt[mk]+26,(char)0);
			if(low==mk)
			{
				dp[mk]=common_len[mk]+1;
				continue;
			}
			dp[mk]=51*n;
			const int com=common_len[mk]+1;
			for(int s=(mk-1)&mk;s;s=(s-1)&mk)
			{
				dp[mk]=min(dp[s]+dp[s^mk]-com,dp[mk]);
			}
		}
		return dp[Two(n)-1];
	}
};

/*
int main()
{

	PrefixTree pt;
	string all[]={"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", "cccccccccccccccccccccccccccccccccccccccccccccccccc", "dddddddddddddddddddddddddddddddddddddddddddddddddd", "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", "ffffffffffffffffffffffffffffffffffffffffffffffffff", "gggggggggggggggggggggggggggggggggggggggggggggggggg", "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh", "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii", "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk", "llllllllllllllllllllllllllllllllllllllllllllllllll", "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm", "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn", "oooooooooooooooooooooooooooooooooooooooooooooooooo", "pppppppppppppppppppppppppppppppppppppppppppppppppp"};
	vector<string> words;
	for(int i=0;i<16;i++)words.push_back(all[i]);
	cout<<pt.getNumNodes(words)<<endl;
	return 0;
}
*/

