#include<string.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k;
    int maxl,maxr;
    char s1[50010],s2[50010],temp;
    int len,p,num[50010],now,ans;
    while(scanf("%d%d",&len,&p)!=EOF)
    {
        ans=0;
        memset(num,0,sizeof(num));
        scanf("%c",&temp);
        for(i=1; i<=len/2; i++)
        {
            scanf("%c",&s1[i]);
        }
        for(i=len-len/2; i>0; i--)
        {
            scanf("%c",&s2[i]);
        }
        maxl=len/2+1;
        maxr=0;
        for(i=1; i<=len/2; i++)
        {
            if(s1[i]!=s2[i])
            {
                if(maxl>i)
                {
                    maxl=i;
                }
                if(maxr<i)
                {
                    maxr=i;
                }
                now=fabs(s1[i]-s2[i]);
                if(now>13)
                {
                    now=26-now;
                }
                num[i]=now;
                ans+=now;
            }
        }
        if(ans==0)
        {
            printf("0\n");
            continue;
        }
        //printf("%d\n",ans);
        if(len%2==1&&p==(len/2+1))
        {
            p--;
            ans++;
        }
        else if(p>len/2)
        {
            p=len-p+1;
        }
       // printf("%d %d\n",maxl,maxr);
        if(maxl-p>0)
        {
            ans+=maxr-p;
        }
        else if(maxl<=p&&maxr>=p)
        {
            if(p-maxl<maxr-p)
            {
                ans+=(maxr-maxl)+p-maxl;
               // printf("-%d\n",ans);
            }
            else
            {
                ans+=(maxr-maxl)+maxr-p;
                //printf("--%d\n",ans);
            }
        }
        else if(p>maxr)
        {
            ans+=p-maxl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
