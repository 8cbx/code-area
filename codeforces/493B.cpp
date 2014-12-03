#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long a[100010*2];
long long b[100010*2];
long long suma,sumb;
long long n,temp;
int timea,timeb;
void init()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    suma=0;
    sumb=0;
    timea=0;
    timeb=0;
}
int main()
{
    int i,last;
    while(cin>>n)
    {
        init ();
        int flag=0;
        last=0;
        int flagg=0;
        for(i=1; i<=n; i++)
        {
            cin>>temp;
            if(i==n)
            {
                if(temp>0)
                {
                    last=0;
                }
                else last=1;
            }
            if(temp>0)
            {
                timea++;
                a[timea]=temp;
                suma+=a[timea];
            }
            else
            {
                timeb++;
                b[timeb]=-temp;
                sumb+=b[timeb];
            }
        }
        if(suma>sumb)
        {
            printf("first\n");
            continue;
        }
        else if(suma<sumb)
        {
            printf("second\n");
            continue;
        }
        else
        {
            if(timea>timeb)
            {
                flag=1;
            }
            else if(timea<timeb)
            {
                flag=0;
            }
        }
        for(i=1; i<=(flag==0?timea:timeb); i++)
        {
            if(i==(flag==0?timea:timeb))
            {
                if(a[i]>b[i])
                {
                    printf("first\n");
                    flagg=1;
                    break;
                }
                else
                {
                    if(a[i]<b[i])
                    {
                        printf("second\n");
                        flagg=1;
                        break;
                    }
                }
            }
            else
            {
                if(a[i]>b[i])
                {
                    printf("first\n");
                    flagg=1;
                    break;
                }
                else if(a[i]<b[i])
                {
                    printf("second\n");
                    flagg=1;
                    break;
                }
            }
        }
        if(flagg==0)
        {
            if(last==1)
            {
                printf("second\n");
                continue;
            }
            else if(last==0)
            {
                printf("first\n");
                continue;
            }
        }
    }
    return 0;
}
