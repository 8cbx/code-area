#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
stack<int> stac;
struct data
{
    char op[5];
    int k;
    int color;
}op[510];
int main()
{
    int a[110][110];
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        while(!stac.empty())
        {
            stac.pop();
        }
        memset(a,0,sizeof(a));
        memset(op,0,sizeof(op));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%s%d%d",op[i].op,&op[i].k,&op[i].color);
        }
        int con=0;
        while(con<m)
        {
            for(int i=1;i<=m;i++)
            {
                if(op[i].k!=0)
                {
                    if(op[i].op[0]=='L')
                    {
                        int j;
                        for(j=1;j<=n;j++)
                        {
                            if(a[j][op[i].k]!=0&&a[j][op[i].k]!=op[i].color)
                            {
                                break;
                            }
                        }
                        if(j>n)
                        {
                            stac.push(i);
                            for(int j=1;j<=n;j++)
                            {
                                a[j][op[i].k]=0;
                            }
                            op[i].k=0;
                        }
                    }
                    else
                    {
                        int j;
                        for(j=1;j<=n;j++)
                        {
                            if(a[op[i].k][j]!=0&&a[op[i].k][j]!=op[i].color)
                            {
                                break;
                            }
                        }
                        if(j>n)
                        {
                            stac.push(i);
                            for(int j=1;j<=n;j++)
                            {
                                a[op[i].k][j]=0;
                            }
                            op[i].k=0;
                        }
                    }
                }
            }
            con++;
        }
        while(!stac.empty())
        {
            printf("%d ",stac.top());
            stac.pop();
        }
        printf("\n");
    }
    return 0;
}
