#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    int m;
    int t;
    int cases=1;
    scanf("%d",&t);
    while(t)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
        {
            t--;
            cases=1;
            if(t)
            {
                printf("\n");
            }
            continue;
        }
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((i*i+j*j+m)%(i*j)==0)
                {
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n",cases++,cnt);
    }
    return 0;
}
