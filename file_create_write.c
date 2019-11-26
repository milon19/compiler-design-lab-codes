#include<stdio.h>

int main()
{
    FILE *fp;
    int i = 0;
    char c;
    printf("Enter File Name to Write : ");
    char filename[30];
    getchar();
    scanf("%s", filename);
    fp = fopen(filename, "w");
    char str[100];
    while((c = getchar()) != EOF)
        str[i++] = c;
    fputs(str, fp);
    fclose(fp);

    return 0;
}
