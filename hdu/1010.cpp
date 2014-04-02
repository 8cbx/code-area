#include<stdio.h>
#include<stdlib.h>
char a[10][10];
int x[150],y[150];
int t,m,n;
int xs,ys,xd,yd;
int ok;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
void DFS(int aa,int bb,int time)
{
    int i;
    if(time==t)
    {
        if(aa==xd&&bb==yd)
            ok=1;
        return;
    }
    if(ok)return;
    int temp=abs(aa-xd)+abs(bb-yd)-abs(time-t);
    if(temp>0||temp&1)return;
    for(i=0;i<4;i++)
    {
        int fx=aa+dir[i][0];
        int fy=bb+dir[i][1];
        if(fx>=0&&fx<n&&fy>=0&&fy<m&&a[fx][fy]!='X')
        {
            a[fx][fy]='X';
            DFS(fx,fy,time+1);
            a[fx][fy]='.'; //回溯
        }
    }
}

int main()
{
    int wall;

    int i,j,k;
    char temp;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF&&(n!=0||m!=0||t!=0))
    {
        ok=0;
        wall=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            for(j=0;a[i][j]!='\0';j++)
            {
                if(a[i][j]=='X')
                {
                    wall++;
                }
                else if(a[i][j]=='S')
                {
                    xs=i;
                    ys=j;
                }
                else if(a[i][j]=='D')
                {
                    xd=i;
                    yd=j;
                }
            }
        }
        if(n*m-wall<t)
        {
            printf("NO\n");
        }
        else
        {
            a[xs][ys]='X';
            DFS(xs,ys,0);
            if(ok)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
