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
#include <cassert>
#include <limits>
#include <cstdarg>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
/*********************************
 Tips
 * Binary search
 * Ternary search
 * Bitwise tricks
 * Bipartite matching
 * Graph algorithms
 * DP
 * Subset DP
 * Greedy algorithms
 * Network flow
 * Construct the solution directly
 * Be careful to the input constraints
 * Corner cases.
**********************************/
string all;
int A[10000],B[10000];
int dp[2501][2501];
const int mod=1000000007;
int mem[2501][11];
int check(const string& ss) {
	int res=0;
	set<string> mem;
	for(int i=1;i<=ss.length();i++) {
		int a=i-1;
		int b=ss.length()-1;
		bool ta=true;
		string s;
		while(a>=0||b>=i) {
			if(ta&&a<0)break;
			if(!ta&&b<i)break; 
			if(ta) {
				if(ss[a]=='B')ta=false;
				s.push_back(ss[a]);
				a--;
			}
			else {
				if(ss[b]=='A')ta=true;
				s.push_back(ss[b]);
				b--;
			}
		}
		if(a<0&&b<i)mem.insert(s);
	}
	assert(mem.size()<=2);
	return mem.size();
}
class Stackol {
	public:
	int countPrograms(vector <string> output, int m) {
		all=accumulate(output.begin(),output.end(),string(""));
		debug(all);
		const int n=all.length();
		for(int i=1;i<=n;i++) {
			A[i]=A[i-1];
			B[i]=B[i-1];
			if(all[i-1]=='A')A[i]++;
			else B[i]++;
		}
		for(int i=0;i<n;i++) {
			for(int j=i,k=0;j<n;j++) {
				if(B[j+1]==B[i]) {
					dp[i][j]++;
					continue;
				}
				int nb=B[j+1]-B[i];
				if(k<j)k=j;
				while(k<n&&A[k+1]-A[j+1]<nb-1)k++;
				const int pk=k;
				if(all[i]=='B') {
					while(k<n&&A[k+1]-A[j+1]==nb-1) {
						dp[i][k]++;
						k++;
					}
				}
				if(j+1<n&&all[j+1]=='A') {
					while(k<n&&A[k+1]-A[j+1]<nb)k++;
					while(k<n&&A[k+1]-A[j+1]==nb) {
						dp[i][k]++;
						k++;
					}
				}
				k=pk;
			}
			/*for(int j=i;j<n;j++) {
				//if(dp[i][j])cerr<<all.substr(i,j-i+1)<<" "<<i<<"-->"<<j<<endl;
				assert(dp[i][j]==check(all.substr(i,j-i+1)));
			}*/
		}
		for(int i=0;i<=m;i++) {
			mem[0][i]=1;
		}
		for(int i=1;i<=n;i++) {
			for(int p=0;p<i;p++) {
				if(!dp[p][i-1])continue;
				for(int j=1;j<=m;j++) {
					mem[i][j]+=mem[p][j-1]*dp[p][i-1]%mod;
					mem[i][j]%=mod;
				}
			}
			for(int j=1;j<=m;j++) {
				mem[i][j]+=mem[i][j-1];
				mem[i][j]%=mod;
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++) {
			ans+=mem[n][i];
			ans%=mod;
			debug(i);
			debug(mem[n][i]);
		}
		return ans;
	}
};
/*
int main() {
	Stackol ss;
	vector<string> input;
	input.push_back("AAABABABAABAAABBAB");
	//input.push_back("AAAAAAAAAAAAB");
	cout<<ss.countPrograms(input,3)<<endl;
	return 0;
}
*/
