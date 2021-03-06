/*
不多说我先吐槽一下这个数据有多弱
我们看下面这个程序
int n;
int num[1000010];
int main()
{
scanf("%d",&n);
for(int i = 1 ; i <= n ; i ++)
scanf("%d",&num[i]);
sort(num+1,num+n+1);
int ans = 1;
for(int i = 1 ; i < n ; i ++)
if(num[i] + n >= num[n] + 1)
ans ++;
printf("%d\n",ans);
return 0;
}
结果是他AC了
我心中阴影面积INF?
我靠这连样例都过不了啊，很明显的一个错误的算法
根本不可以只判断每个a[i]和a[n]的极值关系
比如说我们看这组样例
5
15
14
15
12
14
最小值是是几？ 不是5 是4
因为虽然12+4>15+1
但是我们可以看到，因为排名是保证没有相同的，所以有两个15
一个是1，另一个一定最小就是2了
那么这就非常尴尬了	这数据我给满分啊
看看标解吧
对于第i位选手来说，如果想要夺冠，最好的情况一定是他在下一场夺冠，且其余人按照原有排名的逆序从依次为第二名到第n名。
如果先对所有人排序，这样做的时间复杂度是O(n^2)的，可以得到60分。
再考虑上述过程，可以发现对于从小到大排序后第i位选手和第i+1位选手来说，最优方案下其余人下一场的得分都是一样的，
所以只需要顺序处理好两邻选手的情况即可。
实在有趣
比赛的时候想到这一步了	但是就差一点点	还是没能AK
唉真悲伤现在一想很简单啊
先从小到大排序
对于每一个a[i](a[n]除外)，我们先判断一下他和a[n]的关系咯
怎么说最优肯定是a[i]第一名a[n]最后一名
判断是否可行
然后我们并不需要每个人和除他外所有人比一次
我们就直接拿这个人和他后面那个人一比就好了
因为他后面的人一定不可能会追上他
但是后面那个人就有可能因为加的有点多超过他
a[i]+n>=a[i+1]+(n-i+1)
怎么理解呢
按照标解的意思理解一下就好了
最好的情况一定是他在下一场夺冠，且其余人按照原有排名的逆序从依次为第二名到第n名
就是越大排名的越后越好
所以a[i+1]的名次最好的情况一定是第i+1名
所以可以得n-i+1分
然后判断一下就好了
挺考验逻辑思维的一道题目的
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int maxn=300010;
int n;
int ans;
int a[maxn];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
		if(a[i]+n>=a[n]+1&&a[i]+n>=a[i+1]+(n-i+1))
			ans++;
	ans++;
	cout<<ans<<endl;
	return 0;
}
