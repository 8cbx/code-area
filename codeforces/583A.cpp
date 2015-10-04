#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],b[100];
    int n;
    int ans[100];
    int ansnum=1;
    int aa,bb;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++)
    {
        scanf("%d%d",&aa,&bb);
        if(a[aa]==0&&b[bb]==0)
        {
            a[aa]=1;
            b[bb]=1;
            ans[ansnum]=i;
            ansnum++;
        }
    }
    for(int i=1;i<ansnum;i++)
    {
        if(i!=1)
        {
            printf(" %d",ans[i]);
        }
        else
        {
            printf("%d",ans[i]);
        }
    }
    printf("\n");
    return 0;
}
