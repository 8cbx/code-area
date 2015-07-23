#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
string cpy(string a)
{
    if(a.size()%2==1)
        return a;
    string tmp="";
    for(int i=0;i<(int)a.size()/2;i++)
    {
        tmp.push_back(a[i]);
    }
    string aa=cpy(tmp);
    tmp.clear();
    for(int i=(int)a.size()/2;i<(int)a.size();i++)
    {
        tmp.push_back(a[i]);
    }
    string bb=cpy(tmp);
    if(aa<bb)return aa+bb;
    else return bb+aa;
}
int main()
{
    string s,ss;
    cin>>s>>ss;
    if(cpy(s)==cpy(ss))
    {
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}
