#include<stdio.h>
#include<string.h>
int i;
struct Students
{
    char name[100];
    char id[20];
    double cgpa;
};
int main()
{
    printf("Enter number of student: ");
    int n;
    scanf("%d", &n);
    getchar();
    struct Students std[n];
    for(i = 0; i < n; i++)
    {
        char tmp[100];
        printf("Name: ");
        scanf("%[^\n]", tmp);
        getchar();
        strcpy(std[i].name, tmp);
        printf("ID: ");
        scanf("%[^\n]", tmp);
        getchar();
        strcpy(std[i].id, tmp);
        printf("CGPA: ");
        scanf("%lf", &std[i].cgpa);
        getchar();
    }

    FILE *fp;
    fp = fopen("info.txt", "ab+");
    for(i = 0; i < n; i++)
        fwrite(&std[i], sizeof(struct Students), 1, fp);
    fclose(fp);
    struct Students tmp;
    fp = fopen("info.txt", "r");
    i = 1;
    printf("Total students:  \n\n");
    while(fread(&tmp, sizeof(struct Students), 1, fp))
    {
        printf("%d-> %s %lf\n",i++, tmp.id, tmp.cgpa);
    }
    fclose(fp);
    fp = fopen("info.txt", "r");
    i = 1;
    printf("students CGPA >= 3.25:  \n\n");
    while(fread(&tmp, sizeof(struct Students), 1, fp))
    {
        if(tmp.cgpa >= 3.25)
            printf("%d-> %s\n",i++, tmp.id);
    }
    fclose(fp);
    return 0;
}
