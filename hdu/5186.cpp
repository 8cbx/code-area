#include<stdio.h>
#include<string.h>
int main()
{
    char s[210];
    int ss[210];
    int n,b;
    int len;
    int k;
    int temp;
    while(scanf("%d%d",&n,&b)!=EOF)
    {
        memset(ss,0,sizeof(ss));
        memset(s,0,sizeof(s));
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            len=strlen(s);
            k=1;
            for(int j=len-1; j>=0; j--)
            {
                if(j>=0)
                {
                    if(s[j]<='z'&&s[j]>='a')
                    {
                        temp=s[j]-'a'+10;
                    }
                    else if(s[j]<='9'&&s[j]>='0')
                    {
                        temp=s[j]-'0';
                    }
                    ss[k]=(ss[k]+temp)%b;
                    k++;
                }
            }
            /*for(int j=1;j<=5;j++)
            {
                printf("%d",ss[j]);
            }
            printf("---");*/
        }
        k=205;
        int flag=0;
        while(k>0)
        {
            if(ss[k]!=0)
            {
                flag=1;
                //printf("%d\n",ss[k]);
            }
            if(flag==1)
            {
                if(ss[k]>9)
                {
                    printf("%c",ss[k]-10+'a');
                }
                else
                {
                    printf("%d",ss[k]);
                }
            }
            k--;
        }
        if(flag==0)
        {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
