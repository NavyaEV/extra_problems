#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
float findmedian(struct node *);
typedef struct node NODE;
NODE *reversell(NODE *,NODE *,int );
int main()
{
    NODE *head,*temp=0,*first=0;
    int choice;
    float median;
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
    median=findmedian(first);
    printf("Median is %f",median);
    return 0;
}
float findmedian(struct node *first)
{
    NODE *ptr1;
    int c=0;
    float median;
    ptr1=first;
    while(ptr1->link!=NULL)
    {
        c++;
        ptr1=ptr1->link;
    }
    if(c==0)
    {
        median=first->data;
        return median;
    }
    else
    {
        if((c%2)==0)
        {
            c=c/2;
            ptr1=first;
            while(c>0)
            {
                ptr1=ptr1->link;
                c--;
            }
            median=ptr1->data;
            return median;
        }
        else
        {
            c=c/2;
            ptr1=first;
            if(c==0)
            {
                median=ptr1->data;
                ptr1=ptr1->link;
                median+=ptr1->data;
                median=median/2;
                return median;
            }
            while(c>0)
            {
                ptr1=ptr1->link;
                c--;
            }
            median=ptr1->data;
            ptr1=ptr1->link;
            median+=ptr1->data;
            median=median/2;
            return median;
        }
    }
}
