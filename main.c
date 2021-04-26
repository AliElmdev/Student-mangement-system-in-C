//AliDev

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>

#define Student struct Stud

void add(FILE * fp); // fonction pour ajouter des etudiant
void modify(FILE * fp);// fonction pour modifier les notes ou les information des etudiants
void display(FILE * fp);
void Indivisual(FILE *fp);
void ratt(FILE * fp);
void password();
FILE * del(FILE * fp);
void printChar(char ch,int n);
void title();
FILE *tp;

void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct pass
{
	char pass[25];
}pa;

struct Stud
{
    char name[100];
    char dept[50];
    int idnum;
    float mark[2];
    float moy;
};

int main()
{
    int ch,id,k,i;
    char c,pas[50];
    SetConsoleTitle("Student Management System | EST");
    FILE * fp;
    Student s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    system("color E8");
    gotoxy(39,2);
    printf("Ecole Superieure De Technologie Meknes");
	gotoxy(42,8);
	printf("LOGIN(If 1st login press ENTER)");
	gotoxy(42,10);
	printf("************************************");
	gotoxy(42,11);
	printf("*                                  *");
	gotoxy(42,12);
	printf("*\tEnter Password :             *");
	gotoxy(42,13);
	printf("*                                  *");
	gotoxy(42,14);
	printf("************************************");
	printf("\n\t\t\t\t\t");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("      ****        **          *****         ******   ******   **        **\n");
	printf("     **  **       **            *           *   **   **        **      **\n");
	printf("    ********      **            *           *   **   ******     **    **\n");
	printf("   **      **     **            *           *   **   **          **  **\n");
	printf("  **        **    *******     *****         ******   ******       ****\n");
	gotoxy(65,12);
	while( k<10)
	{
	    pas[k]=getch();
	    char s=pas[k];
	    if(s==13)
		 break;
	    else printf("*");
	    k++;
	}
	pas[k]='\0';
	tp=fopen("Password.txt","r+");
    fgets(pa.pass,25,tp);
    if(strcmp(pas,pa.pass)==0)
	{
		system("cls");
		gotoxy(10,3);
		printf("<<<< Loading Please Wait >>>>");
		for(i=0; i<5; i++)
        {
            printf("\t(*_*)");
            Sleep(500);
        }
        printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *       Welcome %c    *",3);
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		gotoxy(100,27);
    	printf("By AliDev");
    	gotoxy(80,18);
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
		getch();

    title();
    printf("\n\n\t\t\t  Project in C programming 2020");
    printf("\n\n\t\t\t\t      AliDev ");
    printf("\n\n\t\t\t Ecole Superieure De Technologie\n");
    printf("\t\t\t\t      Meknes\n\t\t\t");
    printChar('=',33);
    printf("\n\n\n\t\t\t       press any key to Enter");
    getch();

    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Modify Student");
        printf("\n\n\t\t\t\t3. Show All Student");
        printf("\n\n\t\t\t\t4. Individual View");
        printf("\n\n\t\t\t\t5. Remove Student");
        printf("\n\n\t\t\t\t6. List of students (Pdf)");
        printf("\n\n\t\t\t\t7. Valider/Rattrapage");
        printf("\n\n\t\t\t\t8. Presence/Absence(comming soon....)");
        printf("\n\n\t\t\t\t9. Change Password");
        printf("\n\n\t\t\t\t10. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                add(fp);
                break;
            case 2:
                modify(fp);
                break;
            case 3:
                display(fp);
                break;
            case 4:
                Indivisual(fp);
                break;
            case 5:
                fp=del(fp);
                break;
            case 6:
                system("cls");
            	system("color 4f");
		        gotoxy(10,3);
		        printf("<<<< Opening Please Wait >>>>");
		        for(i=0; i<5; i++)
                {
                    printf("\t(*_*)");
                    Sleep(500);
                }
                //note:   strcat(s,s1)  
            	system("list.pdf");
            	break;
            case 7:
                ratt(fp);
                break;
            case 8:
                system("cls");
		        gotoxy(10,3);
		        printf("<<<< Opening Please Wait >>>>");
		        for(i=0; i<5; i++)
                {
                    printf("\t(*_*)");
                    Sleep(500);
                }
            	//system("attendance.exe");
            	break;
            case 9:
            	    system("cls");
				    system("color 5f");
			        password();
                break;
            case 10:
                return 1;
                break;
            default:
                printf("\n\t\tNo Action Detected");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
        }
    }
    }
    else
    {
        printf("Wrong Password . Get Out");
        getch();
    }
    return 1;
}


