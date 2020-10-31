#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

void random(int &a){
	a=rand()%10;
}

void delay(int num){
	clock_t s = clock();
	num *= 1000;
	
	while(clock() < s + num);
}

void process(int a, int b, int c, float &cash){
	printf("\nThe slot machine shows %d%d%d\n",a,b,c);
	printf("\n//////////////////\n");
	printf("||  --  --  --	||\n");
	printf("|| |%d| |%d| |%d|  ||\n",a,b,c);
	printf("||  --  --  --	||\n");
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	printf("\n");
	
	cash = cash - 0.25;
	
	if(a == b && a == c && b == c){
		cash += 10;
		printf("\n You win the big prize, $10.00!");
		printf("\n   You have $%.2f.",cash);
	}
	
	else if( a == b || a == c || b == c){
		cash += 0.5;
		printf("\n You won 50 cent!");
		printf("\n   You have $%.2f.",cash);
	}
	
	else{
		printf("\n Sorry you don't won anything.");
		printf("\n   You have $%.2f.",cash);
	}
}

void readFile(float &cash){
	FILE* f=fopen("Saved_Cash","r");
	if (feof(f) || f==NULL){
		fclose(f);
	}
	fscanf(f,"%f",&cash);
}

void writeFile(float cash){
	FILE* f=fopen("Saved_Cash","w");
	fprintf(f,"%.2f",cash);
}

int main(){
	int op, count = 0;
	float cash=0;
	int a,b,c;
	
	readFile(cash);
	
	if(cash == 0){
		cash = 10;
	}
	
	while(op != '3'){
		system("cls");
		flag1:printf("=============== WELCOME_TO_SLOT_MACHINE ===============\n");
		printf("Choose one of the following menu options:\n");
		printf("1) Play the slot machine.\n");
		printf("2) Save game.\n");
		printf("3) Cash out.");
			flag:fflush(stdin);
			op = getch();
		switch(op){
			case '1':
				if(cash != 0){
					random(a); random(b); random(c);
					process(a,b,c,cash);
					printf("\n");
				}
				else if(cash == 0){
					printf("\n Out of money. Go away!\n");
					op = '3';
				}
				delay(2);
				break;
			case '2': writeFile(cash);
				printf("\n Saving...");
				delay(2);
				break;
			case '3':
				printf("\n Thank you for playing! You end with $%.2f",cash);
				delay(4);
				break;
			default:
				count++;
				printf("\n Wrong option!");
				if(count == 5){
					count = 0;
					system("cls");
					goto flag1;
				}
				goto flag;
				break;
		}
	}
}
