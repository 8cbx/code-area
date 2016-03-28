#include<stdio.h>
#include<string.h>
int maz[6][6];
int check(int x,int y)
{
    if(maz[y/3][y%3]==1)
    {
        return 1;
    }
    if(x==1)
    {
        if(y==2||y==4||y==5)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==7)
            {
                if(maz[4/3][4%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==9)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==3)
            {
                if(maz[2/3][2%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
    if(x==2)
    {
        if(y==1||y==4||y==5||y==3||y==6)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==8)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
    if(x==3)
    {
        if(y==2||y==5||y==6)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==1)
            {
                if(maz[2/3][2%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==7)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==9)
            {
                if(maz[6/3][6%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
    if(x==4)
    {
        if(y==1||y==2||y==5||y==8||y==7)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==6)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
    if(x==5)
    {
        maz[y/3][y%3]=1;
        return 0;
    }
    if(x==6)
    {
        if(y==2||y==3||y==5||y==8||y==9)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==4)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
    if(x==7)
    {
        if(y==4||y==5||y==8)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==1)
            {
                if(maz[4/3][4%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==3)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==9)
            {
                if(maz[8/3][8%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
    if(x==8)
    {
        if(y==4||y==7||y==5||y==6||y==9)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==2)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
    if(x==9)
    {
        if(y==6||y==5||y==8)
        {
            maz[y/3][y%3]=1;
            return 0;
        }
        else
        {
            if(y==7)
            {
                if(maz[8/3][8%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==1)
            {
                if(maz[5/3][5%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else if(y==3)
            {
                if(maz[6/3][6%3]==1)
                {
                    maz[y/3][y%3]=1;
                    return 0;
                }
                else return 1;
            }
            else
            {
                maz[y/3][y%3]=1;
                return 0;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        int s[15];
        scanf("%d",&k);
        int flag=0;
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&s[i]);
            if(s[i]>9||s[i]==0)
            {
                flag=1;
            }
        }
        if(k<4)
        {
            flag=1;
        }
        if(flag==1)
        {
            printf("invalid\n");
            continue;
        }
        memset(maz,0,sizeof(maz));
        maz[s[1]/3][s[1]%3]=1;
        for(int i=1;i<k;i++)
        {
            if(check(s[i],s[i+1])==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("valid\n");
        }
        else
        {
            printf("invalid\n");
        }
    }
    return 0;
}
