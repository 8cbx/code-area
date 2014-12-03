#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct det
{
    int time,side,num,kind;
}a[100];
void init()
{
    memset(a,0,sizeof(a));
}
int cmp(det aa,det bb)
{
    return aa.time<bb.time;
}
int main()
{
    int player[5][105];
    int had[5][105];
    int n;
    char s1[100],s2[100],sk[2],sl[2];
    int len1,len2,i,j;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        scanf("%d",&n);
        init ();
        memset(player,0,sizeof(player));
        memset(had,0,sizeof(had));
        for(i=1;i<=n;i++)
        {
            scanf("%d%s%d%s",&a[i].time,&sk,&a[i].num,&sl);
            if(sk[0]=='a')
            {
                a[i].side=1;
            }
            else a[i].side=0;
            if(sl[0]=='y')
            {
                a[i].kind=1;
            }
            else a[i].kind=2;
        }
        sort(a+1,a+1+n,cmp);
        for(i=1;i<=n;i++)
        {
            if(a[i].side==1)
            {
                if(player[1][a[i].num]<2)
                {
                    player[1][a[i].num]+=a[i].kind;
                }
                if(player[1][a[i].num]>=2&&had[1][a[i].num]==0)
                {
                    printf("%s %d %d\n",s2,a[i].num,a[i].time);
                    had[1][a[i].num]=1;
                    //continue;
                }
            }
            else
            {
                if(player[2][a[i].num]<2)
                {
                    player[2][a[i].num]+=a[i].kind;
                }
                if(player[2][a[i].num]>=2&&had[2][a[i].num]==0)
                {
                    printf("%s %d %d\n",s1,a[i].num,a[i].time);
                    had[2][a[i].num]=1;
                    //continue;
                }
            }
        }
    }
    return 0;
}
