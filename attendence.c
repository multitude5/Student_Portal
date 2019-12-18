#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x, int y);
void fnmarks(FILE *FP,int i,int dum1);
void Psubject(FILE *FP, int i, int i2);
void printtitle(char *ptrs);
void printbox(void);
int main(void)
{
    FILE *fp;
    int x,y;
    char dump[3];
    char t_id[30];
    char password[10];
    char teacher_id[40]="akzar@cui.com398u2t";
    char cteacher_id[40];
    char student_reg[20];
    char studen_name[20];
    char attadence[1];
    char marks[5];
    char subject[30];
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
    int i=2,i2=0;
    int dum=0;
    printbox();
    gotoxy(25,7);
    scanf("%s",t_id);
    gotoxy(25,9);
    scanf("%s",password);
    system("cls");
    while (1)
    {
        rewind(fp);
        position=(280*i)-280+i2;
        fseek(fp,position,0);
        fscanf(fp,"%s ",cteacher_id);
        if (!strnicmp(teacher_id,cteacher_id,strlen(cteacher_id)))
        {
            int dum1= i;
            int dum2=i2;
            int k;
            char *name = strupr(strtok(cteacher_id,"@"));
            printtitle(name);
            gotoxy(18,7);
            printf("Press One For Attendance");
            gotoxy(16,9);
            printf("Press Two For Entering Marks\n");
            gotoxy(28,11);
            scanf("%d",&k);
            system("cls");
            if (k==1)
            {
                Psubject(fp,i,i2);
                printf("NAME                                         REGISTRATION NO       ATTEDENDANCE");
                for (s_number=n;s_number>0;s_number--)
                {
                    rewind(fp);
                    position=(280*i)-240+i2;
                    fseek(fp,position,0);
                    fgets(student_reg,20,fp);
                    position=(280*i)-179+i2;
                    fseek(fp,position,0);
                    fgets(studen_name,20,fp);
                    printf("\n%-45s%-25s",studen_name,student_reg);
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


                printf("Choose the Number Below!\n_____________________________________________________________\n\n");
                int s=1;
                for (s_number=n;s_number>0;s_number--)
                {
                    rewind(fp);
                    position=(280*i)-240+i2;
                    fseek(fp,position,0);
                    fgets(student_reg,20,fp);
                    position=(280*i)-179+i2;
                    fseek(fp,position,0);
                    fgets(studen_name,20,fp);
                    printf("%-2d %-45s%-25s\n",s,studen_name,student_reg);
                    s++;i++;i2++;

                }
                printf("_____________________________________________________________\n");
                gotoxy(30,14);
                scanf("%d",&s);
                system("cls");
                i2 = dum2+s;
                i = dum1+s-1;
                dum1 = 152;
                printf("\nEnter Marks (0-10)!");
                for (m=1;m<5;m++,k)
                {
                    printf("\nAssignment#%d             |",m);
                    fnmarks(fp,i,dum1);
                    dum1-=8;
                }
                printf("\nEnter Marks (0-15)!");
                for (m=1;m<5;m++)
                {
                    printf("\nQuiz#%d                   |",m);
                    fnmarks(fp,i,dum1);
                    dum1-=8;
                }
                printf("\nEnter Marks (0-25)!");
                for (m=1;m<3;m++)
                {
                    printf("\nSessional#%d              |",m);
                    fnmarks(fp,i,dum1);
                    dum1-=8;
                }
                printf("\nEnter Marks (0-50)!");
                printf("\nTerminals                |");
                fnmarks(fp,i,dum1);
            }
            break;
        }
        else if (cteacher_id[0]=='0')
        {
            printf("Record Not Found!");
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


void fnmarks(FILE *FP,int i,int dum1)
{
    int position;
    char marks[5];
    position=(280*i)-dum1+i+1;
    fseek(FP,position,0);
    scanf("%s",marks);
    fprintf(FP,"%s",marks);
}

void Psubject(FILE *FP, int i, int i2)
{
    int position;
    char subject[40];
    position=(280*i)-220+i2;
    fseek(FP,position,0);
    fgets(subject,40,FP);
    printf("SUBJECT: %s\n\n",strupr(subject));
}



void printtitle(char *ptrs)
{
    printf("                ___________________________               \n\n");
    printf("                           %s                               \n",ptrs);
    printf("                ___________________________                 ");
}




void printbox(void)
{
    gotoxy(15,5);
    printf("* * * * * * * * * * * * * * * * * \n");
    gotoxy(15,6);
    printf("* USERNAME:                    *\n");
    gotoxy(15,7);
    printf("*                               *\n");
    gotoxy(15,8);
    printf("* PASSWORD:                     *\n");
    gotoxy(15,9);
    printf("*                               *\n");
    gotoxy(15,10);
    printf("* * * * * * * * * * * * * * * * * \n");

}
