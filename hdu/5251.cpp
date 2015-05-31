#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 4005;
const double inf = 1e20*1.0;
struct point
{
    double x,y;
};
point c[MAX];
const double eps = 1e-6;
bool dy(double x,double y)
{
    return x > y + eps;
}
bool xy(double x,double y)
{
    return x < y - eps;
}
bool dyd(double x,double y)
{
    return x > y - eps;
}
bool xyd(double x,double y)
{
    return x < y + eps;
}
bool dd(double x,double y)
{
    return fabs( x - y ) < eps;
}
double crossProduct(point a,point b,point c)
{
    return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
double disp2p(point a,point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool cmp(point a,point b)
{
    double len = crossProduct(c[0],a,b);
    if( dd(len,0.0) )
        return xy(disp2p(c[0],a),disp2p(c[0],b));
    return xy(len,0.0);
}
double disp2seg(point a,point l1,point l2)
{
    return fabs(crossProduct(a,l1,l2))/disp2p(l1,l2);
}
point foot_line(point a,point l1,point l2)
{
    point c;
    l2.x -= l1.x;
    l2.y -= l1.y;
    c.x = a.x - l1.x - l2.y + l1.x;
    c.y = a.y - l1.y + l2.x + l1.y;
    return c;
}
double rota_angle(point a1,point a2,point b1,point b2)
{
    point t;
    t.x = b2.x - (b1.x - a1.x);
    t.y = b2.y - (b1.y - a1.y);
    return crossProduct(a1,a2,t);
}
double RC_minareaRectangle(point p[],int n)
{
    int r[4];
    memset(r,0,sizeof(r));
    for(int i=0; i<n; i++)
    {
        if( xy(p[i].y,p[r[0]].y) )    r[0] = i;
        if( xy(p[i].x,p[r[1]].x) )    r[1] = i;
        if( dy(p[i].y,p[r[2]].y) )    r[2] = i;
        if( dy(p[i].x,p[r[3]].x) )    r[3] = i;
    }
    int tp = r[0];
    double area = inf;
    do
    {
        point t = foot_line(p[r[0]],p[r[0]],p[(r[0]+1)%n]);
        while( dy(rota_angle(t,p[r[0]],p[r[1]],p[(r[1]+1)%n]),0.0) )
            r[1]++, r[1] %= n;

        while( dy(rota_angle(p[r[0]],t,p[r[3]],p[(r[3]+1)%n]),0.0) )
            r[3]++, r[3] %= n;

        while( dy(disp2seg(p[(r[2]+1)%n],p[r[0]],p[(r[0]+1)%n]),
                  disp2seg(p[r[2]],p[r[0]],p[(r[0]+1)%n])) )
            r[2]++, r[2] %= n;
        double a = disp2seg(p[r[2]],p[r[0]],p[(r[0]+1)%n]);
        t = foot_line(p[r[3]],p[r[0]],p[(r[0]+1)%n]);
        double b = disp2seg(p[r[1]],p[r[3]],t);
        area = min( area, a*b );
        r[0]++;
        r[0] %= n;
    }
    while( r[0] != tp );
    return area;
}
point stk[MAX];
int top;
double Graham(int n)
{
    int tmp = 0;
    for(int i=1; i<n; i++)
        if( xy(c[i].x,c[tmp].x) || (dd(c[i].x,c[tmp].x) && xy(c[i].y,c[tmp].y) ))
            tmp = i;
    swap(c[0],c[tmp]);
    sort(c+1,c+n,cmp);
    stk[0] = c[0];
    stk[1] = c[1];
    top = 1;
    for(int i=2; i<n; i++)
    {
        while( xyd( crossProduct(stk[top],stk[top-1],c[i]), 0.0 ) && top >= 1 )
            top--;
        stk[++top] = c[i];
    }
    return RC_minareaRectangle(stk,top+1);
}
int main()
{
    int n;
    int t;
    int cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        n*=4;
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&c[i].x,&c[i].y);
        double ans = Graham(n);
        printf("Case #%d:\n%d\n",cases,(int)(ans+0.5));
    }
    return 0;
}
