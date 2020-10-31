#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

struct studentList
{
	char sCode[10];
	char sName[100];
	char dob[12];
	float point;
};

char markPoint[20];
void delay(int sec){
	clock_t start = clock();
	int milisec = sec * 1000;
	while (clock()<start + milisec);
}

void forrst(char a[]){
	for(int i=0; i<strlen(a);i++)
		a[i]=0;
}

char readFromFile(studentList studentInfo[],int &n){
	FILE* f=fopen("Student.txt","r");
	if (feof(f) || f==NULL) {
		fclose(f);
		return 0;
	}
	fscanf(f,"%d%*c",&n);
	fflush(stdin);
	for (int i=0;i<n;i++){
		fscanf(f,"%[^\n]%*c\n",&studentInfo[i].sCode);
		fflush(stdin);
		fscanf(f,"%[^\n]%*c\n",&studentInfo[i].sName);
		fflush(stdin);
		fscanf(f,"%[^\n]%*c\n",&studentInfo[i].dob);
		fflush(stdin);
		fscanf(f,"%f\n",&studentInfo[i].point);
		fflush(stdin);
		fscanf(f,"%s\n",markPoint);
		fflush(stdin);
	}
	fclose(f);
}

void writeOnFile(studentList studentInfo[],int n){
	FILE* f=fopen("Student.txt","w");
	fprintf(f,"%d\n",n);
	for (int i=0;i<n;i++){
		fprintf(f,"%s\n",studentInfo[i].sCode);
		fprintf(f,"%s\n",studentInfo[i].sName);
		fprintf(f,"%s\n",studentInfo[i].dob);
		fprintf(f,"%f\n",studentInfo[i].point);
		fprintf(f,"#############\n");
	}
	fclose(f);
}

void enterList(studentList studentInfo[], int &n){	
	char code[10];
	int codechecker;
	char name[100];
	char doB[12];
	float score=0.00;
	int m = 0;
	
	system("cls");
	printf("-----------------ADD_LIST-----------------\n");
	printf("Enter new student:\n");
	flag0: printf("Student code: ");
		fflush(stdin);
		gets(code);
	for(int i = 0; i<n ; i++){
		codechecker = strcmp(studentInfo[i].sCode,code);
		if(codechecker==0){
			printf("\nERROR_040: Value founded!\nRe-enter the value.\n\n");
			goto flag0;
		}
	}
	printf("Student name: ");
		flag1:fflush(stdin);
		gets(name);
	for(int i=0;i<strlen(name);i++){
		if( !(name[i]>='A'&&name[i]<='Z') && !(name[i]>='a' && name[i]<= 'z') && !(name[i] == ' ') || (name[i]==32&&name[i]==name[i+1]) || strlen(name)<2 ){
			forrst(name);
			printf("ERROR: Name can not have special character or number.\nRe-enter the student name: ");
			goto flag1;
		}
	}
	printf("Date of birth(DD/MM/YYYY): ");
	flag2:fflush(stdin);
		gets(doB);
	for(int i=0;i<strlen(doB);i++){
		if(!(doB[i] >= 45 && doB[i] <= 57) || !(strlen(doB) == 10 )){
			printf("\nFalse to enter the date of birth!\nRe-Enter it: ");
			goto flag2;
		}
	}
		
	printf("Point(Limit 100): ");
		flag3:fflush(stdin);
		scanf("%f",&score);
	if(score == false || score>100 || score <0){
		score = 0;
		printf("ERROR: False to add the point.\nRe-Enter it: ");
		goto flag3;
	}	
		
	strcpy(studentInfo[n].sCode,code);
	strcpy(studentInfo[n].sName,name);
	strcpy(studentInfo[n].dob,doB);
	studentInfo[n].point = score;
	
	printf("\n  Added new student successfully!");
	n++;
}

void lookup(studentList a[], int n){
	char b[100];
	int* p;
	int i;
	int n1;
	float score;
	char* z;
	
	n1 = n - 1;
	
	system("cls");
	printf("-----------------LOOKUP_STUDENT-----------------\n");
	printf("Please enter student name: ");
		gets(b);
		for(i = 0;i<n;i++){
			z = strstr(a[i].sName,b);
			if(z){
				score = a[i].point;
				printf("\n------------------------\n");
				printf("Student code: %s\n",a[i].sCode);
				printf("Student name: %s\n",a[i].sName);
				printf("Date of birth: %s\n",a[i].dob);
				printf("Learning point: %.2f\n",score);
				printf("------------------------\n");
			}
			else
				printf("Invalid name!");
		}
}

void printList(studentList a[], int n)
{
	float score;
	int n1;
	
	n1 = n-1;
	
	system("cls");
	printf("-----------------PRINT_LIST-----------------\n");
	for(int i = 0; i<n; i++){
		score = a[i].point;
		printf("Student code: %s\n",a[i].sCode);
		printf("Student name: %s\n",a[i].sName);
		printf("Date of birth: %s\n",a[i].dob);
		printf("Learning point: %.2f\n",score);
		printf("-----------------------\n");
	}
}

int main()
{
	studentList studentInfo[100];
	int op;
	int n,n1;
	n = 0;
	readFromFile(studentInfo,n);
	n1 = n;
	do{
		system("cls");
		printf("===================MENU===================\n");
		printf("1. Enter student list\n");
		printf("2. Look up student\n");
		printf("3. Display student list\n");
		printf("4. Exit\n");
			op = getch();
			fflush(stdin);
		switch(op){
			case '1': enterList(studentInfo,n);
				delay(2);
				break;
			case '2':	lookup(studentInfo,n);
				delay(2);
				break;
			case '3':	printList(studentInfo,n);
				getch();
				break;
			case '4': printf("Leaving...\n");
				break;
			default:	printf("Wrong formant! Retry it.\n");
				delay(1);
				break;
		}
		
	}while(op != '4');
	
	if(n1 != n)
		writeOnFile(studentInfo,n);
	delay(4);
}
