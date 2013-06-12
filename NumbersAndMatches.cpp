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

const string digit[10]=
{
"012456",
"256",
"02346",
"02356",
"1235",
"01356",
"013456",
"025",
"0123456",
"012356"
};
#define two(x) ((1)<<(x))
int mask[10];
typedef long long int llint;
struct Node
{
	int move;
	int match;
	Node(int a,int b):move(a),match(b){};
};
bool operator<(const Node& a,const Node& b)
{
	return memcmp(&a,&b,sizeof(Node))<0;
}
bool operator>(const Node& a,const Node& b)
{
	return memcmp(&a,&b,sizeof(Node))>0;
}
map<Node,llint> mem[30];

int count_bits(int n)
{
	int res=0;
	while(n)res+=(n&1),n>>=1;
	return res;
}
vector<int> dig;
llint DP(int pos,int move,int match,const int up)
{
	if(move>up)return 0;
	if(pos==dig.size())return match==0?1:0;
	const Node code(move,match);
	if(mem[pos].count(code)) return mem[pos][code];
	llint res=0;
	for(int dest=0;dest<10;dest++)
	{
		int diff=mask[dest]^mask[dig[pos]];
		int out=mask[dig[pos]]&diff;
		int in=mask[dest]&diff;
		assert(out==(mask[dig[pos]]&out));
		assert(0==(in&mask[dig[pos]]));
		assert((mask[dig[pos]]^in^out)==mask[dest]);
		res+=DP(pos+1,move+count_bits(out),match+count_bits(out)-count_bits(in),up);
	}
	mem[pos][code]=res;
	cerr<<pos<<" "<<move<<" "<<match<<" = "<<res<<endl;
	return res;
}
class NumbersAndMatches {
//Review your code before submission!!!!
	public:
	long long differentNumbers(long long num, int up) {
		while(num)
		{
			dig.push_back(num%10);
			num/=10;
		}
		reverse(dig.begin(),dig.end());
		debug(dig.size());
		for(int d=0;d<10;d++)
		for(int j=0;j<digit[d].length();j++)
			mask[d]^=two(digit[d][j]-'0');
		return DP(0,0,0,up);
	}
};

/*
int main()
{
	NumbersAndMatches nn;
	llint n,m;
	cin>>n>>m;
	cout<<nn.differentNumbers(n,m)<<endl;
	return 0;
}
*/
