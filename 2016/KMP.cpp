#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1000005;
char a[MAXN],b[MAXN];
int f[MAXN];
int n,m;

void init()
{
	gets(a);	gets(b);
	n=strlen(a);	m=strlen(b);
}

void getfail()
{
	f[0]=f[1]=0;
	for(int i=1;i<m;i++)
	{
		int j=f[i];
		while(j&&b[i]!=b[j])
			j=f[j];
		f[i+1]=b[i]==b[j]?j+1:0;
	}
}

void KMP()
{
	getfail();
	int j=0;
	for(int i=0;i<n;i++)
	{
		while(j&&a[i]!=b[j])	j=f[j];
		if(b[j]==a[i])	j++;
		if(j==m)
			printf("%d\n",i-m+1);
	}
}

int main()
{
	init();
	KMP();
}
     