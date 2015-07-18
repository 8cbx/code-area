#include<stdio.h>
#include<string.h>
int main()
{
    long long a;
    int w[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(w,0,sizeof(w));
        scanf("%I64d",&a);
        long long todo=a;
        int ans=0;
        if(a==0)
        {
            printf("0\n");
            continue;
        }
        int i=0;
        while(todo>0)
        {
            if(todo%2==1)
            {
                w[i]=1;
            }
            else
            {
                w[i]=0;
            }
            todo/=2;
            i++;
        }
        for(int j=0;j<i;j++)
        {
            if(j==0)
            {
                if(w[j]==1)
                {
                    ans++;
                }
            }
            else if(w[j]==1&&w[j-1]==0)
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
