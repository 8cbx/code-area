#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,aa,bb,aaa,bbb;
    scanf("%d%d%d%d%d%d",&a,&b,&aa,&bb,&aaa,&bbb);
    int resa,resb,ressa,ressb;
    if(a-aa>=0&&b-bb>=0)
    {
        resa=a-aa;
        resb=b;
        ressa=b-bb;
        ressb=a;
    }
    else
    {
        resa=0;
        resb=0;
        ressa=0;
        ressb=0;
    }
    //printf("---%d %d %d %d\n",resa,resb,ressa,ressb);
    if((resa>=aaa&&resb>=bbb)||(resb>=aaa&&resa>=bbb)||(ressa>=aaa&&ressb>=bbb)||(ressb>=aaa&&ressa>=bbb))
    {
        printf("YES\n");
        return 0;
    }
    if(a-bb>=0&&b-aa>=0)
    {
        resa=a-bb;
        resb=b;
        ressa=b-aa;
        ressb=a;
    }
    else
    {
        resa=0;
        resb=0;
        ressa=0;
        ressb=0;
    }
    if((resa>=aaa&&resb>=bbb)||(resb>=aaa&&resa>=bbb)||(ressa>=aaa&&ressb>=bbb)||(ressb>=aaa&&ressa>=bbb))
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}
