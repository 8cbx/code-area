#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[6000];
int main()
{
    int i,j,k,l,t;
    int ii,jj,kk,ll;
    i=1;
    j=1;
    k=1;
    l=1;
    int n=5842-1;
    a[1]=1;
    //a[2]=2;
    //a[3]=3;
    //a[4]=4;
    t=1;
    int *minm;
    while(n--)
    {
        //minm=99999;
        t++;
        ii=a[i]*2;
        jj=a[j]*3;
        kk=a[k]*5;
        ll=a[l]*7;
        if(ii>jj)
        {
            //*minm=j;
            a[t]=jj;
        }
        else a[t]=ii;
        if(a[t]>kk)
        {
            //*minm=k;
            a[t]=kk;
        }
        if(a[t]>ll)
        {
            //*minm=l;
            a[t]=ll;
        }
        if(a[t]==ii)i++;
        if(a[t]==jj)j++;
        if(a[t]==kk)k++;
        if(a[t]==ll)l++;
        //printf("%d-%d-%d-%d-%d\n",a[t],i,j,k,l);
    }
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        if(n%10==1&&n%100!=11)
        {
            printf("The %dst humble number is %d.\n",n,a[n]);
        }
        else if(n%10==2&&n%100!=12)
        {
            printf("The %dnd humble number is %d.\n",n,a[n]);
        }
        else if(n%10==3&&n%100!=13)
        {
            printf("The %drd humble number is %d.\n",n,a[n]);
        }
        else printf("The %dth humble number is %d.\n",n,a[n]);
    }
    return 0;
}
