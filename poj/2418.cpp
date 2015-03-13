#include<stdio.h>
#include<iostream>
#include<string.h>
int sum;
struct node
{
    char s[35];
    node *left;
    node *right;
    int num;
};
int get(char *s)
{
    int i=0,len;
    char temp;
    len=0;
    while(scanf("%c",&temp)!=EOF)
    {
        if(temp=='\n')
        {
            if(i==0)
            {
                len=0;
                break;
            }
            s[i]='\0';
            len=i+1;
            break;
        }
        else
        {
            s[i]=temp;
            i++;
        }
    }
    return len;
}
node *inser(node *head,char *s)
{
    if(head==NULL)
    {
        head=new node;
        strcpy(head->s,s);
        head->left=head->right=NULL;
        head->num=1;
    }
    else
    {
        if(strcmp(s,head->s)<0)
        {
            head->left=inser(head->left,s);
        }
        else if(strcmp(s,head->s)>0)
        {
            head->right=inser(head->right,s);
        }
        else
        {
            head->num=head->num+1;;
            return head;
        }
    }
    return head;
}
void printff(node* head)
{
    if(head!=NULL)
    {
        printff(head->left);
        printf("%s %.4lf\n",head->s,(double)((double)head->num*100/(double)sum));
        printff(head->right);
    }

}
int main()
{
    char s[30];
    node *head;
    head=new node;
    head->right=NULL;
    head->left=NULL;
    head->num=1;
    get(s);
    sum=1;
    strcpy(head->s,s);
    while(get(s)!=0)
    {
        sum++;
        inser(head,s);
        //printff(head);
    }
    //printf("%d\n",sum);
    printff(head);
    return 0;
}
