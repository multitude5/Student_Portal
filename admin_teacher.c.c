#include<stdio.h>
#include<string.h>
#include<conio.h>

int main(void)
{
    FILE *fp;
    int t_lenght,position;
    int m_subject,n_student;
    int l=0;
    char teacher_id[30];
    char student_id[30];
    char subject[30];
    char batch[5]="";
    char degree[5]="";

    char dump3[5]="";
    int teacher_pas;
    fp = fopen("data.txt","w");
    if (fp==NULL)
    {
        printf("Error");
    }
    printf("\nHow many student you want to Register in this class: ");
    scanf("%d",&n_student);
    fflush(stdin);
    printf("\nEnter batch of Students: ");
    scanf("%s",batch);
    fflush(stdin);
    printf("\nEnter degree: ");
    scanf("%s",degree);
    fflush(stdin);
    printf("\nEnter the maximum no of subject: ");
    scanf("%d",&m_subject);
    fflush(stdin);
    fseek(fp,0,2);
    while (l<m_subject)
    {
        int n,k,i;
        printf("\nEnter the Teacher id: ");
        scanf("%s",teacher_id);
        fflush(stdin);
        printf("\nName of subject this teacher is teaching: ");
        gets(subject);
        fflush(stdin);
        t_lenght = 59-strlen(teacher_id);//This line is for finding the last bytes of string out of 30
        position = strlen(teacher_id); // This line is for finding the
        position = position+t_lenght;
        for (k=1;k<=n_student;k++)
        {
            char roll_no[5]="";
            char dump[5]="00";
            char dump1[5]="0";
            itoa(k,roll_no,10);
            if (strlen(roll_no)==1)
            {
                strcat(dump,roll_no);
                strcpy(roll_no,"");
                strcpy(roll_no,dump);
            }
            else if (strlen(roll_no)==2)
            {
                strcat(dump1,roll_no);
                strcpy(roll_no,dump1);
            }
            strcat(strcat(strcat(strcat(strcpy(student_id,batch),"-"),degree),"-"),roll_no);
            printf("%s",student_id);
            fputs(teacher_id,fp);
            position = ftell(fp)+t_lenght;
            fseek(fp,position,0);
            position = position+30;
            fputs(student_id,fp);
            fseek(fp,position,0);
            fputs(subject,fp);
            fseek(fp,position+150,0);
            fputs("\n",fp);
        }
        l++;
        if (m_subject==l)
        {
            for (i=0;i<235;i++)
            {
                fputs("0",fp);
            }
            itoa(n_student,dump3,10);
            fputs(dump3,fp);
        }

    }
        fclose(fp);
}
