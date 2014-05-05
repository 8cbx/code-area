#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c,d,e,f,t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
            c+=f;
            while(c>=60)
            {
                b+=c/60;
                c%=60;
            }
            b+=e;
            while(b>=60)
            {
                a+=b/60;
                b%=60;
            }
            a+=d;
            printf("%d %d %d\n",a,b,c);
        }
    }
    return 0;
}
