
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node * addll(struct node *,struct node *);
void reversell(struct node **);
typedef struct node NODE;
int main()
{
    NODE *head,*temp=0,*first1=0,*first2=0;
    int choice,c;
    float median;
    printf("Enter details of first linked lists\n");
    while(1)
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("Enter the details\n");
        scanf("%d",&head->data);
        if (first1!=0)
        {
            temp->link=head;
            temp=head;
        }
        else
        {
            first1=temp=head;
        }
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);
        if(choice==0)
            break;
    }
    temp->link=0;
    printf("Enter details of second linked lists\n");
    while(1)
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("Enter the details\n");
        scanf("%d",&head->data);
        if (first2!=0)
        {
            temp->link=head;
            temp=head;
        }
        else
        {
            first2=temp=head;
        }
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);
        if(choice==0)
            break;
    }
    temp->link=0;
    temp=addll(first1,first2);
    while(temp->link!=0)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
    return 0;
}
struct node * addll(struct node *f1,struct node *f2)
{
    int c1=0,c2=0,sum;
    struct node *p1,*p2;
    reversell(&f1);
    reversell(&f2);
    p1=f1;
    p2=f2;
    while((p1->link!=NULL)&&(p2->link!=NULL))
    {
        sum=p1->data+p2->data;
        p1->data=sum;
        p2->data=sum;
        p1=p1->link;
        p2=p2->link;
    }
    sum=p1->data+p2->data;
    p1->data=sum;
    p2->data=sum;
    if(p1->link==NULL)
    {
        reversell(&f2);
        return f2;
    }
    else
    {
        reversell(&f1);
        return f1;
    }
}
void reversell(struct node **head)
{
    struct node *first;
    struct node *rest;
    if(*head==NULL)
        return;
    first=*head;
    rest=first->link;
    if (rest==NULL)
        return ;
    reversell(&rest);
    first->link->link=first;
    first->link=NULL;
    *head=rest;
}
