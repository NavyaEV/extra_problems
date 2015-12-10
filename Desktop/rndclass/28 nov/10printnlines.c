#include "stdio.h"
int main()
{
    FILE *fp1 = fopen("source.txt", "r");
    FILE *fp2 = fopen("source.txt", "r");
    if((fp1==NULL)||(fp2==NULL))
    {
        printf("error in opening the text file");
        return 1;
    }
    const int Max = 256;
    char line[Max];
    int lcount=0,k;
    printf("Enter k value:");
    scanf("%d",&k);
    while(fgets(line,Max,fp1)!=NULL)
    {
        if(lcount<k)
            lcount++;
        else
        {
            fgets(line,Max,fp2);
        }
    }
    while(fgets(line,Max,fp2)!=NULL)
    {
        printf("%s",line);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
