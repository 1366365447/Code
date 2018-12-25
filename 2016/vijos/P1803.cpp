/*
劲啊  一道人品辣么高的题
吓得我差点有点不敢做
然后看了下题目发现好像要用线段树？
诶不对数据范围这么小  直接模拟不就好了？
好像可以模拟的OTZ?
然后就开始狂模拟了
结果这就是一道水题   只是好像提交人数太少了2333
因为是两边发射所以我们要左右各扫一遍
注意两个端点处是有一边无法扫的
我们用一个d[]来记录一个合适的高度位置
然后初值d[k=1]=1
然后第一遍是判断向左发射的
所以第一个点不能算上
因为每次是碰到最近的射
所以如果当前的h[i]会比最近的这个d[k]即当前最近的d[k]更小
那么是不能接收的同时他要发射给别人
加入到d[]中
如果发现一个比当前d[k]更高的
那么它至少可以接受当前d[k]对应位置的塔的信号
而且也有可能接受上一个d[k]的信号
所以说用一个while循环来判断接受
前提是d[]数组还有数(未匹配的还有)并且这个目前尝试配对的d[k]塔
他的高度要比当前想接受的这个塔的高度低
否则是不能接受的
即一个塔只能接受比自己矮且中间没有高度在两者之间的塔
所以这样的方法是可行的
然后另一种推也是一样的道理了
最后取所有的最大值
这里要提到的是 可能一开始会想不通为什么可以每次只判断一个d[k]不会漏了情况？
我们知道如果当前判断的塔的高度会小于d[k]
那么如果d[k]前面有可以配对的塔
肯定已经被这个d[k]配对掉了
所以想都不用想
即我们可以得出这个结论
d[]对应的塔的塔高一定是单调递增(或递减的)的
不然一定可以发生配对
同时我们的while循环配对掉了塔之后还要将这个i塔加入这个d[]数组中
因为它还有可能被别的塔匹配
而被它匹配了的塔就已经没办法再匹配别的塔了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50002;
int h[MAXN],v[MAXN],c[MAXN],d[MAXN];
int n,ans,k;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i]>>v[i];
    d[k=1]=1;
    for(int i=2;i<=n;i++)
    {
        if(h[i]<=h[d[k]])
            d[++k]=i;
        else
        {
            while(k!=0&&h[d[k]]<h[i])
                c[i]+=v[d[k--]];
            d[++k]=i;
        }
    }
    d[k=1]=n;
    for(int i=n-1;i>=1;i--)
    {
        if(h[i]<=h[d[k]])
            d[++k]=i;
        else
        {
            while(k!=0&&h[d[k]]<h[i])
                c[i]+=v[d[k--]];
            d[++k]=i;
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,c[i]);
    cout<<ans<<endl;
    return 0;
}
     