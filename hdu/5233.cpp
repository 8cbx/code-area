#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct data
{
    long long hi;
    int id;
    int flag;
    bool operator <(const data& other) const
    {
        if (hi < other.hi)
        {
            return true;
        }
        else if (hi == other.hi)
        {
            if (id < other.id)
            {
                return true;
            }
            else return false;
        }
        return false;
    }
}h[100010];
int main()
{
    long long q[100010];
    int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
        memset(h,0,sizeof(h));
        memset(q,0,sizeof(q));
		for(int i=1;i<=n;i++)
		{
            scanf("%I64d",&h[i].hi);
            h[i].id=i;
            h[i].flag=0;
		}
		sort(h+1,h+1+n);
		for(int i=1;i<=m;i++)
		{
            scanf("%I64d",&q[i]);
            int l=1,r=n,mid;
            while(l<=r)
            {
                mid=(r-l)/2+l;
                if(h[mid].hi>q[i])
                {
                    r=mid-1;
                }
                else if(h[mid].hi<q[i])
                {
                    l=mid+1;
                }
                else
                {
                    if(h[mid].flag==1)
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
            }
            r++;
            if(h[r].hi!=q[i])
            {
                printf("-1\n");
            }
            else
            {
                while(h[r].hi==q[i]&&h[r].flag==1)
                {
                    r++;
                }
                if(h[r].hi!=q[i])
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n",h[r].id);
                    h[r].flag=1;
                }
            }
		}
	}
	return 0;
}
