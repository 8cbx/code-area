#include<stdio.h>
#include<string.h>
int a[10]= {1,2,4,8,16,32,64,128};
int main()
{
    int n;
    int wei[15];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        memset(wei,0,sizeof(wei));
        int tmp=n;
        int i=0;
        while(tmp>0)
        {
            wei[i]=tmp%2;
            tmp/=2;
            i++;
        }
        int ans=0;
        for(int j=0; j<=i; j++)
        {
            //printf("%d\n",wei[j]);
            if(wei[j]==1)
            {
                ans=j;
                break;
            }
        }
        printf("%d\n",a[ans]);
    }
    return 0;
}
