#include<stdio.h>
#include<string.h>
int main()
{
    int old[120];
    int n,i,temp,coun;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        memset(old,0,sizeof(old));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            old[temp]++;
        }
        coun=n-1;
        for(i=1;i<=100;i++)
        {
            while(old[i]!=0&&coun!=0)
            {
                printf("%d ",i);
                old[i]--;
                coun--;
            }
        }
        for(i=1;i<=100;i++)
        {
            while(old[i]!=0)
            {
                printf("%d",i);
                old[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}
