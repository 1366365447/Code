#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[1000][1000];


struct node
{
	int x,y,z;
};

queue<node> s;

void bfs()
{
	node q;
	node temp;
	node p={1,1,1};
	s.push(p);
	while(!s.empty())
	{
		
		q=s.front();
		s.pop();
		if(q.x==n&&q.y==m)
		break;
		for(int i=0;i<4;i++)
		{
			int r=q.x+d[i][0];
			int l=q.y+d[i][1];
			if(a[r][l])
			{
				a[r][l]=0;
				temp.x=r;
				temp.y=l;
				temp.z=q.z+1;
				s.push(temp);
			}
		}
	}
	cout<<q.z;
}

int main()
{
	cin>>n>>m;	
	char ca;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ca;
			a[i][j]=1;
			if(ca=='#') 
			a[i][j]=0;
		}
	bfs();
	return 0;
		
}