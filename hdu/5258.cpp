#include <stdio.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define MAXN 30
struct Line
{
    int x1, x2, y1, y2;
    Line(int xx1=0, int yy1=0, int xx2=0, int yy2=0)
    {
        x1=xx1;
        y1=yy1;
        x2=xx2;
        y2=yy2;
    }
};
Line b[MAXN];
Line a[MAXN];
int n;
int main()
{
    int t;
    int cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        int num1, num2;
        num1=0;
        num2=0;
        for(int i=0;i<n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int j=0;j<num1;j++)
            {
                if(b[j].x1==min(x1,x2)&&b[j].x2==max(x1,x2)&&b[j].y1==min(y1,y2)&&b[j].y2==max(y1,y2)) continue;
            }
            for(int j=0;j<num2;j++)
            {
                if(a[j].x1==min(x1,x2)&&a[j].x2==max(x1,x2)&&a[j].y1==min(y1,y2)&&a[j].y2==max(y1,y2)) continue;
            }
            if(x1==x2)
            {
                b[num1++]=Line(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));
            }
            else
            {
                a[num2++]=Line(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));
            }
        }
        int ans = 0;
        for(int i = 0; i < num1 - 1; i++)
        {
            for(int j = i + 1; j < num1; j++)
            {
                if(b[i].x1 == b[j].x1)
                continue;
                for(int k = 0; k < num2 - 1; k++)
                {
                    for(int h = k + 1; h < num2; h++)
                    {
                        if(a[k].y1 == a[h].y1)
                        continue;
                        if(max(b[i].y1, b[j].y1) <= min(a[k].y1, a[h].y1)&&max(a[k].y1, a[h].y1) <= min(b[i].y2, b[j].y2))
                        {
                            if(max(a[k].x1, a[h].x1) <= min(b[i].x1, b[j].x1)&&max(b[i].x1, b[j].x1) <= min(a[k].x2, a[h].x2))
                            {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d:\n", cases);
        printf("%d\n", ans);
    }
    return 0;
}
