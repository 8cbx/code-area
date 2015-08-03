#include<stdio.h>
#include<string.h>
int a[110][131180];
int b[131180][110];
int main()
{
    for(int i=2;i<=131172;i++)
    {
        scanf("%d",&a[1][i]);
    }
    for(int i=2;i<=131172;i++)
    {
        scanf("%d",&b[i][1]);
    }
    for(int i=2;i<=100;i++)
    {
        for(int j=1;j<=131172;j++)
        {
            if(j==1)
            {
                a[i][j]=b[i][1];
            }
            else a[i][j]=a[i-1][j]^a[i][j-1];
        }
    }
    for(int i=1;i<=131172;i++)
    {
        for(int j=2;j<=100;j++)
        {
            if(i==1)
            {
                b[i][j]=a[i][j];
            }
            else b[i][j]=b[i-1][j]^b[i][j-1];
        }
    }
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",a[x][131072+y]^b[131072+x][y]);
        //printf("%d\n",aa[x][131072+y]^bb[131072+x][y]);
    }
    return 0;
}
