#include<stdio.h>
#include<string.h>
#include<conio.h>

int main(void)
{
    FILE *fp;
    char teacher_id[30];
    char student_id[30];
    char s_registration[30] = "";
    char student_name[30] = "";
    int position = 30;
    int position2 =90;
    int sr_lenght;
    int sn_lenght;
    fp = fopen("data.txt","r+");
    if (fp==NULL)
    {
        printf("Error");
    }
    int i=1,i2=-1;
    fseek(fp,0,0);
    while (!feof(fp))
    {
        rewind(fp);
        position=(210*i)-180+i2;
        fseek(fp,position,0);
        fgets(s_registration,32,fp);
        printf("Enter the Record for this registration no %s\n",s_registration);
        if (strlen(s_registration)<=0)
            break;
        gets(student_name);
        position2 =(210*i)-120+i2;
        fseek(fp,position2,0);
        fputs(student_name,fp);
        i++;i2++;
        printf("%d",position2);
    }
    fclose(fp);
}

