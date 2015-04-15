#include<string.h>
#include<stdio.h>
char s[10][10]={"one","two","three","four","five","six","seven","eight","nine","ten"};
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if(a==0)
        {
            printf("zero\n");
            continue;
        }
        if(a<=10)
        {
            printf("%s\n",s[a-1]);
            continue;
        }
        else if(a<=20)
        {
            if(a==11)
                printf("eleven\n");
            if(a==12)
                printf("twelve\n");
            if(a==13)
                printf("thirteen\n");
            if(a==14)
                printf("fourteen\n");
            if(a==15)
                printf("fifteen\n");
            if(a==16)
                printf("sixteen\n");
            if(a==17)
                printf("seventeen\n");
            if(a==18)
                printf("eighteen\n");
            if(a==19)
                printf("nineteen\n");
            if(a==20)
                printf("twenty\n");
            continue;
        }
        else if(a<=30)
        {
            if(a==30)
                printf("thirty\n");
            else printf("twenty-%s\n",s[a%10-1]);
            continue;
        }
        else if(a<=40)
        {
            if(a==40)
                printf("forty\n");
            else printf("thirty-%s\n",s[a%10-1]);
            continue;
        }
        else if(a<=50)
        {
            if(a==50)
                printf("fifty\n");
            else printf("forty-%s\n",s[a%10-1]);
            continue;
        }
        else if(a<=60)
        {
            if(a==60)
                printf("sixty\n");
            else printf("fifty-%s\n",s[a%10-1]);
            continue;
        }
        else if(a<=70)
        {
            if(a==70)
                printf("seventy\n");
            else printf("sixty-%s\n",s[a%10-1]);
            continue;
        }
        else if(a<=80)
        {
            if(a==80)
                printf("eighty\n");
            else printf("seventy-%s\n",s[a%10-1]);
            continue;
        }
        else if(a<=90)
        {
            if(a==90)
                printf("ninety\n");
            else printf("eighty-%s\n",s[a%10-1]);
            continue;
        }
        else
        {
            printf("ninety-%s\n",s[a%10-1]);
        }
    }
    return 0;
}

