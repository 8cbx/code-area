#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct data
{
    int id,no;
}v[15];
int maz[15][15];
int cmp(data a,data b)
{
    return a.no>b.no;
}
int main()
{
    int t;
    int n;
    int ok;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ok=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[i].no);
            v[i].id=i;
        }
        memset(maz,0,sizeof(maz));
        sort(v+1,v+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            if(v[i].no<0)
            {
                ok=1;
            }
            else
            {
                for(int j=1;j<=v[i].no;j++)
                {
                    maz[v[i].id][v[i+j].id]=1;
                    maz[v[i+j].id][v[i].id]=1;
                    v[i+j].no--;
                }
            }
            sort(v+i+1,v+n+1,cmp);
        }
        if(ok==1)
        {
            printf("NO\n");
            if(t!=0)
            {
                printf("\n");
            }
        }
        else
        {
            printf("YES\n");
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    printf("%d",maz[i][j]);
                    if(j!=n)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            if(t!=0)
            {
                printf("\n");
            }
        }
    }
    return 0;
}
