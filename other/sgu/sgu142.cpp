#include<stdio.h>
#include<string.h>
char s[500005],oput[500005];
    int ss[500005],vis[500005];
    int pow[500005];
int main()
{
    int n;
    pow[0]=1;
    for(int i=1;i<=20;i++)
    {
        pow[i]=2*pow[i-1];
    }
    int h,cnt,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        memset(ss,0,sizeof(ss));
        for(i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                ss[i+1]=1;
            }
            else ss[i+1]=0;
        }
        for(i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            h=0;
            cnt=0;
            for(j=1;j<=i;j++)
            {
                h=h*2+ss[j];
            }
            vis[h]=1;
            cnt++;
            for(;j<=n;j++)
            {
                h=h*2+ss[j];
                h%=pow[i];
                if(vis[h]==0)
                {
                    vis[h]=1;
                    cnt++;
                }
            }
            if(cnt!=pow[i])
            {
                break;
            }
        }
        for(j=0;j<pow[i];j++)
        {
            if(vis[j]==0)
            {
                break;
            }
        }
        printf("%d\n",i);
        for(int k=i-1;k>=0;k--)
        {
            if(j%2==1)
            {
                oput[k]='a';
            }
            else
            {
                oput[k]='b';
            }
            j>>=1;
        }
        oput[i]='\0';
        printf("%s\n",oput);
    }
    return 0;
}
