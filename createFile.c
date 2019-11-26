#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp;
    printf("Enter File Name: ");
    char filename[30];
    scanf("%s", filename);
    fp = fopen(filename, "w");
    fclose(fp);

    return 0;
}