void password()
{
	char c;
	printf("\nEnter new password :");
	fflush(stdin);
	gets(pa.pass);
	printf("\nSave password (y/n) :");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		tp=fopen("Password.txt","w+");
	    fwrite(&pa,sizeof(pa),1,tp);
	    fclose(tp);
		printf("\n\tPassword Saved\n");
	}
	else
	{
		printf("Password not saved :\n");
		printf("Press any key to continue >>>");
		getch();
	}
}


void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t");
    printChar('=',19);
    printf(" Student Management System ");
    system("COLOR 03");
    printChar('=',19);
    printf("\n");
}


//Insert at end

 void add(FILE * fp)
{
    title();

    char another='y';
    Student s;
    int i;
    float moy;

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\tEnter Depertment Name: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\tEnter Id num number: ");
        scanf("%d",&s.idnum);

        printf("\n\n\tEnter marks for 12 semesters\n");
        for(i=0,moy=0; i<2; i++)
        {
        	printf("Devoir %d : ",i+1);
            scanf("%f",&s.mark[i]);
            moy+=s.mark[i];

        }

        moy/=2.0;
        s.moy=moy;

        fwrite(&s,sizeof(s),1,fp);

        printf("\n\n\t\tAdd another student?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}


FILE * del(FILE * fp)
{
    title();

    Student s;
    int flag=0,tempidnum,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter Id num number of Student to Delete the Record");
    printf("\n\n\t\t\tidnum No. : ");
    scanf("%d",&tempidnum);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.idnum==tempidnum)
        {
            flag=1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.dept,s.idnum);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tNO STUDENT FOUND WITH THE INFORMATION\n\t");

    printChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}


void modify(FILE * fp)
{
    title();

    Student s;
    int i,flag=0,tempidnum,siz=sizeof(s);
    float moy;

    printf("\n\n\tEnter Id num Number of Student to MODIFY the Record : ");
    scanf("%d",&tempidnum);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.idnum==tempidnum)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tRecord Found\n\t\t\t");
        printChar('=',38);
        printf("\n\n\t\t\tStudent Name: %s",s.name);
        printf("\n\n\t\t\tStudent Id num: %d\n\t\t\t",s.idnum);
        printChar('=',38);
        printf("\n\n\t\t\tEnter New Data for the student");

        printf("\n\n\t\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\t\tEnter Department: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\t\tEnter idnum number: ");
        scanf("%d",&s.idnum);


        printf("\n\n\t\tEnter marks for 2 semesters\n");
        for(i=0,moy=0; i<2; i++)
        {
        	printf("Devoir %d : ",i+1);
            scanf("%f",&s.mark[i]);
            moy+=s.mark[i];

        }
        moy=moy/2.0;
        s.moy=moy;

        fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");

}

void display(FILE * fp)
{
    title();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tDepertment : %s",s.dept);
        printf("\n\n\t\tId num : %d",s.idnum);
        printf("\n\n\tMarks: ");

        for(i=0; i<2; i++)
            printf("| %.2f |",s.mark[i]);
        printf("\n\n\t\tmoy : %.2f\n\t",s.moy);
        printChar('-',65);
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

void Indivisual(FILE *fp)
{
    title();

    int tempidnum,flag,siz,i;
    Student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        printf("\n\n\tEnter Id num Number: ");
        scanf("%d",&tempidnum);

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.idnum==tempidnum)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\t\tNAME : %s",s.name);
            printf("\n\n\t\tDepartment : %s",s.dept);
            printf("\n\n\t\tidnum : %d",s.idnum);
            printf("\n\n\tMarks: ");

            for(i=0; i<2; i++)
                printf("| %.2f |",s.mark[i]);
            printf("\n\n\t\tmoy : %.2f\n\t",s.moy);
            printChar('-',65);

        }
        else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

        printf("\n\n\t\tShow another student information? (Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}
void ratt(FILE * fp){
	title();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);
    printf("\t");
    printChar('-',60);
    printf("\n\t|\t       Les Etudiant Avec une note >12              |\n\t");
    printChar('-',60);
    printf("\n\t|\t            NAME  \t | \t Moyene            |\n\t");
    printChar('-',60);
    while((fread(&s,siz,1,fp))==1)
    {
        if(s.moy>12){
        printf("\n\t|\tNAME : %s\t | \tmoy : %.2f        |\n\t",s.name,s.moy);
        printChar('-',60);
    }
    }
	printf("\n\n");
    rewind(fp);
        printf("\t");
    printChar('-',60);
    printf("\n\t|\t       Les Etudiant Avec une note >12              |\n\t");
    printChar('-',60);
    printf("\n\t|\t            NAME  \t | \t Moyene            |\n\t");
    printChar('-',60);
    while((fread(&s,siz,1,fp))==1)
    {
        if(s.moy<=12){
        printf("\n\t|\tNAME : %s\t | \tmoy : %.2f        |\n\t",s.name,s.moy);
        printChar('-',60);
    }
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

