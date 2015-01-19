#include<stdio.h>
#include<string.h>
int main()
{
    char s[20];
    int len,mid;
    int flag;
    while(scanf("%s",s)!=EOF)
    {
        flag=0;
        len=strlen(s);
        mid=len/2;
        if(len%2==0)
        {
            for(int i=0; i<mid; i++)
            {
                if(s[i]!=s[len-1-i])
                {
                    flag=1;
                    break;
                }
            }
        }
        else
        {
            for(int i=0; i<mid; i++)
            {
                if(s[i]!=s[len-1-i])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            for(int i=0; i<len; i++)
            {
                printf("%c",s[i]);
                if(i==mid)
                {
                    printf("%c",s[i]);
                }
            }
            printf("\n");
            continue;
        }
        int left=0;
        int right=0;
        int flag2=0;
        int no=0;
        if(len%2==0)
        {
            for(int i=0; i<mid-1; i++)
            {
                while(s[i]!=s[len-1-right-i])
                {
                    right++;
                    if(right>1)
                    {
                        no=1;
                        break;
                    }
                }
            }
            if(no==0)
            {
                for(int i=len-1; i>=mid-1; i--)
                {
                    printf("%c",s[i]);
                }
                for(int i=mid; i<len; i++)
                {
                    printf("%c",s[i]);
                }
                printf("\n");
                continue;
            }
            no=0;
            right=0;
            for(int i=len-1; i>mid; i--)
            {
                while(s[i]!=s[len-1+right-i])
                {
                    right++;
                    if(right>1)
                    {
                        no=1;
                        break;
                    }
                }
            }
            if(no==0)
            {
                for(int i=0; i<=mid; i++)
                {
                    printf("%c",s[i]);
                }
                for(int i=mid-1; i>=0; i--)
                {
                    printf("%c",s[i]);
                }
                printf("\n");
                continue;
            }
            printf("NA\n");
        }
        else
        {
            int z,y,nn;
            z=0,y=0;
            nn=0;
            for(int i=0;i<mid;i++)
            {
                while(s[i+z]!=s[len-1-i])
                {
                    z++;
                    if(z>1)
                    {
                        nn=1;
                        break;
                    }
                }
            }
            if(nn==0)
            {
                for(int i=0; i<=mid; i++)
                {
                    printf("%c",s[i]);
                }
                for(int i=mid; i>=0; i--)
                {
                    printf("%c",s[i]);
                }
                printf("\n");
                continue;
            }
             z=0,y=0;
            nn=0;
            for(int i=len-1;i>mid;i--)
            {
                while(s[i-z]!=s[len-1-i])
                {
                    //printf("%c--%c %d %d\n",s[i-z],s[len-1-i],i-z,i);
                    z++;
                    if(z>1)
                    {
                        nn=1;
                        break;
                    }
                }
            }
            if(nn==0)
            {
                for(int i=len-1; i>mid-1; i--)
                {
                    printf("%c",s[i]);
                }
                for(int i=mid; i<len; i++)
                {
                    printf("%c",s[i]);
                }
                printf("\n");
                continue;
            }
            printf("NA\n");
        }
    }
    return 0;
}
