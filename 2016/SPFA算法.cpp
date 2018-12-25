#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF=0x7ffff;
int a[100][100];
bool inque[100];
int d[100];
queue<int> q;
int n,e;

void SPFA(int s)//源点就是这么6
{
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[s]=0;
	q.push(s);
	inque[s]=true;
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		inque[x]=false;
		
		for(int i=1;i<=n;i++)
			if(d[x]+a[x][i]<d[i]) 
			{
				d[i]=d[x]+a[x][i];
				if(!inque[i])
					q.push(i),inque[i]=true;
			}
	}
	
	for(int i=1;i<=n;i++)
	cout<<d[i]<<" ";
}

int main()
{
	memset(inque,false,sizeof(inque));
	cin>>n>>e;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		a[i][j]=INF;//初始化INF
	for(int i=1;i<=e;i++)
	{
		int x,y,v;
		cin>>x>>y>>v;
		a[x][y]=v;
	}
	SPFA(1);
	return 0;
}