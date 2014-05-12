#include<stdio.h>
#include<string.h>
int main()
{
    int year,month,day,i,sum;
    int days[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
    {
        sum=0;
        for(i=1;i<month;i++)
        {
            sum+=days[i];
        }
        if(month>2&&((year%4==0&&year%100!=0)||year%400==0))
        {
            sum++;
        }
        sum+=day;
        printf("%d\n",sum);
    }
    return 0;
}
