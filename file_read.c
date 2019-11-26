#include<stdio.h>

int main()
{
    FILE *fp;

    printf("Enter File Name to Read: ");
    char filename[30];
    scanf("%s", filename);
    fp = fopen(filename, "r");

    char ch = fgetc(fp);

    while(ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fp);
    }

    fclose(fp);
    return 0;
}

