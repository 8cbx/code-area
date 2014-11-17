#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[3500];
    int b[3500],c[3500],d[3500];
    int n,i,j;
    //freopen("1.txt","r",stdin);
    int ans,temp;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
         memset(d,0,sizeof(d));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            if(a[i]!=b[i])
            {
                for(j=i;j<=n;j++)
                {
                    if(a[i]==b[j])
                    {
                        temp=b[j];
                        b[j]=b[i];
                        b[i]=temp;
                        ans++;
                        //printf("%d\n",ans);
                        c[ans]=i-1;
                        d[ans]=j-1;
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
        if(ans==0)
        {
            continue;
        }
        for(i=1;i<=ans;i++)
        {
            printf("%d %d\n",c[i],d[i]);
        }
    }
    return 0;
}
