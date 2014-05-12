#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,p,l,temp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n>m)
        {
            temp=n;
            n=m;
            m=temp;
        }
        p=0;
        l=0;
        for(i=n;i<=m;i++)
        {
            if(i%2==0)
            {
                p+=i*i;
            }
            else l+=i*i*i;
        }
        printf("%d %d\n",p,l);
    }
    return 0;
}
