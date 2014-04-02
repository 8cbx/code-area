#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n;
    double i,j;
    char s;
    scanf("%d",&n);
    while(n--)
    {
        while(scanf("%c",&s)!=EOF&&(s!='*'&&s!='/'&&s!='+'&&s!='-'));
        /*{
            printf("%c--\n",s);
        }*/
        //printf("%c--\n",s);
            scanf("%lf%lf",&i,&j);
            if(s=='*')
            {
                printf("%.0lf\n",i*j);
            }
            if(s=='/')
            {
                if((int)i%(int)j!=0)printf("%.2lf\n",i/j);
                else printf("%.0lf\n",i/j);
            }
            if(s=='+')
            {
                printf("%.0lf\n",i+j);
            }
            if(s=='-')
            {
                printf("%.0lf\n",i-j);
            }

    }
    return 0;
}
