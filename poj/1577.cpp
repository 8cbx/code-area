#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int sum;
struct node
{
    char s;
    node *left;
    node *right;
};
node *findmin(node *head)
{
    if(head!=NULL)
    {
        while(head->left!=NULL)
        {
            head=head->left;
        }
    }
    return head;
}
node *findmax(node *head)
{
    if(head!=NULL)
    {
        while(head->right!=NULL)
        {
            head=head->right;
        }
    }
    return head;
}
node *delet(node *head,char s)
{
    node *temp;
    if(head==NULL)
    {
        return 0;
    }
    if(s<head->s)
    {
        head->left=delet(head,s);
    }
    else
    {
        if(s>head->s)
        {
            head->right=delet(head,s);
        }
        else
        {
            if(head->left==NULL&&head->right==NULL)
            {
                delete head;
                head=NULL;
            }
            else if(head->left)
            {
                for(temp=head->left; temp->right; temp=temp->right);
                head->s=temp->s;
                head->left=delet(head->left,head->s);
            }
            else
            {
                for(temp=head->right; temp->left; temp=temp->left);
                head->s=temp->s;
                head->right=delet(head->right,head->s);
            }
        }
    }
    return head;
}
node *inser(node *head,char s)
{
    if(head==NULL)
    {
        head=new node;
        head->s=s;
        head->left=NULL;
        head->right=NULL;
    }
    else
    {
        if(s<head->s)
        {
            head->left=inser(head->left,s);
        }
        else if(s>head->s)
        {
            head->right=inser(head->right,s);
        }
        else
        {
            return head;
        }
    }
    return head;
}
void printff(node* head)
{
    if(head==NULL)
    {
        return;
    }
    if(head->s>='A'&&head->s<='Z')printf("%c",head->s);
    printff(head->left);
    printff(head->right);
}
node *empt(node* head)
{
    if(head!=NULL)
    {
        empt(head->left);
        empt(head->right);
        delete head;
    }
    return NULL;
}
int main()
{
    char s[50],sb;
    char ss[50];
    int num;
    num=0;
    memset(ss,0,sizeof(ss));
    int i=0;
    while(scanf("%c",&s[i])!=EOF)
    {
        if(s[i]!='*'&&s[i]!='$'&&(s[i]>'Z'||s[i]<'A'))
            continue;
        if(s[i]=='*')
        {
            node *head;
            head=new node;
            head->right=NULL;
            head->left=NULL;
            i--;
            for(; i>=0; i--)
            {
                inser(head,s[i]);
            }
            i=-1;
            printff(head);
            printf("\n");
        }
        else if(s[i]=='$')
        {
            i--;
            node *head;
            head=new node;
            head->right=NULL;
            head->left=NULL;
            for(; i>=0; i--)
            {
                inser(head,s[i]);
            }
            i=-1;
            printff(head);
            printf("\n");
            return 0;
        }
        i++;
    }
    return 0;
}
