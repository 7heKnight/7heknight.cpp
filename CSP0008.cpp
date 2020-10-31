#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void addString(char a[]){
	printf("Please enter a string: ");
		fflush(stdin);
		gets(a);
	for(int i=0;i<strlen(a);i++)
		a[i] = tolower(a[i]);
}

void appearedOne(char a[], char b[]){
	for(int i=0; i<strlen(a);i++)
		b[a[i]]++;
}

void printAppeared(char b[]){
	printf("Found characters: ");
	for(int i = 95; i <123;i++)
		if(b[i]==1)
			printf("%-4c",i);
}

int main(){
	int op, op1;
	char a[100];
	char b[25];
	
	do{
		system("cls");
		addString(a);
		appearedOne(a,b);
		printAppeared(b);
		printf("\n---------------------------------------------------");
		printf("\nContinue to run program if press enter, Esc to exit.\n");
			flag:fflush(stdin);
			op1 = getch();
			
		if(op1 == 27);
		else if(op1 != 13){
			printf("Wrong Inpput!\n");
			goto flag;
		}

	}while(op1 != 27);
	
	printf("\nExitting the program...\n");
}
