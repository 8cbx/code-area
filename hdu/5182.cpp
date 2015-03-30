#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct data2
{
    int a,b,cha,id;
}data[1000];
int cmp(data2 x,data2 y)
{
    if(x.cha==y.cha)
    {
        if(x.b==y.b)
        {
            return x.id<y.id;
        }
        else return x.b<y.b;
    }
    return x.cha>y.cha;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&data[i].a,&data[i].b);
            data[i].id=i;
            data[i].cha=data[i].a-data[i].b;
        }
        sort(data,data+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",data[i].id);
        }
        printf("\n");
    }

    return 0;
}
