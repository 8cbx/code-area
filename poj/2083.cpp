#include<stdio.h>
#include<string.h>
#include<math.h>
int a[8][800][800];
int level(int n)
{
    int i,s;
    for(i=0,s=1; i<n; i++)
        s *= 3;
    return s;
}
void print(int t,int n,int x,int y)
{
    if(n==1)
    {
        a[t][x][y]=1;
        return;
    }
    else
    {
        int m=level(n-2);
        print(t,n-1,x,y);
        print(t,n-1,x,y+2*m);
        print(t,n-1,x+m,y+m);
        print(t,n-1,x+2*m,y);
        print(t,n-1,x+2*m,y+2*m);
    }
    return;
}
int main()
{
    int x,y;
    int n,i,j;
    memset(a,0,sizeof(a));
    for(i=1; i<=7; i++)
    {
        print(i,i,0,0);
    }
    int m;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
        {
            break;
        }
        m=level(n-1);
        for(i=0; i<m; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[n][i][j]==1)
                {
                    printf("X");
                }
                else printf(" ");
            }
            printf("\n");
        }
        printf("-\n");
    }
    return 0;
}
