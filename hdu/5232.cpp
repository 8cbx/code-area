#include<stdio.h>
#include<string.h>
int main()
{
    int a[35][35];
    int n;
    int cnt;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt+n*2);
    }
    return 0;
}
