#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void addteacher();
void addstudentrecord();
void addingQuiz();
void attempquiz();
void deleterecord();
void printtitle(char *ptrs,int x,int y);
void gotoxy(int x, int y);
void fnmarks(FILE *FP,int i,int dum1);
void Psubject(FILE *FP, int i, int i2);
void printbox(void);
void teacherlogin(void);

typedef struct                              //structure for the quiz//
{
    char question [40];
    char option [20];
    char answer [3] ;

}quiz_t;



int main(void)
{

    int i,j;
    printtitle("WELCOME",0,0);
    gotoxy(20,7);
    printf("Three For Student Login\n");
    gotoxy(21,9);
    printf("Two For Teacher Login\n");
    gotoxy(22,11);
    printf("One For Admin Login\n");

    gotoxy(30,13);
    scanf("%d",&i);

    //Sleep(1000);
    system("cls");
    if (i==1)
    {
        while(1)
        {
            printtitle("ADMIN",0,0);
            gotoxy(2,5);
            printf("1) Create Teacher Account\n");
            gotoxy(2,7);
            printf("2) Add Student Data\n");
            gotoxy(2,9);
            printf("3) Delete Student Record\n");
            gotoxy(2,11);
            printf("0) Exit");
            printf("\n_____________________________________________________________\n");
            gotoxy(30,14);
            scanf("%d",&j);
            system("cls");
            if (j==1)
                addteacher();
            if (j==2)
                addstudentrecord();
            if (j==3)
                deleterecord();
            if (j==0)
                break;
            system("cls");
        }

    }
    else if (i==2)
    {
        teacherlogin();
    }
    else if (i==3)
    {
        attempquiz();
    }
}




void addteacher(void)
{
    FILE *fp;
    int t_lenght,position;
    int m_subject,n_student;
    int i;
    char teacher_id[40];
    char regno_student[20];
    char course_titile[40];
    char batch[5]="";
    char degree[5]="";
    char dump3[5]="";
    char dump4[5]="";
    char credit[2];
    char teacher_pas[8];
    int count;
    fp = fopen("data.txt","w");
    if (fp==NULL)
    {
        printf("Error");
    }
    printf("\nNo of Students: ");
    scanf("%d",&n_student);
    fflush(stdin);
    printf("\nBatch: ");
    scanf("%s",batch);
    fflush(stdin);
    printf("\nDegree: ");
    scanf("%s",degree);
    fflush(stdin);
    printf("\nNO of Courses: ");
    scanf("%d",&m_subject);
    fflush(stdin);
    fprintf(fp,"%d %d %d",n_student,m_subject,60);
    count = 279-ftell(fp);
    fseek(fp,count,1);
    fputs("\n",fp);
    while (m_subject>0)
    {
        int n,k,i;
        printf("\nTeacher ID: ");
        scanf("%s",teacher_id);
        fflush(stdin);
        printf("\nPassword: ");
        scanf("%s",teacher_pas);
        fflush(stdin);
        printf("\nCourse Title: ");
        gets(course_titile);
        fflush(stdin);
        printf("\nCredit: ");
        scanf("%d",&i);
        fflush(stdin);
        itoa(i,credit,10);
        t_lenght = 24-strlen(teacher_id);//This line is for finding the last bytes of string out of 30
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
            strcat(strcat(strcat(strcat(strcpy(regno_student,batch),"-"),degree),"-"),roll_no);
            printf("%s\n",regno_student);
            fputs(teacher_id,fp);

            position = ftell(fp)+t_lenght;

            fseek(fp,position,0);
            fputs(teacher_pas,fp);
            fseek(fp,position+15,0);
            fputs(regno_student,fp);
            position = position+40;
            fseek(fp,position,0);
            fputs(course_titile,fp);
            position = position+110;
            fseek(fp,position,0);
            fputs(credit,fp);
            fseek(fp,position+105,0);
            fputs("\n",fp);
        }
        m_subject--;
    }
    for (i=279;i>0;i--)
    {
        fputs("0",fp);
    }
    fclose(fp);
}

