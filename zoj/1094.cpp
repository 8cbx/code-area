#include<stdio.h>
#include<string.h>
struct data
{
    char s[2];
    int n,m;
    int times;
}matrix[30];
int nn[256],mm[256];
char s[500];
int p,error;
data expr()
{
    data t;
    if(s[p]=='(')
    {
        data t1,t2;
        p++;
        t1=expr();
        t2=expr();
        p++;
        if(t1.m!=t2.n)
        {
            error=1;
        }
        t.n=t1.n;
        t.m=t2.m;
        t.times=t1.times+t2.times+t1.n*t1.m*t2.m;
    }
    else
    {
        t.n=nn[(int)s[p]];
        t.m=mm[(int)s[p]];
        t.times=0;
        p++;
    }
    return t;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",matrix[i].s);
        scanf("%d%d",&matrix[i].n,&matrix[i].m);
        nn[(int)matrix[i].s[0]]=matrix[i].n;
        mm[(int)matrix[i].s[0]]=matrix[i].m;
    }
    while(scanf("%s",s)!=EOF)
    {
        p=0;
        error=0;
        data t=expr();
        if(error)
        {
            printf("error\n");
        }
        else printf("%d\n",t.times);
    }
    return 0;
}
