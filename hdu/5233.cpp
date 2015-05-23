#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
struct ip
{
    int a,b,c,d;
    bool operator <(const ip& other) const
    {
        if (a < other.a)
        {
            return true;
        }
        else if (a == other.a)
        {
            if (b < other.b)
            {
                return true;
            }
            else if(b==other.b)
            {
                if (c < other.c)
                {
                    return true;
                }
                else if(c==other.c)
                {
                    if (d < other.d)
                    {
                        return true;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        return false;
    }
};
map<ip,int> mapp;
int cmp(ip a,ip b)
{
    if(a.a==b.a&&a.b==b.b&&a.c==b.c&&a.d==b.d)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    ip s[1010],ss[1010];
    ip sss;
    int t;
    int cases;
    int n,m;
    while(scanf("%d",&t)!=EOF)
    {
        cases=0;
        while(t--)
        {
            cases++;
            printf("Case #%d:\n",cases);
            scanf("%d%d",&n,&m);
            for(int i=1; i<=n; i++)
            {
                scanf("%d.%d.%d.%d",&s[i].a,&s[i].b,&s[i].c,&s[i].d);
            }
            for(int i=1; i<=m; i++)
            {
                scanf("%d.%d.%d.%d",&sss.a,&sss.b,&sss.c,&sss.d);
                mapp.clear();
                for(int j=1; j<=n; j++)
                {
                    ss[j].a=s[j].a&sss.a;
                    ss[j].b=s[j].b&sss.b;
                    ss[j].c=s[j].c&sss.c;
                    ss[j].d=s[j].d&sss.d;
                    mapp[ss[j]]=1;
                }
                printf("%d\n",(int)mapp.size());
            }
        }
    }
    return 0;
}
