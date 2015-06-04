#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    int l,r,x;
    int c[16];
    int wei[16];
    int num=0;
    scanf("%d%d%d%d",&n,&l,&r,&x);
    int now=1<<n;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&c[i]);
    }
    while(now>0)
    {
        int i=0;
        int tmp=now;
        memset(wei,0,sizeof(wei));
        while(tmp>0)
        {
            wei[i]=tmp%2;
            tmp/=2;
            i++;
        }
        int ans=0;
        int min=9999999;
        int max=0;
        int coun=0;
        for(i=0; i<n; i++)
        {
            if(wei[i]==1)
            {

                ans+=c[i];
                if(c[i]>max)
                {
                    max=c[i];
                }
                if(c[i]<min)
                {
                    min=c[i];
                }
                coun++;
            }
        }
        if(coun>=2&&(max-min>=x)&&l<=ans&&r>=ans)
        {
            num++;
        }
        //printf("\n");
        now--;
    }
    printf("%d\n",num);
    return 0;
}
