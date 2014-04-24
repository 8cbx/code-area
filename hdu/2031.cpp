#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
string transforms(int x,int y,string s)
{
    string res="";
    int sum=0;
    for(int i=0;i<s.length();++i)
    {
        if(s[i]=='-')
        {
            continue;
        }
        if(s[i]>='0'&&s[i]<='9')
        {
            sum=sum*x+s[i]-'0';
        }
        else
        {
            sum=sum*x+s[i]-'A'+10;
        }
    }
    while(sum)
    {
        char tmp=sum%y;
        sum/=y;
        if(tmp<=9)
        {
            tmp+='0';
        }
        else
        {
            tmp=tmp-10+'A';
        }
        res=tmp+res;
    }
    if(res.length()==0)res="0";
    if(s[0]=='-')res='-'+res;
    return res;
}
int main()
{
    int a,b;
    string s;
    while(cin>>s>>b)
    {
        cout<<transforms(10,b,s)<<endl;
    }
    return 0;
}
