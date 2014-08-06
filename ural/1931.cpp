#include<stdio.h>
#include<string.h>
int main()
{
    int n,a,b,tmpp,doo,todo,tmp;
    while(scanf("%d",&n)!=EOF)
    {
        a=todo=1;
        b=doo=0;
        scanf("%d",&tmpp);
        for(int i=1; i<n; i++)
        {
            scanf("%d",&tmp);
            if(tmp<tmpp)
            {
                tmpp=tmp;
                b=1;
                todo=i+1;
            }
            else
            {
                b++;
            }
            if(b>doo)
            {
                a=todo;
                doo=b;
            }
        }
        printf("%d\n",a);
    }
    return 0;
}
