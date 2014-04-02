#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[100010];
int n,m,x,y,z;
void in(int a,int b,int c)
{
    int nowcolor=0,now=0;
    if(num[a]!=0)now=a;
    if(num[b]!=0)now=b;
    if(num[c]!=0)now=c;
    nowcolor=num[a]+num[b]+num[c];
    if(now==a)
    {
        for(int i=1;i<=3;i++)
        {
            if(i!=nowcolor)
            {
                num[b]=i;
                num[c]=6-i-nowcolor;
                return;
            }
        }
    }
    if(now==b)
    {
        for(int i=1;i<=3;i++)
        {
            if(i!=nowcolor)
            {
                num[a]=i;
                num[c]=6-i-nowcolor;
                return;
            }
        }
    }
    if(now==c)
    {
        for(int i=1;i<=3;i++)
        {
            if(i!=nowcolor)
            {
                num[a]=i;
                num[b]=6-i-nowcolor;
                return;
            }
        }
    }
    num[a]=1;
    num[b]=2;
    num[c]=3;

}
int main()
{
    int a;
    int i,j;
    scanf("%d%d",&n,&m);
    memset(num,0,sizeof(num));
    scanf("%d%d%d",&x,&y,&z);
    num[x]=1;
    num[y]=2;
    num[z]=3;
    for(i=2;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        in(x,y,z);
    }
    for(i=1;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("%d\n",num[n]);
}
