#include<stdio.h>
#include<string.h>
int father[21];
int used[21];
int finda(int a)
{
    int fa;
    if(a==father[a])
    {
        return a;
    }
    fa=a;
    while(fa!=father[fa])
    {
        fa=father[fa];
    }
    return fa;
}
int main()
{
    int a,b,tree,cas,fa,fb,now,maxx;
    tree=0;
    maxx=0;
    cas=0;
    memset(used,0,sizeof(used));
    for(int i=1; i<=20; i++)
    {
        father[i]=i;
    }
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a<0||b<0)
        {
            break;
        }
        if(a==0&&b==0)
        {
            now=0;
            cas++;
            for(int i=1; i<=maxx; i++)
            {
                //printf("%d %d\n",father[i],i);
                if(father[i]==i&&used[i]==1)
                {
                    now++;
                }
            }
            if(now!=1&&maxx!=0)
            {
                tree=1;
            }
            if(tree==0)
            {
                printf("Case %d is a tree.\n",cas);
            }
            else printf("Case %d is not a tree.\n",cas);
            tree=0;
            maxx=0;
            for(int i=1; i<=20; i++)
            {
                father[i]=i;
            }
            memset(used,0,sizeof(used));
            continue;
        }
        used[a]=1;
        used[b]=1;
        if(a>maxx)
        {
            maxx=a;
        }
        if(b>maxx)
        {
            maxx=b;
        }
        if(tree==0)
        {
            fa=finda(a);
            fb=finda(b);
            if(fb==b&&a!=b)
            {
                father[fb]=a;
            }
            else
            {
                tree=1;
            }
        }
        //printf("%d\n",tree);
    }
    return 0;
}
