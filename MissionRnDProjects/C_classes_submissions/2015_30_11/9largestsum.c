#include<stdio.h>
#include<stdlib.h>
struct eg
{
    int a[100],n,l;
}testcase[5]={{{1,2,3,5,-10,20,40},7,2},{{5,7,-1,6,9,-10,30},7,1}
};
int main()
{
    int l,i;
    for(i=0;i<2;i++)
    {
        l=largest(&testcase[i]);
        if(l==testcase[i].l)
            printf("Pass\n");
        else
            printf("Fail\n");
    }
    return 0;
}
int largest(struct eg *t)
{
    int **a,m=0,x,y,i,j;
    a=(int **)malloc(sizeof(int *)*t->n);
    for(i=0;i<t->n;i++)
    {
        a[i]=(int *)malloc(sizeof(int)*t->n);
        for(j=0;j<t->n;j++)
        {
            a[i][j]=t->a[i]+t->a[j];
            if(m<a[i][j])
            {
                m=a[i][j];
                x=i;y=j;
            }
        }
    }
    while(a[x-2][y]<a[x-1][y])
    {
        x--;
    }
    return y-x+1;
}
