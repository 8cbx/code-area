#include<stdio.h>
#include<string.h>
int has[50010];
int pos[50010];
int a[50010];
int main()
{
    int n;
    long long sum=0;
    memset(has,0,sizeof(has));
    memset(pos,0,sizeof(pos));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(sum%n==0)
        {
            printf("%d\n",i+1);
            for(int j=0; j<=i; j++)
            {
                printf("%d\n",a[j]);
            }
            break;
        }
        else if(has[sum%n]==1)
        {
            printf("%d\n",i-pos[sum%n]);
            for(int j=pos[sum%n]+1;j<=i;j++)
            {
                printf("%d\n",a[j]);
            }
            break;
        }
        pos[sum%n]=i;
        has[sum%n]=1;
    }
    return 0;
}
