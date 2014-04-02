#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) a>b?a:b
int main()
{
    int num[150];
    double p[150],tot[10010];
    int t,n,i,j;
    double maxx;
    int maxm;
    scanf("%d",&t);
    while(t--)
    {
        maxm=0;
        scanf("%lf%d",&maxx,&n);
        maxx=1-maxx;
        for(i=1;i<=n;i++)
        {
            scanf("%d%lf",&num[i],&p[i]);
            p[i]=1-p[i];
            maxm+=num[i];
        }
        //printf("++\n");
        memset(tot,0,sizeof(tot));
        tot[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=maxm;j>=num[i];j--)
            {
                tot[j]=max(tot[j],tot[j-num[i]]*p[i]);
                //printf("++\n");
            }
        }
        /*for(i=1;i<=maxm;i++)
        {
            printf("%lf\n",tot[i]);
        }*/
        for(i=maxm;i>=0;i--)
        {
            if(tot[i]>maxx)
            {printf("%d\n",i);
            break;}
        }
    }
    return 0;
}
