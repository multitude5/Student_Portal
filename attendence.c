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
    char t_id[15]="aksam@cui.com3";
    char s_registration[15];
    char student_r[20];
    char studen_name[20];
    char attadence[3];
    fp = fopen("data.txt","r+");
    int position;
    if (fp==NULL)
    {
        printf("Error");
    }
    fseek(fp,0,0);
    int n,n2;
    fscanf(fp,"%d %d",&n,&n2);
    int s_number = n;
    n2 = n;
    int i=2,i2=1;
    int dum=10;
    while (1)
    {
        rewind(fp);
        position=(280*i)-280+i2;
        fseek(fp,position,0);
        fgets(s_registration,15,fp);
        if (!strcmp(t_id,s_registration))
        {
            i2--;
            printf("NAME                                         REGISTRATION NO       ATTEDENCE");
            for (;n>0;n--)
            {
                rewind(fp);
                position=(280*i)-240+i2;
                fseek(fp,position,0);
                fgets(student_r,20,fp);
                position=(280*i)-179+i2;
                fseek(fp,position,0);
                fgets(studen_name,20,fp);
                printf("\n%-45s%-25s",studen_name,student_r);
                position=(280*i)-60+i2;
                scanf("%s",attadence);
                fseek(fp,position,0);
                fputs(attadence,fp);
                i++;i2++;
            }
            break;
        }
        else if (s_registration[0]=='0')
        {
            break;
        }
        i++;i2++;dum--;
    }
}




void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
