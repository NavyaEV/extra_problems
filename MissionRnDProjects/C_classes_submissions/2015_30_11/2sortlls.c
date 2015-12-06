#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node * mergell(struct node *,struct node *);
typedef struct node NODE;
NODE *reversell(NODE *,NODE *,int );
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
    do
    {
        c=0;
        if(first1->data<first2->data)
            first1=mergell(first1,first2);
        else if(first1->data>first2->data)
            first1=mergell(first2,first1);
        else
        {
            first2=first2->link;
            c=1;
        }
    }while(c);
    temp=first1;
    while(temp->link!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
    return 0;
}
struct node * mergell(struct node *f1,struct node *f2)
{
    struct node *p1,*p2,*pre;
    p1=f1;
    p2=f2;
    if(p1->link==NULL)
    {
        p1->link=f2;
        return f1;
    }
    else if(p2->link==NULL)
    {
        while(p1->data<p2->data)
        {
            if(p1->link!=NULL)
            {
                pre=p1;
                p1=p1->link;
            }
            else
            {
                p1->link=p2;
                return f1;
            }
        }
        if(p1==f1)
        {
            p2->link=p1;
            return p2;
        }
        else if(p1->data<p2->data)
        {
            p1->link=p2;
            return f1;
        }
        pre->link=p2;
        p2->link=p1;
        return f1;
    }
    while((p1->link!=NULL)&&(p2->link!=NULL))
    {
        while(p1->data<p2->data)
        {
            if(p1->link!=NULL)
            {
                pre=p1;
                p1=p1->link;
            }
            else
            {
                p1->link=p2;
                return f1;
            }
        }
        pre->link=p2;
        pre=p2;
        p2=p2->link;
        while(p2->data<p1->data)
        {
            if(p2->link!=NULL)
            {
                pre=p2;
                p2=p2->link;
            }
            else
            {
                p2->link=p1;
                return f1;
            }
        }
        pre->link=p1;
        pre=p1;
        if(p1->link==NULL)
        {
            p1->link=p2;
            return f1;
        }
        p1=p1->link;
    }
    if(p2->link==NULL)
    {
        while(p1->data<p2->data)
        {
            if(p1->link!=NULL)
            {
                pre=p1;
                p1=p1->link;
            }
            else
            {
                    p1->link=p2;
            }
        }
        pre->link=p2;
        p2->link=p1;
        return f1;
    }
    else
    {

    }
    return f1;
};
