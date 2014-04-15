#include<stdio.h>
#include<string.h>
#include<math.h>
int a[1000010];
int main()
{
    int n;
    int temp,ans,i,j,cnt=0;
    memset(a,0,sizeof(a));
    cnt=1;
    for(i=2; i<=1000000; i++)
    {
        if(a[i]==0)
        {
            a[i]=cnt;
            for(j=i+i;j<=1000000;j+=i)
            {
                a[j]=a[i];
            }
            cnt++;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
