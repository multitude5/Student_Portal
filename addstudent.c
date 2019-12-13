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
    int position3;
    int sr_lenght;
    int sn_lenght;
    char dump[3];
    fp = fopen("data.txt","r+");
    if (fp==NULL)
    {
        printf("Error");
    }
    fseek(fp,-2,2);
    fgets(dump,3,fp);
	int n = atoi(dump);
    printf("%d",n);
    int number = n;
    int i=1,i2=-1;
    while (number>0)
    {
        rewind(fp);
        position=(220*i)-180+i2;
        fseek(fp,position,0);
        fgets(s_registration,30,fp);
                if (s_registration[0]=='0')
        {
            break;
        }
        printf("Enter the Record for this registration no %s\n",s_registration);
        gets(student_name);
        position2 =(220*i)-120+i2;
        fseek(fp,position2,0);
        fputs(student_name,fp);
        position3 =(220*(i+n))-120+(i2+n);
        fseek(fp,position3,0);
        fputs(student_name,fp);
        i++;i2++;
        number--;
        //printf("%d",position2);
    }
    fclose(fp);
}
