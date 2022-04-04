#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include"lib.h"
#include"login.c"
#include"bus.c"
#include"booking.c"
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
void bus();
void name_number(int booking,char numstr[100]);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancle();

int main()
{
	login();
    int num,i;
    do{
    system("cls");
    printf("\n\n\n");
   printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> View Bus List\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Book Tickets\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Cancle Booking\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Bus Status Board\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Exit\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice:: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        bus();
        break;
    case 2:
        booking();
        break;
    case 3:
        cancle();
        break;
    case 4:
        status();
        break;
    }
getch();
    }while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t Brought To You By code-projects.org");
    getch();
    return 0;
}
void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");
   b = fopen(tempstr2,"a");
for(i=0; i<booking; i++)//
{
    printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
      printf("\t\t\t\tEnter the seat number:--->");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the name of person:--->");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int trno)
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,trno,index=0,j;
    printf("Enter the number of bus:---->");
    scanf("%d",&trno);
    j=read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",trno,ch[trno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancle()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:---->");
 scanf("%d",&trno);
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_name(trno);
 status_1(trno);
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
}
