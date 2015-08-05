#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[5000000];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        int head=0,tail=0,op,x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&x);
                a[tail]=x;
                tail++;
                int tmp=tail-1;
                int temp;
                //printf("--%d %d %d %d\n",head,tail,a[tmp],a[tmp-1]);
                while(tmp>head&&a[tmp]>a[tmp-1])
                {
                    temp=a[tmp];
                    a[tmp]=a[tmp-1];
                    a[tmp-1]=temp;
                    tmp--;
                    //printf("%d\n",tmp);
                }
                /*for(int j=head;j<=tail;j++)
                {
                    printf("---%d\n",a[j]);
                }*/
            }
            if(op==2)
            {
                if(tail>head)
                    tail--;
            }
            if(op==3)
            {
                if(head!=tail)
                    printf("%d\n",a[head]);
                else
                {
                    printf("0\n");
                }
            }
        }
    }
    return 0;
}
