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

const int MAXN=1005;
struct Job
{
	int j,b;
	bool operator <(const Job& x)const
	{
		return j>x.j;
	}
}a[MAXN];
int Case;
int n;

void init()
{
	for(int i=1;i<=n;i++)
	{
		read(a[i].b);	read(a[i].j);
	}
	sort(a+1,a+n+1);
}

void work()
{
	int now=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		now+=a[i].b;
		ans=max(ans,now+a[i].j);
	}
	printf("Case %d: %d\n",++Case,ans);
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		init();
		work();
	}
	return 0;
}
     