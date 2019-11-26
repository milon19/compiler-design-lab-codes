#include<stdio.h>

int main()
{
    FILE *fp;
    int i, j = 0;
    fp = fopen("text.txt", "r");
    char txt[1000];
    char ch = fgetc(fp);
    while(ch != EOF)
    {
        txt[j++] = ch;
        ch = fgetc(fp);
    }
    for(i = 0; txt[i] != '\0';)
    {
        if(txt[i]=='/' && txt[i+1] == '/')
        {
            while(txt[i] != '\n')
                printf("%c", txt[i++]);
            printf("\n");
        }
        else if(txt[i]=='/' && txt[i+1] == '*')
        {
            while(txt[i+1]!='/')
                printf("%c", txt[i++]);
            printf("%c", txt[i++]);
            printf("%c", txt[i++]);
            printf("\n");
        }

        else
        {
            i++;
        }
    }
    fclose(fp);

    return 0;
}

