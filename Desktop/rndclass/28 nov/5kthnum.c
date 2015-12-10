#include<stdio.h>
#include<stdlib.h>
void quicksort(int *,int ,int );
struct eg
{
    int n1,n2,k,num;
}testcase[5]={{3,5,13,27}
};
int main()
{
    int i=0,num;
    num=findnum(&testcase[i]);
    if(num==testcase[i].num)
        printf("Pass");
    else
        printf("Fail");
    return 0;
}
int findnum(struct eg *t)
{
    int c=(t->n1)+(t->n2)-1;
    int x=0,*a,i=-1,temp,m,y;
    a=(int *)malloc(c*sizeof(int));
    while(c<t->k)
    {
        if(x==0)
            x=2;
        c=c*x;
        x++;
    }
    y=c/(x-1);
    if(c==t->k)
        return (x-1)*(t->n1)*(t->n2);
    temp=(t->n1)*(t->n2+1);
    m=t->n2+2;
    while(temp<((t->n1)*(t->n2)*(x-1)))
    {
        a[++i]=temp;
        temp=(t->n1)*m;
        m++;
    }
    temp=(t->n2)*(t->n1+1);
    m=t->n1+2;
    while(temp<((t->n1)*(t->n2)*(x-1)))
    {
        a[++i]=temp;
        temp=(t->n2)*m;
        m++;
    }
    a[++i]=((t->n1)*(t->n2)*(x-1));
    x=(x-2)*((t->n1)+(t->n2)-1);
    while(x<t->k)
    {
        x++;
    }
    quicksort(a,0,(t->n1+t->n2-2));
    return a[x-y-1];
}
void quicksort(int *a,int left,int right)
{
     int p,l,r,t;
     l=left;
     r=right;
     p=a[left];
     while(l<r)
     {
        while((a[r]>=p)&&(l<r))
        r--;
        if(l<r)
        {
            t=a[l];
            a[l]=a[r];
            a[r]=t;
            l++;
        }
        while((a[l]<=p)&&(l<r))
        l++;
        if(l<r)
        {
            t=a[l];
            a[l]=a[r];
            a[r]=t;
            r--;
        }

        if(left<r)
            quicksort(a,left,l);
        if(right>l)
            quicksort(a,l+1,right);
    }
}
