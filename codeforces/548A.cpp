#include<stdio.h>
#include<string.h>
int main()
{
    char s[1500];
    int k;
    int len;
    scanf("%s",s);
    scanf("%d",&k);
    len=strlen(s);
    if(len%k!=0)
    {
        printf("NO\n");
        return 0;
    }
    if(len==1&&k==1)
    {
        printf("YES\n");
        return 0;
    }
    int num=len/k;
    int now=0;
    int head,rear;
    while(now+num<=len)
    {
        head=now;
        rear=now+num-1;
        while(head<=rear)
        {
            //printf("%d %d %c %c\n",head,rear,s[head],s[rear]);
            if(s[head]!=s[rear])
            {
                printf("NO\n");
                return 0;
            }
            head++;
            rear--;
        }
        now+=num;
    }
    printf("YES\n");
    return 0;
}
