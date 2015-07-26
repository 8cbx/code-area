#include<string.h>
#include<stdio.h>
char ss[]={"anniversary"};
int find(char s[],int l,int r,int start)
{
    int len=strlen(s);
    for(int i=start;i<len;i++)
    {
        int flag=0;
        for(int j=0;j<=r-l;j++)
        {
            //printf("%c %c %d %d\n",s[i+j],ss[l+j],i,j);
            if(s[i+j]!=ss[l+j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return i+r-l+1;
        }
    }
    return len+1;
}
int main()
{
    char s[1000];
    int t;
    int len1,len2;
    len2=strlen(ss);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len1=strlen(s);
        //printf("%d\n",len1);
        int flag=0;
        for(int i=0;i<len2;i++)
        {
            for(int j=i+1;j<len2;j++)
            {
               // printf("----%d %d\n",i,j);
                int pos=0;
                pos=find(s,0,i,pos);
                //printf("1-%d\n",pos);
                pos=find(s,i+1,j,pos);
               // printf("2-%d\n",pos);
                pos=find(s,j+1,len2-1,pos);
                //printf("3-%d\n",pos);
                if(pos<=len1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        if(flag==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
