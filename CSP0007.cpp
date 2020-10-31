#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void add_string(char a[], char &check){
	flag:printf("Please enter a string: ");
		fflush(stdin);
		gets(a);
	for(int i=0; i<strlen(a); i++){
		if(a[i]==33 || a[i]== 35 || a[i]==40 || a[i]==41 ||a[i]==64||a[i]==91||a[i]==93||a[i]==123||a[i]==125){
			printf("Do not allow enter special characters such as @, #, !, [, ], {, }, (, )\n");
			for(int j=0; j<strlen(a);j++){
				a[j]=0;
			}
			goto flag;
		}
	}
	check = a[strlen(a)];
	printf("\n Added successfully!\n");
}

void remove_blank(char a[], char check){
	int c = 0, d = 0;
	char b[500];
  	while (a[c] != '\0'){
    	if ( !(a[c] == ' ' && a[c+1] == ' ') ){
			b[d] = a[c];
			d++;
		} c++;
	}
	int n = strlen(b);
	for(int i = n; i>=0; i--){
		b[i]=0;
		if(check==b[i]){
			break;
		}
	}
	for(int i=0; i<strlen(a);i++){
		a[i]=0;
	}
	strcpy(a,b);
	printf("\n Removed unnecessary blank!\n");
}

int main(){
	int op, op1, n;
	char a[500];
	char check;
	
	do{
		flag1:printf("1. Enter an string, do not allow enter special characters such as @, #, !, [, ], {, }, (, )\n");
		printf("2. Remove all unnecessary blank in the string\n");
		printf("3. Display the string on the screen\n");
		printf("ESC to exit the program.\n\n");
			flag0:fflush(stdin);
				op = getch();
			
		switch(op){
			case '1':	add_string(a,check);
				break;
			case '2': remove_blank(a,check);
				break;
			case '3': printf("\n%s\n",a);
				break;
			default: printf("404 ERROR NOT FOUND!\n");
				goto flag0;
				break;
		}	
	}while(op != 27);
}
