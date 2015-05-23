#include<stdio.h>
#include<string.h>
char s[1000100];
int main()
{
    char ss;
    int t;
    int k;
    int cases=0;
    while(scanf("%d",&t)!=EOF)
    {
        cases=0;
        while(t--)
        {
            cases++;
            printf("Case #%d:\n",cases);
            scanf("%c",&ss);
            memset(s,0,sizeof(s));
            int now=0;
            while(scanf("%c",&ss)!=EOF)
            {
                if(ss=='\n')
                {
                    break;
                }
                s[now]=ss;
                now++;
            }
            scanf("%d",&k);
            //printf("%d--%s\n",k,s);
            int len=strlen(s);
            if(len==k||k==1)
            {
                printf("%s\n",s);
                continue;
            }
            //printf("%d --\n",len);
            int row=len/k;
            int colu=len%k;
            if(colu!=0)
            {
                row++;
            }
            //printf("%d %d\n",row,colu);
            now=0;
            if(colu==0)
            {
                while(now<row)
                {
                    int i=0;
                    int add=row;
                    printf("%c",s[now]);
                    i++;
                    int coun=now;
                    while(i*add+now<len)
                    {
                        //printf("%d---\n",i*k+now);
                        printf("%c",s[coun+add]);
                        coun+=add;
                        if(i==colu)
                        {
                            add--;
                        }
                        i++;
                    }
                    //printf("\n");
                    now++;
                }
                printf("\n");
                continue;
            }
            while(now<row-1)
            {
                int i=0;
                int add=row;
                printf("%c",s[now]);
                i++;
                int coun=now;
                while(i*add+now<len)
                {
                    //printf("%d---\n",i*k+now);
                    printf("%c",s[coun+add]);
                    coun+=add;
                    if(i==colu)
                    {
                        add--;
                    }
                    i++;
                }
                //printf("\n");
                now++;
            }
            for(int i=row-1,coun=0; coun<colu; i+=row,coun++)
            {
                printf("%c",s[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
