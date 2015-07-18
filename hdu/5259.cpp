#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
};
struct data
{
    point a[5];
} he[5010];
int ab(int a,int b)
{
    return a>b?(a-b):(b-a);
}
int cha(point a,point b)
{
    return ab(a.x,b.x)+ab(a.y,b.y);
}
int dp[5010][5][5][5][5];
int main()
{
    int n;
    int t;
    int cases;
    cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        for(int i = 0; i < 4; i++)
        {
            he[0].a[i].x = 0;
            he[0].a[i].y = i + 1;
        }
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=3; j++)
            {
                scanf("%d%d",&he[i].a[j].x,&he[i].a[j].y);
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[0][0][1][2][3] = 0;
        /*do
        {
            for(int i=0; i<=3; i++)
            {
                printf("%d ",dp[1][c[0]][c[1]][c[2]][c[3]]);
            }
            printf("\n");
        }
        while(next_permutation(c,c+4));*/
        for(int i=1; i<=n; i++)
        {
            int a[4]= {0,1,2,3};
            do
            {
                if(dp[i-1][a[0]][a[1]][a[2]][a[3]]!=-1)
                {
                    int b[4]= {0,1,2,3};
                    do
                    {
                        //printf("--%d %d %d %d %d %d\n",dp[i][a[0]][a[1]][a[2]][a[3]],b[0],b[1],b[2],b[3],dp[i-1][b[0]][b[1]][b[2]][b[3]]);
                        if(he[i].a[b[0]].y<=he[i].a[b[1]].y&&he[i].a[b[1]].y<=he[i].a[b[2]].y&&he[i].a[b[2]].y<=he[i].a[b[3]].y)
                        {
                            int tmp=dp[i-1][a[0]][a[1]][a[2]][a[3]]+cha(he[i].a[b[0]],he[i-1].a[a[0]])+cha(he[i].a[b[3]],he[i-1].a[a[3]])+cha(he[i].a[b[1]],he[i-1].a[a[1]])+cha(he[i].a[b[2]],he[i-1].a[a[2]]);
                            if(dp[i][b[0]][b[1]][b[2]][b[3]]==-1)dp[i][b[0]][b[1]][b[2]][b[3]]=tmp;
                            else dp[i][b[0]][b[1]][b[2]][b[3]]=min(dp[i][b[0]][b[1]][b[2]][b[3]],tmp);

                            /*dp[i][a[0]][a[1]][a[2]][a[3]]=min(dp[i-1][a[0]][a[1]][a[2]][a[3]]+cha(he[i-1].a[a[0]],he[i].a[a[0]])+cha(he[i-1].a[a[3]],he[i].a[a[3]])+cha(he[i-1].a[a[1]],he[i].a[a[1]])+cha(he[i-1].a[a[2]],he[i].a[a[2]]),
                                                              dp[i-1][b[0]][b[1]][b[2]][b[3]]+cha(he[i-1].a[b[0]],he[i].a[a[0]])+cha(he[i-1].a[b[3]],he[i].a[a[3]])+cha(he[i-1].a[b[1]],he[i].a[a[1]])+cha(he[i-1].a[b[2]],he[i].a[a[2]]));
                            //printf("%d\n",dp[i][a[0]][a[1]][a[2]][a[3]]);*/
                        }
                    }
                    while(next_permutation(b,b+4));
                }
            }
            while(next_permutation(a,a+4));
        }
        int ans = 2000000000;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    for(int l = 0; l < 4; l++)
                    {
                        if(dp[n][i][j][k][l] != -1) ans = min(ans, dp[n][i][j][k][l]);
                    }
                }
            }
        }
        printf("Case #%d:\n",cases);
        printf("%d\n",ans);
    }
    return 0;
}
