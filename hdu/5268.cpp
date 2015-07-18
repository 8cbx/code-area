#include<string.h>
#include<stdio.h>
int main()
{
    int a,b;
    int num[5]={0,1000,1500,2000,2500};
    int t;
    scanf("%d",&t);
    int cases=0;
    while(t--)
    {
        cases++;
        int ans=0;
        for(int i=1;i<=4;i++)
        {
            scanf("%d%d",&a,&b);
            int tmp=num[i]/250*(250-a);
            tmp=tmp-(50*b);
            if(tmp<num[i]/100*40)
            {
                tmp=num[i]/100*40;
            }
            ans+=tmp;
        }
        printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
