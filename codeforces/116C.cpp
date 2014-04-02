#include<stdio.h>
#include<string.h>
int b[2100],c[2000100];
int main()
{
    int a[2000100];
    int i,j,k,f,r;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,-1,sizeof(b));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            c[i]=i;
            if(a[i]==-1)b[i]=1;
        }
        f=1;
        r=n+1;
        while(f<r)
        {
            if(a[f]!=-1)
            {
                //printf("%d--%d--%d--%d\n",f,r,a[f],b[a[f]]);
                if(b[a[f]]==-1)
                {
                    a[r]=a[f];
                    c[r]=c[f];
                    r++;
                    f++;
                }
                else
                {
                    b[c[f]]=b[a[f]]+1;
                    f++;
                }
            }
            else
            {
                f++;
            }
        }
        k=0;
        for(i=1; i<=n; i++)
        {
            if(k<b[i])
                k=b[i];
            //printf("--%d\n",b[i]);
        }
        printf("%d\n",k);
    }
    return 0;
}
