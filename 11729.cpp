#include<stdio.h>
#include<stdlib.h>
int main()
{
    int jj[1010];
    int b[1010];
    int i,j,k;
    int n,temp;
    int cases=1;
    int time,now;
    while(scanf("%d",&n)!=EOF)
    {
        time=0;
        now=0;
        if(n==0)break;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&b[i],&jj[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(jj[i]<jj[j])
                {
                    temp=jj[i];
                    jj[i]=jj[j];
                    jj[j]=temp;
                    temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            time+=b[i];
            if(time+jj[i]>now)
            {
                now=jj[i]+time;
            }
        }
        printf("Case %d: %d\n",cases,now);
        cases++;
    }
    return 0;
}
