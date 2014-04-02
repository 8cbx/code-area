#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    //int a[30];
    char x1,x2;
    int n,i,j;
    scanf("%d",&n);
    scanf("%c",&x1);
    while(n--)
    {
        //memset(a,0,sizeof(a));
        j=1;
        x1='0';
        while(scanf("%c",&x2)!=EOF)
        {
            //printf("---%c---%c---\n",x1,x2);
            if(x2=='\0'||x2=='\n')
            {
                break;
            }
            //a[x-'A'+1]++;
            if(x1==x2)
            {
                j++;
            }
            else if(x1!='0')
            {
                if(j>1)
                {
                    printf("%d",j);
                }
                printf("%c",x1);
                x1=x2;
                j=1;
            }
            else x1=x2;
        }
        if(j>1)
        {
            printf("%d",j);
        }
        printf("%c",x1);
        printf("\n");
    }
    return 0;
}
