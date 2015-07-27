#include<stdio.h>
#include<string.h>
#define maxn 1010
int main()
{
    int n,p[maxn];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        int x,max=0;
        while(scanf("%d",&x)!=EOF)
        {
            if(x==0)
            {
                break;
            }
            memset(p,0,sizeof(p));
            bool vaild=true;
            for(int i=1; i<=n; i++)
            {
                if(vaild)
                {
                    bool ok=true;
                    for(int i=x+1; i<=max; i++)
                    {
                        if(p[i]==1)
                        {
                            ok=false;
                            break;
                        }
                    }
                    if(!ok)
                    {
                        vaild=false;
                    }
                    else
                    {
                        max=(max>x?max:x);
                        p[x]=2;
                        for(int i=x-1; i>0&&!p[i]; i--)
                        {
                            p[i]=1;
                        }
                    }
                }
                if(i<n)
                {
                    scanf("%d",&x);
                }
            }
            printf("%s\n",vaild?"Yes":"No");
        }
        printf("\n");
    }
    return 0;
}
