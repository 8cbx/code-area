#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m;
    int a[110];
    int i,j;
    int k;
    int temp;
    int x,y;
    a[0]=0;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&temp);
        a[i]=temp+a[i-1];
    }
    scanf("%d%d",&x,&y);
    for(i=2;i<=m;i++)
    {
        if((a[i-1]>=x&&a[i-1]<=y)&&(a[m]-a[i-1]>=x&&a[m]-a[i-1]<=y))
        {printf("%d\n",i);
        return 0;}
    }
    printf("0\n");
    return 0;
}
