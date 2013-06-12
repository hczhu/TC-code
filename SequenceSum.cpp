
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
#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif

template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
	vector<T> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			T tmp;
			istringstream is(s);
			is>>tmp;
			re.push_back(tmp);
		}
	}
	return re;
}
vector<int> product(const vector<int>& a,const vector<int>& b)
{
	vector<int> res;
	for(int i=0;i<a.size();i++)
	for(int j=0;j<b.size();j++)
		res.push_back(a[i]+b[j]);
	return res;
}
vector<int> derive(const vector<int>& a)
{
	vector<int> res;
	for(int i=1;i<a.size();i++)
		res.push_back(a[i]-a[i-1]);
	return res;
}
vector<int> KMPmatch(const vector<int>& text,const vector<int>& pattern)
{
	const int n=text.size();
	const int m=pattern.size();
	assert(m);
	vector<int> fail(m);
	fail[0]=-1;
	for(int i=1,k=-1;i<pattern.size();i++)
	{
		while(k!=-1&&pattern[k+1]!=pattern[i])k=fail[k];
		if(pattern[k+1]==pattern[i])k++;
		fail[i]=k;
	}
	vector<int> ret;
	for(int i=0,k=-1;i<n;i++)
	{
		while(k!=-1&&text[i]!=pattern[k+1])k=fail[k];
		if(pattern[k+1]==text[i])k++;
		if(k==m-1)ret.push_back(i-m+1),k=fail[k];
	}
	return ret;
}
vector<int> shiftMatch(const vector<int>& text,const vector<int>& pat)
{
	assert(pat.size());
	if(pat.size()==1)
	{
		vector<int> ret(text.size());
		for(int i=0;i<ret.size();i++)ret[i]=i;
		return ret;
	}
	vector<int> dpat=derive(pat);
	vector<int> dtext=derive(text);
	vector<int> pos=KMPmatch(dtext,dpat);
	return pos;
}


typedef long long int llint;
class SequenceSum {
	public:
	long long findSubstring(vector <int> A, vector <int> B, vector <int> C, vector <int> D, 
			vector <int> E, vector <int> F, vector <string> Z) 
	{
		const int up=50*50*50;
		vector<int> pat=parse<int>(accumulate(Z.begin(),Z.end(),string("")));
		debug(pat.size());
		vector<int>  all[6]={A,B,C,D,E,F};
		vector<int> Y=all[5];
		int top=4;
		while(top>=0&&Y.size()*all[top].size()<=up)
			Y=product(all[top--],Y);
		debug(top);
		debug(Y.size());
		assert(Y.size()>=pat.size());
		vector<int> X=vector<int>(1,0);
		while(top>=0)X=product(all[top--],X);
		debug(X.size());
		const int n=X.size();
		const int m=Y.size();
		if((llint)n*(llint)m<(llint)pat.size())return -1;
		assert(m>=pat.size());
		llint res=(llint)n*(llint)m;
		map<int,int> reverseX;
		for(int i=n-1;i>=0;i--)reverseX[X[i]]=i;
		vector<int> pos=shiftMatch(Y,pat);
		debug(pos.size());
		for(int i=0;i<pos.size();i++)
		{
			int p=pos[i];
			//cerr<<"check position "<<p<<endl;
			if(reverseX.count(pat[0]-Y[p]))
			{
				debug(p);
				debug(pat[0]);
				debug(Y[p]);
				int x=reverseX[pat[0]-Y[p]];
				debug(x);
				res=min(res,(llint)x*(llint)m+p);
			}
		}
		debug(res);
		map<pair<int,int>,int> dreverseX;
		for(int i=n-1;i;i--)
			dreverseX[make_pair(X[i-1],X[i])]=i-1;
		for(int pre=1;pre<pat.size();pre++)
		{
			int d1=pat[pre-1]-Y.back();
			bool ok=true;
			for(int i=0;i<pre;i++)
				if(d1+Y[m-i-1]!=pat[pre-i-1])ok=false;
			int d2=pat[pre]-Y[0];
			for(int i=pre;i<pat.size();i++)
				if(d2+Y[i-pre]!=pat[i])ok=false;
			if(ok&&dreverseX.count(make_pair(d1,d2)))
			{
				int pos=dreverseX[make_pair(d1,d2)];
				cerr<<pre<<" "<<d1<<" "<<d2<<" "<<pos<<endl;
				res=min(res,(llint)pos*(llint)m+m-pre);
			}
		}
		if(res>=(llint)n*(llint)m)res=-1;
		return res;
	}
};
