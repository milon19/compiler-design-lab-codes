#include<stdio.h>
#include<string.h>

int i;
struct Students
{
    char NAME[255];
    char ID[25];
    double CGPA;
};

void home()
{
    printf("\n\n\t\t-----------------------------------------------\n");
    printf("\t\t|\t                                      |\n");
    printf("\t\t|\t1. Press 1 for add new students       |\n");
    printf("\t\t|\t2. Press 2 for view students list     |\n");
    printf("\t\t|\t3. Press 3 for exit                   |\n");
    printf("\t\t|\t                                      |\n");
    printf("\t\t-----------------------------------------------\n\n\n");
    printf("\t\t\t    Enter your choice: ");
}

int main()
{
    int ch;
    home();
    while(scanf("%d", &ch)==1)
    {

        if(ch == 3)
            break;
        else if(ch == 1)
        {
            printf("\t\t\t    Enter number of student: ");
            int ns;
            scanf("%d", &ns);
            getchar();
            struct Students student[ns];
            for(i = 0; i < ns; i++)
            {
                char temp[255];
                printf("\t\t\t    Enter Name of student %d : ", i+1);
                scanf("%[^\n]", temp);
                strcpy(student[i].NAME, temp);
                //printf("%s\n", student[i].NAME);
                getchar();
                printf("\t\t\t    Enter ID of student %d : ", i+1);
                scanf("%s", temp);
                strcpy(student[i].ID, temp);
                //printf("%s\n", student[i].ID);
                printf("\t\t\t    Enter CGPA of student %d : ", i+1);
                scanf("%lf", &student[i].CGPA);
                //printf("%.3lf\n", student[i].CGPA);
                getchar();
                printf("\n\n\t\t\t  *************************************\n");
                printf("\t\t\t      %s is ADDED in LIST.\n", student[i].NAME);
                printf("\t\t\t  *************************************\n\n\n");
            }
            printf("\t\t\t    ALL Students are ADDED in LIST.\n\n\n");
            FILE *fp;
            fp = fopen("student_data.dat", "ab+");

            for(i = 0; i < ns; i++)
            {
                fwrite(&student[i], sizeof(struct Students), 1, fp);
            }
            fclose(fp);
        }

        else
        {
            system("cls");
            FILE *fp;
            struct Students tmp;
            fp = fopen("student_data.dat", "r");
            printf("\n\n\t\tList of all students:\n");
            printf("\n\n\t\t-------------------------------------------------------------------------------\n");
            printf("\t\t|  SL  |                  Name                  |       ID       |    CGPA    |\n");
            printf("\t\t-------------------------------------------------------------------------------\n");
            int sl = 1;
            while(fread(&tmp, sizeof(struct Students), 1, fp))
            {
                int len = strlen(tmp.NAME);
                printf("\t\t|  %02d  |%s", sl++, tmp.NAME);
                for(i = 1; i <= 40-len; i++)
                    printf(" ");
                printf("|%s", tmp.ID);
                len = strlen(tmp.ID);
                for(i = 1; i <= 16-len; i++)
                    printf(" ");
                printf("|%.03lf       |\n", tmp.CGPA);
                printf("\t\t-------------------------------------------------------------------------------\n");
            }
                //printf("Name = %s ID = %s CGPA = %.3lf\n", tmp.NAME, tmp.ID, tmp.CGPA);
            fclose(fp);
        }
        printf("continue...\n");
        home();
    }

    return 0;
}
