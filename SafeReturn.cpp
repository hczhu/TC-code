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
//INT_MAX INT_MIN
#include <limits.h>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<(b);++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()

template<int N>
class bipartite_match_t
{
public:
int rset[N];
int rmatch[N];
int ff;
bool augment(int v,const vector<vector<int> >& edge)
{
	for(int i=0;i<edge[v].size();i++)
	{
		int u=edge[v][i];
		if(ff==rset[u])continue;
		rset[u]=ff;
		if(rmatch[u]==-1||augment(rmatch[u],edge))
		{
			rmatch[u]=v;
			return true;
		}
	}
	return false;
}
int maxMatch(int n,int m,const vector<vector<int> >& edge)
{
	memset(rset,0,sizeof(rset[0])*m);
	memset(rmatch,0xff,sizeof(int)*m);
	int res=0;
	ff=1;
	for(int i=0;i<n;i++)
	{
		if(!augment(i,edge))continue;
		res++;
		ff++;
		//memset(rset,false,sizeof(bool)*m);
	}
	return res;
}
};

int edge[100][100];
int dis[100][100];
const int inf=1000000;
class SafeReturn {
 public:
  int minRisk(int N, vector <string> streets) {
    debug("Start calculation.");
    const int n =SZ(streets);
    Rep(i, n)Rep(j, n) {
      edge[i][j]= (streets[i][j]!='-')?streets[i][j] - '0':inf;
      dis[i][j]=edge[i][j];
    }
    Rep(i,n)dis[i][i]=0;
    Rep(k,n)Rep(i,n)Rep(j,n)dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    Rep(i, n) {
      Rep(j, n)cerr<<dis[i][j]<<" ";
      cerr<<endl;
    }
    vector<vector<int> > medge(N);
    Rep(a, N) Rep(b, N) if(a!=b){
      if (dis[0][b+1]==dis[0][a+1] + dis[a+1][b+1]) {
        cerr<<a+1 << " --->" <<  b+1 <<endl;
        medge[a].push_back(b);
      }
    }
    bipartite_match_t<100> matcher;
    const int M = matcher.maxMatch(N, N, medge);
    debug(M);
    assert(M+1 <= N);
    return N - M;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"-234",
 "2---",
 "3---",
 "4---"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"-12",
 "1-1",
 "21-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; string Arr1[] = {"-11",
 "1-1",
 "11-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minRisk(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SafeReturn ___test;
  ___test.run_test(-1);
}
// END CUT HERE
