#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
char ch[10][130]={"Cardiff Express","Belfast Express","Derby Express","Chester Express","Newport Express","Back Menu"};
void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n");
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n");
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n");
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
	printf("\n");
	printf("\t\t\t\t\t[0]  =>  %s\n",ch[5]);
}
