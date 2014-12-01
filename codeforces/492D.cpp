#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long seq[1000010<<1];
long long times[1000010<<1];
int main()
{
    long long a,b,time,sum,big,gcdd,now1,now2;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cin>>a>>b;
        sum=a+b;
        big=a*b;
        memset(times,-1,sizeof(times));
        memset(seq,0,sizeof(seq));
        now1=0;
        now2=0;
        for(int j=1; j<=sum; j++)
        {
            if(now1+b>now2+a)
            {
                times[j]=1;
                seq[j]=seq[j-1]+1;
                now2+=a;
            }
            else if(now1+b<now2+a)
            {
                times[j]=2;
                seq[j]=seq[j-1]+1;
                now1+=b;
            }
            else
            {
                times[j]=0;
                seq[j]=seq[j-1]+1;
                now1+=b;
                now2+=a;
                j++;
                times[j]=0;
                seq[j]=seq[j-1]+1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            cin>>time;
            time%=sum;
            if(time==0)
                time=sum;
            if(times[seq[time]]==2)
            {
                printf("Vanya\n");
            }
            else if(times[seq[time]]==1)
            {
                printf("Vova\n");
            }
            else
            {
                printf("Both\n");
            }
        }
    }
    return 0;
}
