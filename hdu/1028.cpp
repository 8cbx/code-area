#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[125][125];
    int i,j;
    int n;
    for(i=1;i<=120;i++)
    {
        a[i][0]=1;
        a[i][1]=1;
        a[0][i]=1;
        a[1][i]=1;
    }
    for(i=2;i<=120;i++)
    {
        for(j=2;j<=120;j++)
        {
            if(i>=j)
            {
                a[i][j]=a[i-j][j]+a[i][j-1];
            }
            else a[i][j]=a[i][i];
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",a[n][n]);
    }
    return 0;
}
