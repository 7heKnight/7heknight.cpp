#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>	

	
int bin2dec()
{
    int  num,cal, dec = 0, i = 0;
	
	
	printf("Enter binary number: ");
    	flag: fflush(stdin);
			scanf("%d",&num);
		fflush(stdin);
	
	if(num == 0 || num%10 == 2 ||num%10 == 3 || num%10 == 4 || num%10 == 5 || num%10 == 6 || num%10 == 7 ||num%10 ==8 || num%10 == 9)
	{
		num = 0;
		printf("\nWrong format!\n");
		printf("Re-enter the binary: ");
		goto flag;
	}
	
    while (num > 0)
    {
		dec = dec + (num % 10) * pow(2,i++);
		num = num / 10 ;
    }
    printf("Decimal number is: %d\n",dec);
	printf("Press any key to continue.\n");
}

int oct2dec()
{
    long int oct, dec = 0;
    int i = 0;
 
    printf("Enter any octal number: ");
    	flag: fflush(stdin);
			scanf("%d",&oct);
		fflush(stdin);
	
	if(oct == 0 || oct%10 == 9 || oct%10 == 8)
	{
		oct = 0;
		printf("\nWrong format!\n");
		printf("Re-enter the binary: ");
		goto flag;
	}
	
    while (oct != 0)
    {
        dec =  dec +(oct % 10)* pow(8, i++);
        oct = oct / 10;
    }

    printf("Decimal number is: %d\n",dec);
	printf("Press any key to continue.\n");
}

int hex2dec()
{
    long int hex, dec = 0;
    int i = 0;
 
    printf("Enter any hexadecimal number: ");
    	flag: fflush(stdin);
			scanf("%d",&hex);
		fflush(stdin);
	
	if(hex == 0 || hex%10 == 11 || hex%10 == 10 || hex%10 == 12 || hex%10 == 13 || hex%10 == 14 || hex%10 == 15)
	{
		hex = 0;
		printf("\nWrong format!\n");
		printf("Re-enter the binary: ");
		goto flag;
	}
    while (hex != 0)
    {
        dec =  dec +(hex % 10)* pow(16, i++);
        hex = hex / 10;
    }

    printf("Decimal number is: %d\n\n",dec);
	printf("Press any key to continue.\n");
	
}

int main()
{
	int choice;
	do
	{
		system("cls");
		printf("1. Convert binary number to decimal number\n");
		printf("2. Convert octal number to decimal number\n");
		printf("3. Convert hexadecimal number to decimal number\n");
		printf("4. Exit\n");
			choice = getch();
		
		switch(choice)
		{
			case '1' :
				bin2dec();
				break;
			case '2' :
				oct2dec();
				break;
			case '3' :
				hex2dec();
				break;
			case '4':	printf("Leaving\n");
				break;
			default: printf("\nWrong format\n");
				break;
		}
	getch();
	}
	while(choice != '4');
}
