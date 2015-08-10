#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x7fffffff
using namespace std;
typedef long long LL;
const LL maxn=10000+10;
struct Point
{
    LL x,y,z;
    Point (LL x=0,LL y=0,LL z=0):x(x),y(y),z(z) {}
} poin[25];
typedef Point Vector;

double Dot(Vector A,Vector B)
{
    return A.x*B.x + A.y*B.y;
}
double Length(Vector A)
{
    return sqrt(Dot(A,A));
}
double angle(Vector A,Vector B)
{
    return acos(Dot(A,B)/Length(A)/Length(B));
}
LL dis(Point A,Point B)
{
    LL xx=(A.x-B.x)*(A.x-B.x);
    LL yy=(A.y-B.y)*(A.y-B.y);
    LL zz=(A.z-B.z)*(A.z-B.z);
    return xx+yy+zz;
}
int judge(Point a,Point b,Point c,Point d)
{
    int flag=0;
    LL len,len2,len3;
    len=dis(a,b) ;
    len2=dis(a,c) ;
    len3=dis(a,d) ;
    if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
        flag++;
    len=dis(b,a) ;
    len2=dis(b,c) ;
    len3=dis(b,d) ;
    if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
        flag++;
    len=dis(c,a) ;
    len2=dis(c,b) ;
    len3=dis(c,d) ;
    if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
        flag++;
    len=dis(d,a) ;
    len2=dis(d,b) ;
    len3=dis(d,c) ;
    if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
        flag++;
    if (flag==4) return 1;
    else return 0;
}
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&poin[i].x,&poin[i].y);
            poin[i].z=0;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        if(judge(poin[i],poin[j],poin[k],poin[l]))
                        {
                            ans++;
                            //printf("--\n%lld %lld\n%lld %lld\n%lld %lld\n%lld %lld\n",poin[i].x,poin[i].y,poin[j].x,poin[j].y,poin[k].x,poin[k].y,poin[l].x,poin[l].y);
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
