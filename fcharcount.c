#include<stdio.h>

int main()
{
    FILE *fp;

    printf("Enter File Name: ");
    char filename[30];
    scanf("%s", filename);
    fp = fopen(filename, "r");
    int cnt = 0;
    char ch = fgetc(fp);
    while(ch != EOF)
    {
        if(ch != ' ' && ch != '\n')
            cnt++;
        ch = fgetc(fp);
    }
    printf("Number of characters in %s: %d\n", filename, cnt);
    fclose(fp);
    return 0;
}


