#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
struct node * addnode(struct node *,int );
int main()
{
    NODE *head,*temp=0,*first=0,*newstart;
    int choice,newdata;
    while(1)
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("Enter the details 1\n");
        scanf("%d",&head->data);
        if (first!=0)
        {
            temp->link=head;
            temp=head;
        }
        else
        {
            first=temp=head;
        }
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);
        if(choice==0)
            break;
    }
    temp->link=first;
    printf("Enter new data node:");
    scanf("%d",&newdata);
    first=addnode(first,newdata);
    for(temp=first;temp->link!=first;temp=temp->link)
    {
        printf("%d ",temp->data);
    }
    printf("%d",temp->data);
    return 0;
}
struct node * addnode(struct node *first,int newdata)
{
    struct node *ptr,*pre,*n;
    ptr=first;
    if(ptr->link==ptr)
    {
        if(ptr->data>newdata)
        {
            n=(struct node *)malloc(sizeof(struct node));
            n->data=newdata;
            n->link=ptr;
            ptr->link=n;
            return n;
        }
    }
    else
    {
    while(ptr->data<newdata)
    {
        pre=ptr;
        if(ptr->link==first)
            break;
        ptr=ptr->link;
    }
    n=(struct node *)malloc(sizeof(struct node));
    n->data=newdata;
    if(ptr->data<newdata)
    {
        ptr->link=n;
        n->link=first;
    }
    else
    {
        pre->link=n;
        n->link=ptr;
    }
    return first;
    }
}
