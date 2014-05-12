#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int nums,num,n,time,i;
    char s[250],ss;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        num=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='x')
            {
                num++;
            }
        }
        nums=n-num;
        time=(int)fabs(num-nums)/2;
        printf("%d\n",time);
        if(num<nums)
        {
            ss='X';
        }
        else ss='x';
        for(i=0;i<n;i++)
        {
            if(time>0&&s[i]==ss)
            {
                time--;
                printf("%c",ss=='X'?'x':'X');
            }
            else printf("%c",s[i]);
        }
    }
    return 0;
}
