#include<stdio.h>
#include<string.h>
#define minn(a,b) a>b?b:a
#define maxx(a,b) a<b?b:a
#define INF 99999999
int ok,ans,dist;
int n,p1,p2,q1,q2,p3,q3;
int aabs(int a,int b)
{
    return (a-b>0)?(a-b):(b-a);
}
void change(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int inbox(int now,int l,int r)
{
    return now>=l&&now<=r;
}
int havecross(int l,int r,int ll,int rr)
{
    return!(r<ll||rr<l);
}
int check(int p,int q,int pp,int qq,int step)
{
    int i,l,r,x;
    int direc=pp>p?1:-1;
    //printf("%d %d %d\n",l,r,x);
    for(i=1;i<=step;i++)
    {
        l=maxx(1,maxx(q-i,qq-(dist-i)));
        //printf("%d %d %d %d\n",i,l,r,x);
        r=minn(n,minn(q+i,qq+(dist-i)));
        x=p+direc*i;
        //printf("%d %d %d %d\n",i,l,r,x);
        if(((x==p3-i||x==p3+i)&&havecross(l,r,q3-i,q3+i))
        ||(aabs(p3,x)<i&&(inbox(q3-i,l,r)||inbox(q3+i,l,r))))
        return i;
    }
    return INF;
}
void did()
{
    dist=aabs(p1,p2);
    //printf("%d\n",dist);
    //printf("%d %d\n",check(p1,q1,p2,q2,dist/2-1),check(p2,q2,p1,q1,dist/2-1));
    ans=minn(check(p1,q1,p2,q2,dist/2-1),check(p2,q2,p1,q1,dist/2-1));
    //printf("%d\n",ans);
    if(ans!=INF)
    {
        ok=1;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ok=ans=0;
        scanf("%d%d%d%d%d%d",&p1,&q1,&p2,&q2,&p3,&q3);
        if(aabs(p1,p2)<aabs(q1,q2))
        {
            change(&p1,&q1);
            change(&p2,&q2);
            change(&p3,&q3);
        }
        did();
        if(ok==0)
        {
            printf("NO\n%d\n",dist-1);
        }
        else
        {
            printf("YES\n%d\n",ans);
        }
    }
    return 0;
}
