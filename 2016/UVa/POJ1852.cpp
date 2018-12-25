#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

const int MAXN=1000005;
int a[MAXN];
int n;
int L;

void init()
{
	read(n);	read(L);
	for(int i=1;i<=n;i++)
		read(a[i]);
}

void work()
{
	int maxt=0,mint=0;
	for(int i=1;i<=n;i++)
	{
		maxt=max(maxt,max(a[i],L-a[i]));
		mint=max(mint,min(a[i],L-a[i]));
	}
	out(mint,0);	out(maxt);
}

int main()
{
	init();
	work();
	return 0;
}
     