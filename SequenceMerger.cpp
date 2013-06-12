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
typedef long long int llint;
const llint inf=1000000000;
template<typename T>
T convert(const string& ss)
{
	istringstream is(ss);
	T tmp;
	is>>tmp;
	return tmp;
}
vector<string> parse(const string& ss,const char* cut)
{
	vector<string> re;
	for(int j=0;j<ss.size();j++)
	{
		string s;
		while(j<ss.size()&&NULL==strchr(cut,ss[j]))
			s+=ss[j++];
		if(!s.empty())
		{
			re.push_back(s);
		}
	}
	return re;
}
llint parse_num(const string&  a)
{
	if(a.length()>10)return inf+1;
	return convert<llint>(a);
}

class SequenceMerger {
	public:
	vector <int> getVal(vector <string> seq, vector <int> pos) 
	{
		vector<vector<llint> > list;
		for(int i=0;i<seq.size();i++)
		{
			vector<string> all=parse(seq[i]," ");
			vector<llint> num(all.size()-1);
			for(int j=1;j<all.size();j++)
				num[j-1]=parse_num(all[j]);
			for(int j=0;j<num.size();j++)cerr<<num[i]<<" "<<endl;	
			list.push_back(num);
		}
		debug(list.size());
		vector<int> res(pos.size(),-1);
		for(int i=0;i<pos.size();i++)
		{
			llint p=pos[i];
			llint low=1,high=inf+1;
			while(low<high)
			{
				llint mid=(low+high)>>1;
				llint cnt=0;
				for(int j=0;j<seq.size();j++)
				{
					const vector<llint>& num=list[j];
					if(seq[j][0]=='A')
					{
						if(mid>=num[0])
						{
							llint add=min(num[2],(mid-num[0])/num[1]+1);
							cnt+=add;
						}
					}
					else if(seq[j][0]=='G')
					{
						if(mid>=num[0])
						{
							if(num[1]==1)cnt+=num[2];
							else 
							{
								llint k=num[0];cnt++;
								int cc=1;
								while(++cc<=num[2]&&k<=mid/num[1])cnt++,k*=num[1];
							}
						}
					}
					else
					{
						for(int k=0;k<num.size();k++)
							if(num[k]<=mid)cnt++;
					}
				}
				cerr<<mid<<" cnt="<<cnt<<endl;
				if(cnt>=p)high=mid;
				else low=mid+1;
			}
			if(low>inf)low=-1;
			res[i]=low;
			cerr<<p<<"="<<low<<endl;
		}
		return res;
	}
};
