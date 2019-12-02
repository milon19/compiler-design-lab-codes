/*
if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u')
{
    printf("%c is Vowel", ch);
}
*/
#include<stdio.h>
#include<string.h>

int i, j;

int main()
{
    char code[1000], ch;

    while((ch = getchar())!=EOF)
    {
        code[i++] = ch;
    }
    code[i] = '\0';

    for(i = 0; code[i] != '\0'; i++)
        if(code[i] == '\n')
            code[i] = ' ';
    for(i = 1; code[i] != '\0'; i++)
    {
        while(code[i-1] == ' ' && code[i] == ' ')
        {
            for(j = i-1; code[j] != '\0'; j++)
                code[j] = code[j+1];
        }
    }
    printf("Input after remove white space: \n");
    printf("%s\n", code);
    char con[1000], block[1000];
    for(i = 0; code[i] != '\0';)
    {
        if(code[i] == 'i' && code[i+1] == 'f')
        {
            printf("%c%c\n", code[i], code[i+1]);
            i+=2;
            continue;
        }
        if(code[i] == '(')
        {
            j = 0;
            while(code[i] != ')')
            {
                con[j++] = code[i++];
            }
            con[j++] = code[i++];
            con[j] = '\0';
            //printf("%s\n", con);
            i = j+2;
            continue;
        }
        if(code[i] == '{')
        {
            j = 0;
            while(code[i] != '}')
            {
                if(code[i] == '\0')
                    break;
                block[j++] = code[i++];
            }
            block[j++] = code[i];
            block[j] = '\0';
            //printf("%s\n", block);
            i = j;
            break;
        }
        i++;
    }
    for(i = 0; con[i] != '\0'; i++)
    {

        if(con[i] == ' ')
            printf("\n");
        else
        {
            if(con[i] == '(')
            {
                printf("%c", con[i]);
                printf("\n");
            }
            else if(con[i] == ')')
            {
                printf("\n");
                printf("%c", con[i]);
            }
            else
            {
                printf("%c", con[i]);
            }
        }
    }
    printf("\n");
    for(i = 0; block[i] != '\0'; i++)
    {

        if(block[i] == '(' || block[i] == '{')
        {
            printf("\n");
            printf("%c", block[i]);
            printf("\n");
        }
        else if(block[i] == ',')
        {
            printf("\n");
            printf("%c", block[i]);
            printf("\n");
        }
        else if(block[i] == ')' || block[i] == '}')
        {
            printf("\n");
            printf("%c", block[i]);
            printf("\n");
        }
        else
        {
            printf("%c", block[i]);
        }
    }
    printf("\n");
    return 0;
}
