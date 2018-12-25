#include<cstdio>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  

 
int n,ans=0,k;  
int a[1000],b[1000];  
int f[1000+10]={0};//f[i]��ʾ��i��������·  
int g[1000+10]={0};//g[i]��ʾ��i����������·  
int map[1000+10][1000+10]={0}; //�ж�2�������Ƿ���ڿ���Ƕ�Ĺ�ϵ������ͼ��   


int dp(int i)  
{  
    if(f[i])return f[i];//���仯����  
    //�����ǰ����ѷ��ʹ�ֱ�ӷ���  
       
    f[i]=1;//δ���ԣ�����ֵ  
       
    for(int j=1;j<=n;j++)  
    {  
        if(map[i][j])f[i]=max(f[i],dp(j)+1);  
        //״̬ת�Ʒ���   
    }  
    return f[i];  
}  
  
void print(int i)//�����i��ʼ   
{  
    cout<<i<<' ';  
      
    for(int j=1;j<=n;j++)  
       if(map[i][j]&&f[i]==f[j]+1)//���i��Ƕ����j�ڣ����i����ľ���   
       {  
           print(j);   
           break;  
       }  
}  

int main()  
{  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d%d",&a[i],&b[i]);  
    }  
    for(int i=1;i<=n;i++)  
       for(int j=1;j<=n;j++)  
       {  
           if((a[i]<a[j]&&b[i]<b[j])||(a[i]<b[j]&&b[i]<a[j]))map[i][j]=1;  
       }//�ж�ͼ�Ƿ���ڣ��Ƿ������Ƕ   
      
    for(int i=1;i<=n;i++)f[i]=dp(i);  
    //����ÿ��������Ƕ  
       
      
    for(int i=1;i<=n;i++)if(ans<f[i])ans=f[k=i];//�ҳ�����f[i]������¼����k   
    printf("%d\n",ans);  
  
    print(k);  
  
    return 0;   
      
}  
