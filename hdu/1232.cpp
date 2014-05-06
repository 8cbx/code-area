#include<stdio.h>
#include<string.h>
int father[1010];
int findd(int a)
{
    if(father[a]==0)
    {
        return a;
    }
    return father[a]=findd(father[a]);
}
int main()
{
    int a,b;
    int fa,fb,sum;
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        if(n==0)
        {
            return 0;
        }
        scanf("%d",&m);
       memset(father,0,sizeof(father));
        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            fa=findd(a);
            fb=findd(b);
            if(fa!=fb)
            {
                father[fa]=fb;
            }
        }
        for(i=1; i<=n; i++)
        {
            if(father[i]==0)
            {
                sum++;
            }
        }
        printf("%d\n",sum-1);
    }
    return 0;
}
