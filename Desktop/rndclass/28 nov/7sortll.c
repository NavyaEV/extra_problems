#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
struct node * sortll(struct node *);
int main()
{
    NODE *head,*temp=0,*first=0,*newstart;
    int choice;
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
    temp->link=0;
    newstart=sortll(first);
    printf("Details\n");
    temp=newstart;
    while(temp->link!=0)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
    return 0;
}
struct node * sortll(struct node *first)
{
    struct node *temp,*ptr,*t1,*t2,*t3;
    ptr=first;
    temp=ptr->link;
    if(ptr->data>temp->data)
    {
        while(temp->data<temp->link->data)
        {
            temp=temp->link;
        }
        t1=temp->link;
        t2=t1->link;
        t1->link=ptr->link;
        temp->link=ptr;
        ptr->link=t2;
        return t1;
    }
    while(ptr->link->data<temp->link->data)
    {
        ptr=ptr->link;
        temp=temp->link;
    }
    t1=temp;
    t2=temp->link;
    while(temp->link->data<t2->link->data)
    {
        temp=temp->link;
        t2=t2->link;
    }
    temp=temp->link;
    t2=t2->link;
    t3=t2->link;
    t2->link=t1->link;
    ptr->link=t2;
    temp->link=t1;
    t1->link=t3;
    return first;
}
