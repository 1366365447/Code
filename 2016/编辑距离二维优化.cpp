#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;
string a,b;
int f[1000];

int Min(int a,int b,int c)
{
	return min(min(a,b),c);
}

int main()
{
	cin>>a>>b;
	int c1=a.length();
	int c2=b.length();
	f[0]=0;
	for(int j=1;j<=c2;j++)
		f[j]=j;
	for(int i=1;i<=c1;i++)
	{
		int last=f[0];
			f[0]=i;
			for(int j=1;j<=c2;j++)
			{
			int temp=f[j];
			if(a[i-1]==b[j-1])
				f[j]=Min(last,temp+1,f[j-1]+1);
			else
				f[j]=Min(last+1,temp+1,f[j-1]+1);
			last=temp;
			}
	}
	cout<<f[c2];
	return 0;
}