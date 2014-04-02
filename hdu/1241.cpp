#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[103][103];
int n,m,t,cou;
int d[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
void DFS(int i,int j)
{
    //if(i>n||j>m)return;
    int k;
    for(k=0;k<8;k++)
    {
        int nx=i+d[k][0];
        int ny=j+d[k][1];
        if(nx>=0&&ny>=0&&ny<m&&nx<n&&a[nx][ny]=='@')
        {
            a[nx][ny]='X';
            DFS(nx,ny);
        }
    }
    return;
}
void make()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]=='@')
            {
                DFS(i,j);
                cou++;
            }
        }
    }
}
int main()
{
    int i,j,k;
    char temp;
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0&&m!=0))
    {
        cou=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        make();
        printf("%d\n",cou);
    }
    return 0;
}
