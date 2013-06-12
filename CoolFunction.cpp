#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
bool table[100][100][100];
class CoolFunction
{
	public:
	vector <int> restore(vector <int> values)
	{
		const int n=values.size();
		if(n==1)
			return vector<int>(1,-values[0]);
		vector<int> dy;
		vector<int> res;
		for(int i=1;i<n;i++)
			dy.push_back(values[i]-values[i-1]);
		int xdy=dy[0],sum=values[0];
		for(int i=1;i<dy.size();i++)
		{
			int d=dy[i]-dy[i-1];
			if(d<0||(d&1))cout<<"Error"<<endl;
			d>>=1;
			while(d--)res.push_back(i),xdy++,sum-=i,cout<<"push "<<i<<endl;
		}
		cout<<xdy<<" "<<sum<<endl;
		table[0][0][0]=true;
		for(int k=0;;k++)
		{
			for(int s=0;s<=sum;s++)
			for(int i=0;i<=k;i++)
			{
				int j=k-i;
				for(int v=0;v<=s;v++)
				{
					if(i&&table[i-1][j][s-v])
						table[i][j][s]=true;
					if(v>=n-1&&j&&table[i][j-1][s-v])
						table[i][j][s]=true;
				}
			}
			if((k+xdy)%2)continue;
			int x=(k+xdy)/2;
			int y=k-x;
			cout<<"check "<<x<<" "<<y<<endl;
			if(x<0||y<0)continue;
			if(table[x][y][sum])
			{
				cout<<x<<" "<<y<<" "<<sum<<" "<<xdy<<endl;
				while(x)
				{
					for(int v=sum;v>=0;v--)
					{
						if(table[x-1][y][sum-v])
						{
							sum-=v;
							x--;
							res.push_back(-v);
							cout<<"push "<<-v<<endl;
							break;
						}
					}
				}
				while(y)
				{
					for(int v=n-1;v<=sum;v++)
					{
						if(table[x][y-1][sum-v])
						{
							sum-=v;
							y--;
							res.push_back(v);
							cout<<"push "<<-v<<endl;
							break;
						}
					}
				}
				break;
			}
		}
		sort(res.begin(),res.end());
		return res;
	}
};
