/*
Orz%%%%%lll6924
第一题都不会
看到数据范围想到了离散
但是想不到怎么离散Orz
题意简述:给定n个闭区间,求出一个数使它与包含它的区间数的积最大,输出这个积。 
20分算法：枚举所有的p，用O(n)的时间计算出包含它的区间数，时间复杂度O（n*max_p）。
40分算法1：显然p最优时一定会在区间端点上，所以只需要枚举2n个端点即可，时间复杂度O(n2)。
40分算法2：用left[i]表示i报酬上的左端点数，left[i]表示右端点数，
则用O(max_p)的时间扫一遍就可以计算出每一个p被包含的次数，再枚举所有端点即可，
时间复杂度O(max_p)。
100分算法：注意到40分算法2的瓶颈是max_p，但是只有2n个端点，因此我们对2n个端点进行离散化，
这样就可以在O(n)的时间内计算出每一个p被包含的次数，时间复杂度为O(n)。
怎么离散呢
其实意思就是我们不用管整个坐标轴
我们只要记录下两个端点就好了
然后同时要记录下他是左端点还是右端点
之后按照前后顺序将这些端点打散
全部按照升序排一下就好了
然后我们扫一遍序列	用num记录当前包含在多少个区间之内
对于碰到的点有两种情况
1.左端点	2.右端点
如果是左端点说明又进入了一个区间	先num++	再尝试更新ans
如果是右端点说明即将离开了一个区间	先尝试更新ans	再num--
然后就可以找到答案了(注意数据要开到long long)
嗯其实离散化还是题目做的少
其实挺好理解的
有些数据本身很大,自身无法作为数组的下标保存对应的属性,或者太难寻找(间隔太大)
如果这时只是需要这堆数据的相对属性， 那么可以对其进行离散化处理
即离散化的前提：当数据只与它们之间的相对大小有关，而与具体是多少无关时，可以进行离散化。
可以大大降低时间复杂度
还有一道很经典的离散化
51Nod中的贪心算法教程中一个借教室的题目
也是离散化端点
涨姿势了%%%%lll6924
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
struct node
{
	int x;
	bool k;
	bool operator <(const node &b)const
	{
		return x<b.x;
	} 
}a[MAXN<<1];
int n;
long long num,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i+n].x);
		a[i].k=1;	a[i+n].k=0;
	}
	sort(a+1,a+(n<<1)+1);
	for(int i=1;i<=(n<<1);i++)
	{
		if(a[i].k)
		{
			num++;
			ans=max(ans,a[i].x*num);
		}
		else
		{
			ans=max(ans,a[i].x*num);
			num--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     