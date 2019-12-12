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
    int position;
    int position2;
    int sr_lenght;
    int sn_lenght;
    fp = fopen("data.txt","r+");
    if (fp==NULL)
    {
        printf("Error");
    }
    int i=1,i2=-1,j;
    char c;
    while (1)
    {
        rewind(fp);
        position2 =(210*i)-120+i2;
        fseek(fp,position2,0);
        fgets(student_name,2,fp);
        if (student_name[0]!="0")
        {
            i++;i2++;
        }
        else
        {
            i++;i2++;
            break;
        }

    }
}
