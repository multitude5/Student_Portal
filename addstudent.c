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
    int n1,n2;
    fp = fopen("data.txt","r+");
    if (fp==NULL)
    {
        printf("Error");
    }
    fseek(fp,0,0);
    fscanf(fp,"%d %d",&n1,&n2);
    printf("%d \n%d",n1,n2);
    int s_number = n1;
    int n;
    int number2= n2;
    int i=2,i2=1;
    while (s_number>0)
    {
        rewind(fp);
        position=(210*i)-170+i2;
        fseek(fp,position,0);
        printf("%d",ftell(fp));
        fgets(s_registration,20,fp);

        printf("\nEnter the Record for this registration no %s: ",s_registration);
        gets(student_name);
        n=0;
        for (number2=n2;number2>0;number2--)
        {
            position3 =(210*(i+n))-100+(i2+n);
            fseek(fp,position3,0);
            fputs(student_name,fp);
            n = n1+n;
        }
        i++;i2++;
        s_number--;
    }
    fclose(fp);
}
