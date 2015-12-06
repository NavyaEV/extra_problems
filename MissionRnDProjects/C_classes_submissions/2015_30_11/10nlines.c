#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *in,*out;
    int c=0,k;
    long int pos;
    char s[100];
    in=fopen("source.txt", "r");
    printf("Enter k value:");
    scanf("%d",&k);
    if(in==NULL)
    {
        perror("error to open file");
        exit(EXIT_FAILURE);
    }
    out=fopen("dest.txt", "w");
    if(out==NULL)
    {
        perror("error to open destination file");
        exit(EXIT_FAILURE);
    }
    fseek(in,0,SEEK_END);
    pos=ftell(in);
    while(pos)
    {
        fseek(in,--pos,SEEK_SET);
        if(fgetc(in)=='\n')
        {
            if(c++==k)
                break;
        }
    }
    while(fgets(s,sizeof(s),in)!=NULL)
    {
        fprintf(out,"%s",s);
    }
    fclose(in);
    fclose(out);
    return 0;
}
