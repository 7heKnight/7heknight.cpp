#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int pdd()
{
	int d, m, y;
    int maxd = 31; 
    
    system("cls");
    printf("============== Date_Process ==============\n");
    flag:
    printf("Enter the day: ");
    	fflush(stdin);
		scanf("%d",&d);
	printf("Enter the month: ");
		fflush(stdin);
		scanf("%d",&m);
	printf("Enter the year: ");
		fflush(stdin);
		scanf("%d",&y);
	
	if(d == false || m == false || y == false){
		d =0;m=0;y=0;
		printf("\n False to enter the date process\n");
		goto flag;
	}
	if(y <1900)	return 0;
	if ( d<1 || d>31 || m<1 || m>12) return 0;
	
	if ( m==4 || m==6 || m==9 || m==11) maxd=30;
	else if (m==2)
	{
		if ( y%400==0 || ( (y%4==0) && (y%100!=0) ) ) maxd=29;
		else if(y%2 == 0 && y%4 ==2) maxd=28;
		else maxd=28;
    }
    
    printf(" Your inpputed date: %d/%d/%d\n  ",d,m,y);
	return d<=maxd; 
}

char op1()
{
	char a, b;
	system("cls");
	printf("============== Convert_Characters_to_ASCII ==============\n");
	printf("Please enter 2 characters.\n");
	printf("Enter 1st character: ");
		scanf("%c",&a);
		fflush(stdin);
	printf("Enter 2st character: ");
		scanf("%c",&b);
		fflush(stdin);
	if(a<b)
		for(a; a<=b; a++)
			printf("\nChar: %c, ASCII: %d\n",a,a);
	else if(a>b)
		for(a; a>=b; a--)
			printf("\nChar: %c, ASCII: %d\n",a,a);
}

void op2()
{
	char b;
	system("cls");
	printf("============== Convert_ASCII_to_Char ==============\n");
	printf("\nEnter ASCII code: ");
	while(b == 0){
	flag:fflush(stdin);
		scanf("%d",&b);
		fflush(stdin);
		if(b == 0){
			b = 0;
			printf("Wrong format!\n\nPlease re-enter the ASCII code: ");
		}
	}

	printf("ASCII:%d Character: %c\n",b,b);	
}

char cd()
{
	int op;
	
	system("cls");
	printf("================Option_2:_Character_data.================\n");
	printf("1 - Convert a character to ASCII code\n");
	printf("2 - Convert ASCII to a character code\n");
	printf("Choose 1 option!");
	flag:	op = getch();
		fflush(stdin);
		
	switch(op)
	{
		case '1':
			op1();
			break;
		case '2':
			op2();
			break;
		default: printf("\nWrong format! Try again.");
			goto flag;
			break;
	}
}

int main()
{
	int op;
	do
	{
		system("cls");
		printf("================Welcome to my Menu================\n");
		printf("1 - Processing date data\n");
		printf("2 - Character data\n");
		printf("3 - Exit\n");
		flag:	fflush(stdin);
			op = getch();
		switch(op)
		{
			case '1':
				    if (pdd()) printf("Valid date!");
 					   else printf("Invalid date!");
				break;
			case '2':
				cd();
				break;
			case '3': printf("Leaving......");
				break;
			default: printf("Wrong format!Please try again.\n");
				goto flag;
				break;
		}
		getch();
	}
	while(op != '3');
}
