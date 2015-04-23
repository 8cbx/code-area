#include<stdio.h>
bool TestLeapYear(int &Year)
{
    if(Year%400==0||(Year%4==0&&Year%100!=0))
        return true;
    return false;
}
void todo(int Year,int Day)
{
    int HowManyDays[13]= {0,31,59,90,120,151,181,212,243,273,304,334,365};
    int Month;
    if(TestLeapYear(Year))
        if(Day==HowManyDays[2]+1)
        {
            printf("%d-02-29",Year);
            return;
        }
        else if(Day>HowManyDays[2])
            Day--;
    Month=0;
    while(HowManyDays[Month]<Day)
        Month++;
    printf("%d-%.2d-%.2d",Year,Month,Day-HowManyDays[Month-1]);
    return;
}
int main()
{
    int days;
    char s[7][10]= {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    while(scanf("%d",&days)!=EOF)
    {
        if(days==-1)
        {
            break;
        }
        int year=2000;
        int temp=days;
        days++;
        while(days-365>0)
        {
            days-=365;
            if(TestLeapYear(year))
            days--;
            year++;
        }
        if(days==0)
        {
            days=365;
            year--;
            if(TestLeapYear(year))
                days++;
        }
        todo(year,days);
        printf(" %s\n",s[temp%7]);
    }
    return 0;
}
