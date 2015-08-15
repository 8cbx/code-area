#include<stdio.h>
#include<string.h>
char s[1000000];
int main()
{
    int t;
    int cases=0;
    while(scanf("%s%d",s,&t)!=EOF)
    {
        cases++;
        if(t==-1)
        {
            return 0;
        }
        long long ans=0;
        long long ji=0;
        long long ou=0;
        int len=strlen(s);
        bool oufou=0;
        for(int i=0;i<len;i++)
        {
            if(oufou==0)
            {
                ji+=s[i]-'0';
                ans+=s[i]-'0';
            }
            else
            {
                ou+=s[i]-'0';
                ans+=s[i]-'0';
            }
            oufou^=1;
        }
        //printf("%lld %lld %lld\n",ans,ji,ou);
        long long tmp;
        long long tmpj=0,tmpo=0;
        while(t--)
        {
            tmp=ans;
            tmpj=0;
            tmpo=0;
            int wei=0;
            while(tmp>0)
            {
                wei++;
                if(wei&1)
                {
                    tmpj+=tmp%10;
                }
                else
                {
                    tmpo+=tmp%10;
                }
                tmp/=10;
            }
            if(wei&1)
            {
                if(oufou&1)
                {
                    ji+=tmpo;
                    ou+=tmpj;
                    ans+=tmpj;
                    ans+=tmpo;
                    oufou^=1;
                }
                else
                {
                    ji+=tmpj;
                    ou+=tmpo;
                    ans+=tmpj;
                    ans+=tmpo;
                    oufou^=1;
                }
            }
           else
            {
                if(oufou&1)
                {
                    ji+=tmpj;
                    ou+=tmpo;
                    ans+=tmpj;
                    ans+=tmpo;
                }
                else
                {
                    ji+=tmpo;
                    ou+=tmpj;
                    ans+=tmpj;
                    ans+=tmpo;
                }
            }
            //printf("%lld %lld %lld\n",ans,ji,ou);
        }
        if((ji-ou)%11==0||ji==ou)
        {
            printf("Case #%d: Yes\n",cases);
        }
        else
        {
            printf("Case #%d: No\n",cases);
        }
    }
    return 0;
}
