/*
一道暗含玄机的0/1背包OTZ
我们知道朴素的0/1应该是每个物品有选或不选两种决策
而这道题正好对应着每个物品有翻转和不翻转两种决策
并且具有动态规划的前提条件
所以我们可以用背包来做
这也是一种隐含0/1的思路了
物品的体积可以看作是上面拉面的减去下面的，我们一直将上下的差看作背包问题的物品体积，
而每个物品都可一翻转，每一次翻转分数就要加上1，但是翻转两次相当于没有翻转，
所以每一个最多翻转一次
设f[i][j]为处理到i物品时	要得到j的差值的最小操作次数
那么状态转移方程就很好写了
f[i,j]:=min{f[i-1,j-w[i,1]],f[i-1,j-w[i,2]]+1} (1<=i<=n,-sum<=j<=sum)
sum就是所以一对数中的更大值之和
w[i,1]表示不翻动第i个物品的差值，w[i,2]表示翻动第i个物品的差值
通过简单分析可以知道abs(sum)<=5000,因为上限最大为6，下限最小为1，
那么如果按照常规的思考方式我们需要建立一个 1000*10000的二维数组。这是无法办到的。
但是我们可以很明显地看到每一个阶段的所有状态总是在它们前一个阶段的状态通过决策得到的，
不会来自于更以前的阶段。那么我们是不是只需要通过建立一个2*10000的数组来求解呢？ 
f[0,j]用来表示前一个阶段的状态数组，f[1,j]表示当前阶段的状态数组,
到下一阶段时又将当前阶段的状态数组作为前一个阶段的状态值，
那么前一个阶段的状态数组就不需要了， 又可以用它来作为当前阶段的状态数组，
这样来回地滚动不是达到了1000*10000的一样的效果吗？ 
从而大量节省了浪费掉的空间，完美地解决了这个问题。这也就是我们所说的滚动数组。
然后我们考虑到这个f[][]的第二维需要有满足负数的情况
但是我们知道下标是不能用负数的
所以我们对于所有的第二维下表全部加上一个MAXV
这样负数变成了正的	原先是正的也变成了一个更高层的区域内的数
避免了冲突
寻找答案时按照0--sum来找
每次要找到正负因为我们是要绝对值最小
然后随便乱搞就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
const int MAXV=80006;
const int INF=0x7ffffff;
int f[2][MAXV*2+2];
int n;
int p;
int sum;

void init()
{
	int x,y;
	cin>>n;
	for(int i=(-n*6);i<=(n*6);i++)
		f[0][i+MAXV]=f[1][i+MAXV]=INF;
}

int main()
{
	int x,y;
	int i;
	init();
	f[0][0+MAXV]=0;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		int w=x-y;
		sum+=max(x,y);
		for(int j=-sum;j<=sum;j++)
			f[i%2][j+MAXV]=min(f[(i-1)%2][(j-w)+MAXV],f[(i-1)%2][(j+w)+MAXV]+1);		
	}
	for(int j=0;j<=sum;j++)
		if(f[(i-1)%2][j+MAXV]!=INF||f[(i-1)%2][-j+MAXV]!=INF)
		{
			cout<<min(f[(i-1)%2][j+MAXV],f[(i-1)%2][-j+MAXV])<<endl;
			return 0;
		}
}
     