/*
直接打好表然后拆分就好了
然后OTZ不想多说啥
*/
#include <iostream>
#include <stdio.h>
using namespace std;
char str[16][150]={
"2(0)",
"2",
"2(2)",
"2(2+2(0))",
"2(2(2))",
"2(2(2)+2(0))",
"2(2(2)+2)",
"2(2(2)+2+2(0))",
"2(2(2+2(0)))",
"2(2(2+2(0))+2(0))",
"2(2(2+2(0))+2)",
"2(2(2+2(0))+2+2(0))",
"2(2(2+2(0))+2(2))",
"2(2(2+2(0))+2(2)+2(0))",
"2(2(2+2(0))+2(2)+2)"
};
int num[17]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int main()
{
    int a,i=14,j;
    scanf("%d",&a);
    for(i;i>=0;i--)
    {
        if(a>=num[i])
        {
            a-=num[i];    
                printf("%s",str[i]); 
                break;
        }   
    }
    i--;
    for(int j=i;j>=0;j--)
    {
        if(a>=num[j])
        {
            a-=num[j];    
                printf("+%s",str[j]);
        }
    }
    printf("\n");
    return 0;
}