void deleterecord(void)
{
    FILE *fp;
    char student_reg[30] = "";
    char student_name[30] = "";
    int position,n1,n2;
    FILE *fileptr1;
    char ch='A';
    int delete_line, temp = 0;
    fp = fopen("data.txt","r+");
    if (fp==NULL)
    {
        printf("Error");
    }
    fseek(fp,0,0);
    fscanf(fp,"%d %d",&n1,&n2);
    int s_number = n1;
    int i=2,i2=0;
    printf("Enter Number to Delete the Record!\n_____________________________________________________________\n\n");
    int s=1;
    for (s_number=n1;s_number>0;s_number--)
    {
        rewind(fp);
        position=(280*i)-240+i2;
        fseek(fp,position,0);
        fgets(student_reg,20,fp);
        position=(280*i)-179+i2;
        fseek(fp,position,0);
        fgets(student_name,20,fp);
        printf("%-2d %-45s%-25s\n",s,student_name,student_reg);
        i++;i2++;s++;
    }
    printf("_____________________________________________________________\n");
    gotoxy(30,14);
    rewind(fp);
    do
    {
      scanf("%d",&delete_line);
    }while (delete_line<0 || delete_line>n1);
    fileptr1 = fopen("replica.txt", "w");
    while (ch != EOF)
    {
        ch = getc(fp);
        if (temp != delete_line)
        {
            putc(ch, fileptr1);
        }
        if (ch == '\n')
        {
            if (temp==delete_line)
            {
                delete_line+=n1;
            }
            temp++;
        }
    }
    rewind(fp);
    system("cls");
    printtitle("REORD DELETED",0,7);
    Sleep(3000);
    n1--;
    rewind(fileptr1);
    fprintf(fileptr1,"%d %d",n1,n2);
    fclose(fp);
    fclose(fileptr1);
    remove("data.txt");
    rename("replica.txt","data.txt");

}


void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}



// Start of Student Data Entrance Function
void addstudentrecord(void)
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
    int s_number = n1;
    int n;
    int number2= n2;
    int i=2,i2=1;
    while (s_number>0)
    {
        rewind(fp);
        position=(280*i)-241+i2;
        fseek(fp,position,0);
        fscanf(fp,"%s ",s_registration);

        printf("\nEnter the Name for this registration no %s:",strupr(s_registration));
        gets(student_name);
        n=0;
        for (number2=n2;number2>0;number2--)
        {
            position3 =(280*(i+n))-180+(i2+n);
            fseek(fp,position3,0);
            fputs(student_name,fp);
            n = n1+n;
        }
        i++;i2++;
        s_number--;
    }
    fclose(fp);

}

//Start of the quiz creating function for teacher




// Starts of quizs attempting function
void attempquiz(FILE *fp)
{
    FILE *prt ;
    char t_quize[5];
    char option[5];
    int count = 0;
    int total_quizs;
    quiz_t attempt;
    if ((prt = fopen("quiz1.txt","r")) == NULL)
        printf("Failed to open the File");

    fgets(t_quize,5,prt);

    for (int i = 0 ; i < total_quizs ; i++ )
    {
        fgets(attempt.question,40,prt);
        printf("%s\n",attempt.question);

        for (int o=0 ; o < 4 ; o++ )
        {
            fgets(attempt.option,20,prt);
            printf("%d)%s",o+1,attempt.option);
        }
        printf("\nEnter the correct option number : ");
        gets(option);                                       /* Taking option from the student*/
        fgets(attempt.answer,5,prt);
        printf("%s",attempt.option);
        strcat(option,"\n");


        if (!strcmp(option,attempt.answer))                 /*Checking if the user option is correct or wrong*/
        {
            printf("Correct\n\n\n");
            count += 1 ;
        }
        else
            printf("Wrong\n\n\n");



    }
    printf("The correct answers %d",count);


}


