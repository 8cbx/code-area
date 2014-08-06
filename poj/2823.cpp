#include<stdio.h>
#include<string.h>
int a[1000010],b[1000010],c[1000010],d[1000010],e[1000010];
int n,m;
void getmin()
{
    int head,rear,se;
    memset(b,0,sizeof(b));
    head=1;
    rear=0;
    se=0;
    int i;
    for(i=1;i<m;i++)
    {
        while(head<=rear&&a[i]<=b[rear])
        {
            rear--;
        }
        rear++;
        b[rear]=a[i];
        c[rear]=i;
    }
    for(i=m;i<=n;i++)
    {
        while(head<=rear&&a[i]<=b[rear])
        {
            rear--;
        }
        rear++;
        b[rear]=a[i];
        c[rear]=i;
        se++;
        while(c[head]<i-m+1)
        {
            head++;
        }
        d[i-m+1]=b[head];
    }
}
void getmax()
{
    int head,rear,se;
    memset(b,0,sizeof(b));
    head=1;
    rear=0;
    se=0;
    int i;
    for(i=1;i<m;i++)
    {
        while(head<=rear&&a[i]>=b[rear])
        {
            rear--;
        }
        rear++;
        b[rear]=a[i];
        c[rear]=i;
    }
    for(i=m;i<=n;i++)
    {
        while(head<=rear&&a[i]>=b[rear])
        {
            rear--;
        }
        rear++;
        b[rear]=a[i];
        c[rear]=i;
        se++;
        while(c[head]<i-m+1)
        {
            head++;
        }
        e[i-m+1]=b[head];
    }
}
void output()
{
    int i;
    for(i=1;i<=n-m+1;i++)
    {
        if(i==1)
        {
            printf("%d",d[i]);
        }
        else printf(" %d",d[i]);
    }
    printf("\n");
    for(i=1;i<=n-m+1;i++)
    {
        if(i==1)
        {
            printf("%d",e[i]);
        }
        else printf(" %d",e[i]);
    }
    printf("\n");
}
int main()
{

    int i,j,k;
    int fron,rear;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        getmin();
        getmax();
        output();
    }
    return 0;
}
