#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10;
string a[MAXN];
int pre[MAXN][MAXN];
int v[MAXN];
int ans;
int T;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(pre,0,sizeof(pre));
	memset(v,0,sizeof(v));
	ans=0x7ffffff;
}

bool search(string a,string b,int b1)//在b中查找是否存在a为子串
{
	int la=a.length();
	int lb=b.length()-b1;
	if(la>lb)
		return 0;
	bool flag=0;
	for(int i=0;i<=lb-la;i++)
	{
		bool can=1;
		for(int j=0;j<=b.length()-i;j++)
			if(a[j]!=b[j+i])
				can=0;
		if(can)
			flag=1;
	}
	return flag;
}

void dfs(int x,int sum,int cur)
{
	if(cur==n+1)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			if(search(a[i],a[x],0))
			{
				cout<<a[i]<<" "<<a[x]<<endl;
				dfs(x,sum,cur+1);
			}
			else
			{
				int d=a[x].length();
				for(int j=d-a[i].length();j<d;j++)
					if(search(a[i],a[x],j))
					{
						v[i]=1;
						dfs(i,sum+a[i].length()-(a[x].length()-j),cur+1);
						v[i]=0;
						break;
					}
			}
		}
}

int main()
{
	cin>>T;
	while(T--)
	{
		init();
		cout<<search(a[2],a[4],0)<<endl;
		for(int i=1;i<=n;i++)
		{
			v[i]=1;
			dfs(i,a[i].length(),1);
			v[i]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
     