#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x, int y);
int main(void)
{
    FILE *fp;
    int x,y;
    char dump[3];
    char t_id[15]="ifthar@cui.com";
    char s_registration[15];
    char student_r[20];
    char studen_name[20];
    char attadence[1];
    char marks[5];
    fp = fopen("data.txt","r+");
    int position;
    if (fp==NULL)
    {
        printf("Error");
    }
    fseek(fp,0,0);
    int n,n2,n_a;;
    fscanf(fp,"%d %d %d",&n,&n2,&n_a);
    int s_number = n;
    int i=2,i2=1;
    int dum=0;
    while (1)
    {
        rewind(fp);
        position=(280*i)-280+i2;
        fseek(fp,position,0);
        fgets(s_registration,15,fp);
        //printf("%d",s_registration);
        if (!strcmp(t_id,s_registration))
        {
            int dum1= i;
            int dum2=--i2;
            //printf("%d",dum2);
            int k;
            gotoxy(40,1);
            printf("Press One For Attendance");
            gotoxy(35,2);
            printf("Press Two For Entering Marks\n");
            gotoxy(39,3);
            scanf("%d",&k);
            if (k==1)
            {
                printf("Enter Attendance\n");
                printf("NAME                                         REGISTRATION NO       ATTEDENDANCE");
                while (1)
                {
                    rewind(fp);
                    position=(280*i)-280+(i2+1);
                    fseek(fp,position,0);
                    fgets(s_registration,15,fp);
                    if (strcmp(t_id,s_registration))
                    {
                        break;
                    }
                    position=(280*i)-240+i2;
                    fseek(fp,position,0);
                    fgets(student_r,20,fp);
                    position=(280*i)-179+i2;
                    fseek(fp,position,0);
                    fgets(studen_name,20,fp);
                    printf("\n%-45s%-25s",studen_name,student_r);
                    position=(280*i)-n_a+i2;
                    scanf("%s",attadence);
                    fseek(fp,position,0);
                    fputs(attadence,fp);
                    i++;i2++;
                }
                system("cls");
                n_a -=2;
                rewind(fp);
                fprintf(fp,"%d %d %d",n,n2,n_a);
                break;
            }
            else if (k=2)
            {
                int m;


                printf("Enter the marks!");
                int s=1;
                while (1)
                {
                    rewind(fp);
                    position=(280*i)-280+(i2+1);
                    fseek(fp,position,0);
                    fgets(s_registration,15,fp);
                    if (strcmp(t_id,s_registration))
                    {
                        break;
                    }
                    position=(280*i)-240+i2;
                    fseek(fp,position,0);
                    fgets(student_r,20,fp);
                    position=(280*i)-179+i2;
                    fseek(fp,position,0);
                    fgets(studen_name,20,fp);
                    printf("\n%-2d %-45s%-25s",s,studen_name,student_r);
                    s++;i++;i2++;

                }
                printf("Enter the Number:");
                scanf("%d",&s);
                i2 = dum2+s;
                i = dum1+s;
                dum1 = 152;
                for (m=1;m<5;m++)
                {
                    printf("\nAssignment#%-15d",m);
                    position=(280*i)-dum1+i2;
                    fseek(fp,position,0);
                    scanf("%s",marks);
                    fprintf(fp,"%s",marks);
                    dum1-=8;
                }
                for (m=1;m<5;m++)
                {
                    printf("\nQuiz#%-15d",m);
                    position=(280*i)-dum1+i2;
                    fseek(fp,position,0);
                    scanf("%s",marks);
                    fprintf(fp,"%s",marks);
                    dum1-=8;
                }
                for (m=1;m<3;m++)
                {
                    printf("\nSessional#%-15d",m);
                    position=(280*i)-dum1+i2;
                    fseek(fp,position,0);
                    scanf("%s",marks);
                    fprintf(fp,"%s",marks);
                    dum1-=8;
                }
                printf("Terminals");
                position=(280*i)-dum1+i2;
                fseek(fp,position,0);
                scanf("%s",marks);
                fprintf(fp,"%s",marks);
            }
            break;
        }
        else if (s_registration[0]=='0')
        {
            break;
        }
        i++;i2++;dum++;
    }
}




void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
