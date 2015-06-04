#include<stdio.h>
#include<string.h>
int ok(int left,int right)
{
    if(((right-left)>=2)||((left-right)>=2))
    {
        return 1;
    }
    else return 0;
}
int main()
{
    int flag=0,flag2=0;
    char a[100100];
    int c[100010];
    int b[100010];
    scanf("%s",a);
    int n=strlen(a);
    int now=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]=='A'&&a[i+1]=='B')
        {
            flag=1;
            c[now]=i;
            now++;
            //printf("--%d\n",i);
        }
    }
    int no=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]=='B'&&a[i+1]=='A')
        {
            flag2=1;
            b[no]=i;
            no++;
            //printf("%d--\n",i);
        }
    }
    //printf("%d %d %d %d\n",flag,flag2,left,right);
    if(flag!=1||flag2!=1)
    {
        printf("NO\n");
        return 0;
    }
    //printf("%d %d\n",right-left,(left-right));
    for(int i=0;i<now;i++)
    {
        for(int j=0;j<no;j++)
        {
            if(ok(c[i],b[j])==1)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