void printtitle(char *ptrs,int x,int y)
{
    gotoxy(x,y);
    printf("                ______________________________               \n\n");
    gotoxy(x,y+1);
    printf("                           %s                               \n",ptrs);
    gotoxy(x,y+2);
    printf("                ______________________________                 ");
}


void fnmarks(FILE *FP,int i,int dum1)
{
    int position;
    char marks[2];
    int mark;
    position=(280*i)-dum1+i+1;
    fseek(FP,position,0);
    do
    {
        scanf("%d",&mark);
    }while (mark<0 || mark>99);
    itoa(mark,marks,10);
    fprintf(FP,"%s",marks);
}

void Psubject(FILE *FP, int i, int i2)
{
    int position;
    char subject[40];
    position=(280*i)-215+i2;
    fseek(FP,position,0);
    fgets(subject,40,FP);
    printf("SUBJECT: %s\n\n",strupr(subject));
}




void printbox(void)
{
    gotoxy(15,5);
    printf("* * * * * * * * * * * * * * * * * \n");
    gotoxy(15,6);
    printf("* USERNAME:                     *\n");
    gotoxy(15,7);
    printf("*                               *\n");
    gotoxy(15,8);
    printf("* PASSWORD:                     *\n");
    gotoxy(15,9);
    printf("* * * * * * * * * * * * * * * * * \n");

}

void regname(FILE *fp,int i,int s)
{
    char student_reg[20];
    char studen_name[20];
    int position=(280*i)-240+i-2;
    rewind(fp);
    fseek(fp,position,0);
    fgets(student_reg,20,fp);
    position=(280*i)-179+i-2;
    fseek(fp,position,0);
    fgets(studen_name,20,fp);
    printf("%-3d%-45s%-25s",s,studen_name,strupr(student_reg));
}

