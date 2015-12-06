#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
struct node * sortll(struct node *);
void reversell(struct node **);
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
    struct node *p1,*p2;
    p1=first;
    while(p1->link->data<p1->link->link->data)
    {
        p1=p1->link;
    }
    p2=p1->link;
    reversell(&p2);
    p1->link=p2;
    return first;
}
void reversell(struct node **head)
{
    struct node *first,*next;
    if(*head==NULL)
        return;
    first=*head;
    next=first->link;
    if(next==NULL)
        return ;
    reversell(&next);
    first->link->link=first;
    first->link=NULL;
    *head=next;
}
