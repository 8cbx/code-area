//写麻烦了，其实没几个水仙花数
#include<stdio.h>
#include<string.h>
int main()
{
    int shui[250];
    int i,n,m,num,a,b,c,flag;
    num=1;
    for(i=100;i<=999;i++)
    {
        a=i/100;
        b=i/10%10;
        c=i%10;
        //printf("%d %d %d\n",a,b,c);
        if(a*a*a+b*b*b+c*c*c==i)
        {
            shui[num]=i;
            num++;
            //printf("%d %d %d\n",num,i,shui[num]);
        }
    }
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        flag=0;
        for(i=1;i<num;i++)
        {
            if(shui[i]<=m&&shui[i]>=n)
            {
                if(flag==1)
                {
                    printf(" ");
                }
                printf("%d",shui[i]);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