void teacherlogin(void)
{
    FILE *fp;
    int x,y;
    char dump[3];
    char t_id[30]="ifthar@cuilahore.edu.pk";
    char password[9]="1A2B3C4D3";
    char pass[30];
    char cteacher_id[30];
    char student_reg[20];
    char studen_name[20];
    char attadence[1];
    char marks[5];
    char subject[30];
    char dum1[1]="A";
    char dum2[1]="P";
    fp = fopen("data.txt","r+");
    int position;
    if (fp==NULL)
    {
        printf("Error");
    }
    fseek(fp,0,0);
    int n1,n2,n_a;;
    fscanf(fp,"%d %d %d",&n1,&n2,&n_a);
    int s_number = n1;
    int count =n1*n2;
    int i=2,i2=0;
    int dum=0;
    /*printbox();
    gotoxy(26,6);
    scanf("%s",t_id);
    gotoxy(26,8);
    scanf("%s",password);
    */system("cls");
    char teacher_id[30];
    strcpy(teacher_id,t_id);
    while (count>0)
    {
        rewind(fp);
        position=(280*i)-280+i2;
        fseek(fp,position,0);
        fscanf(fp,"%s",cteacher_id);
        int dum1= i;
        int dum2=i2;
        if (!strnicmp(cteacher_id,teacher_id,strlen(cteacher_id)))
        {

            int k;
            position=(280*i)-265+i2;
            fseek(fp,position,0);
            fscanf(fp,"%s",pass);
            if (strcmp(pass,password))
            {

                char *name = strupr(strtok(cteacher_id,"@"));
                printtitle(name,0,2);
                gotoxy(18,7);
                printf("Press One For Attendance");
                gotoxy(16,9);
                printf("Press Two For Entering Marks\n");
                gotoxy(15,11);
                printf("Press Three To Change Password\n");
                gotoxy(16,13);
                printf("Press Four For creating Quiz\n");
                gotoxy(28,15);
                scanf("%d",&k);
                system("cls");
                if (k==1)
                {
                    Psubject(fp,i,i2);
                    int day = (60-n_a)/2;
                    printf("Attendance Day: %d\n\n",day);
                    printf("Please Enter P and A only!\n");
                    printf("   NAME                                         REGISTRATION NO       ATTEDENDANCE\n");
                    int s=1;
                    for (s_number=n1;s_number>0;s_number--)
                    {
                        regname(fp,i,s);

                        position=(280*i)-n_a+i2;
                        do
                        {scanf("%s",attadence);
                        if (strlen(attadence)>1 )
                            printf("\nEnter P and A only!");
                        }while (strlen(attadence)>1);
                        fseek(fp,position,0);
                        fputs(attadence,fp);
                        i++;i2++;s++;
                    }
                    system("cls");
                    n_a -=2;
                    rewind(fp);
                    fprintf(fp,"%d %d %d",n1,n2,n_a);
                    break;
                }
                if (k==2)
                {
                    int m;
                    printf("Choose the Number Below!\n_____________________________________________________________\n\n");
                    int s=1;
                    for (s_number=n1;s_number>0;s_number--)
                    {
                        regname(fp,i,s);
                        printf("\n");
                        s++;i++;i2++;
                    }
                    printf("\n_____________________________________________________________\n");
                    gotoxy(30,0);
                    do
                    {
                        scanf("%d",&s);
                    }while (s<0 || s>n1+1);
                    system("cls");
                    i2 = dum2+s;
                    i = dum1+s-1;
                    dum1 = 106;
                    printf("\nEnter Marks (0-10)!");
                    for (m=1;m<5;m++,k)
                    {
                        printf("\nAssignment#%d             |",m);
                        fnmarks(fp,i,dum1);
                        dum1-=3;
                    }
                    printf("\nEnter Marks (0-15)!");
                    for (m=1;m<5;m++)
                    {
                        printf("\nQuiz#%d                   |",m);
                        fnmarks(fp,i,dum1);
                        dum1-=3;
                    }
                    printf("\nEnter Marks (0-25)!");
                    for (m=1;m<3;m++)
                    {
                        printf("\nSessional#%d              |",m);
                        fnmarks(fp,i,dum1);
                        dum1-=3;
                    }
                    printf("\nEnter Marks (0-50)!");
                    printf("\nTerminals                |");
                    fnmarks(fp,i,dum1);
                    system("cls");
                    break;
                }
                if (k==3)
                {

                    printf("Caution! \nTo Avoid Over Right Password Put Extra Spaces\nof not more than 10 character\n");
                    printf("Enter New Password: ");
                    scanf("%s",pass);
                    for (s_number=n1;s_number>0;s_number--)
                    {
                    position=(280*i)-255+i2;
                    fseek(fp,position,0);
                    fputs(pass,fp);
                    i++;i2++;
                }
                //system("cls");
                if (k==4)
                {


    int total_quizs ;
    char quizzz[5];

    FILE *ptr;
    if ((ptr = fopen("quiz1.txt","w")) == NULL )
        printf("File does not exist");

    printf("Enter no of quiz questions : ");
    scanf("%d",&total_quizs);

    printf("\n\n\n");

    itoa(total_quizs,quizzz,10);
    fputs(quizzz,ptr);
    quiz_t quiz;
    fputs("\n",ptr);

    for ( int i = 0 ; i < total_quizs ; i++)
    {
        printf("\n\nEnter the %d question of quiz :  ",i+1);
        fflush(stdin);
        gets(quiz.question);
        fputs(quiz.question,ptr);
        fputs("\n",ptr);

        for ( int o = 0 ; o < 4 ; o++ )
        {
            printf("\nEnter the %d option for the question %d : ",o+1,i+1);
            fflush(stdin);
            gets(quiz.option);
            fputs(quiz.option,ptr);
            fputs("\n",ptr);
        }

        printf("\nEnter the correct option number of question %d : ",i+1);
        fflush(stdin);
        gets(quiz.answer);
        fputs(quiz.answer,ptr);
        fputs("\n",ptr);
    }
    fclose(ptr);

                }
                }
                system("cls");
            }
            else
            {
                printf("Wrong Password");
                break;
            }

        }
        else if (count==0)
        {
            printf("Invalid User-name!");
        }
        i++;i2++;count--;
    }
}

