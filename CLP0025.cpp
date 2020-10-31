#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

#define ESC 27

struct account{
	char ID[60];
	char PIN[8];
	char name[100];
	float balances;
	char moneyType[3];
	int accountCode;
};

struct accountLog{
	char withdraw[200];
	char transfer[200];
};

void readLog(account a[], int &n){
	FILE* f=fopen("ATM_Card.txt","r");
	if (feof(f) || f==NULL) {
		fclose(f);
	}
	fscanf(f,"%d\n",&n);
	fflush(stdin);
	
	for(int i=0; i<n;i++){
		fscanf(f,"%[^\n]%*c\n",&a[i].ID);
		fflush(stdin);
		fscanf(f,"%[^\n]%*c\n",&a[i].PIN);
		fflush(stdin);
	}
	
	fclose(f);
}

void readInfo(account a[], int n){
	FILE* f=fopen("Account_Information.txt","r");
	if (feof(f) || f==NULL) {
		fclose(f);
	}
	
	for(int i=0; i<n;i++){
		fscanf(f,"%d\n",&a[i].accountCode);
		fflush(stdin);
		fscanf(f,"%[^\n]%*c\n",&a[i].name);
		fflush(stdin);
		fscanf(f,"%f\n",&a[i].balances);
		fflush(stdin);
		fscanf(f,"%[^\n]%*c\n",&a[i].moneyType);
		fflush(stdin);
	}
	
	fclose(f);
}

void writeLog(account a[],int n){
	FILE* f=fopen("ATM_Card.txt","w");
	fprintf(f,"%d\n",n);
	for (int i=0;i<n;i++){
		fprintf(f,"%s\n",a[i].ID);
		fprintf(f,"%s\n",a[i].PIN);
	}
	fclose(f);
}

void writeInfo(account a[],int n){
	FILE* f=fopen("Account_Information.txt","w");
	for (int i=0;i<n;i++){
		fprintf(f,"%d\n",a[i].accountCode);
		fprintf(f,"%s\n",a[i].name);
		fprintf(f,"%f\n",a[i].balances);
		fprintf(f,"%s\n",a[i].moneyType);
	}
	fclose(f);
}

void forrst(char a[]){
	for(int i=0; i<strlen(a);i++)
		a[i]=0;
}

void delay(int sec){
	clock_t start = clock();
	sec *= 1000;
	
	while(clock()<start + sec);
}

void reg(account a[], int &n){
	char ID[16];
	char IDChecker[16];
	char PIN[8];
	char PINChecker[8];
	char name[100];
	char vnd[4]="VND";
	char usd[4]="USD";
	float balances;
	char moneyType[4];
	int z;
	int y;
	
	system("cls");
	printf("============== Creating_a_new_account ==============\n");
	//Enter ID 0
	flag0:printf("Enter the ID(14 numbers): ");
		fflush(stdin);
//		gets(ID);
		scanf("%[^\n]%*c",&IDChecker);
		strcpy(ID,IDChecker);

	for(int i=0;i<strlen(ID);i++){
		if(!(ID[i] >= '0' && ID[i] <='9')||!(strlen(ID)==14) ){
			printf(" Wrong format!\n");
			checkID: forrst(ID);
			goto flag0;
		}
		for(int i=0; i<n;i++){
			y = strcmp(a[i].ID,ID);		
			if(y==0){
				printf(" The ID is already exist!\nRe-");
				goto checkID;
			}
			else if(!y)
				break;
		}
	}
	
	//Enter PIN 1
	printf("Enter the PIN code(6 numbers): ");
	flag1:fflush(stdin);
		gets(PIN);
//		scanf("%[^\n]%*c",&PINChecker);
//		strcpy(PIN,PINChecker);
	for(int i=0;i<strlen(PIN);i++){
		if(!(PIN[i] >= '0' && PIN[i] <='9')||!(strlen(PIN)==6) ){
			forrst(PIN);
			printf(" Wrong format! Re-enter PIN: ");
			goto flag1;
		}
	}
	
	//Enter Name 2
	printf("Enter name: ");
	flag2:fflush(stdin);
		gets(name);
	for(int i=0;i<strlen(name);i++){
		if( !(name[i]>='A'&&name[i]<='Z') && !(name[i]>='a' && name[i]<= 'z') && !(name[i] == ' ')  ){
			forrst(name);
			printf(" Wrong format! Name can not have special character or number.\n  Re-enter name: ");
			goto flag2;
		}
	}
	
	//Enter Type of money 3
	printf("Enter type of money(USD or VND): ");
	flag3:fflush(stdin);
		gets(moneyType);
		for(int i=0;i<strlen(moneyType);i++){
			moneyType[i] = toupper(moneyType[i]);
		}
	for(int i=0;i<strlen(moneyType);i++){
		if(!(moneyType[i] == vnd[i] || moneyType[i] == usd[i])){
			forrst(moneyType);
			printf(" Wrong format! Re-enter the type of money: ");
			goto flag3;
		}
	}
	
	//Enter Balance 4vnd 5usd
	z = strcmp(vnd,moneyType);
	printf("Enter your balances:\n");
	if(z==0){
		printf(" Enter amount:");
		printf("\t\t\t\tVND\r\t\t");
		flag4:fflush(stdin);
			scanf("%f",&balances);
		if(balances == false||balances < 50000){
			printf("  False to add the values(Atleast 50000 VND). Re-enter it:\t\t\t\tVND\r\t\t\t\t\t\t\t");
			goto flag4;
		}
	}
	else{
		printf(" Enter amount: $");
		flag5:fflush(stdin);
			scanf("%f",&balances);
		if(balances == false||balances<5){
			printf("  False to add the values(Atleast $5). Re-enter it: $");
			goto flag4;
		}
	}
	
	strcpy(a[n].ID,ID);
	strcpy(a[n].PIN,PIN);
	strcpy(a[n].name,name);
	strcpy(a[n].moneyType,moneyType);
	a[n].balances = balances;
	a[n].accountCode = n+1;
	
	printf("\n  Register Successfully!");
	n++;
}

int login(account a[], int n, int &m){
	char ID[16];
	char IDChecker[16];
	char PIN[8];
	char PINChecker[8];
	int z,y;
	int count = 0;
	
	system("cls");
	printf("=============== Login ===============\n");
	printf("Please enter your ID: ");
		flag0:fflush(stdin);
		gets(ID);
	printf("PIN: ");
		flag1:fflush(stdin);
		scanf("%[^\n]s",&PINChecker);
		strcpy(PIN,PINChecker);
	
	if(count == 5)	return 0;
	
	for(int i=0;i<strlen(PIN);i++){
		if(!(PIN[i] >= '0' && PIN[i] <='9')||!(strlen(PIN)==6) ){
			forrst(PIN);
			printf("Wrong PIN! Re-enter PIN: ");
			count++;
			goto flag1;
		}
	}
		
	for(int i = 0;i<n;i++){
		z = strcmp(a[i].ID,ID);
		y = strcmp(a[i].PIN,PIN);
		if(z==0){
			if(y==0){
				m = i;
				return 1;
			}
		}
	}
	return 0;		
}

void readWithdrawLog(accountLog a[], int &z){
	FILE* f=fopen("Withdraw_Log.txt","r");
	if (feof(f) || f==NULL) {
		fclose(f);
	}
	fscanf(f,"%d\n",&z);
	fflush(stdin);
	
	for(int i=0; i<z;i++){
		fscanf(f,"%[^\n]%*c\n",&a[i].withdraw);
		fflush(stdin);
	}
	
	fclose(f);
}

void writeWithdrawLog(accountLog a[],int z){
	FILE* f=fopen("Withdraw_Log.txt","w");
	fprintf(f,"%d\n",z);
	for (int i=0;i<z;i++){
		fprintf(f,"%s\n",a[i].withdraw);
	}
	fclose(f);
}

void withdrawLog(account a[], int m, accountLog b[], float withdr){
	int z;
	z=0;
	readWithdrawLog(b,z);
	sprintf(b[z].withdraw,"No. %d: -%0.2f %s",a[m].accountCode,withdr,a[m].moneyType);
	z++;
	writeWithdrawLog(b,z);
}

void withdraw(account a[],int m){
	accountLog b[100];
	int z; //z == bien dem cua accountLog
	float withdr,currentM,minus;
	currentM = a[m].balances;
	
	system("cls");
	printf("--------------- Withdraw ---------------");
	printf("\nEnter amount to withdraw: ");
		flag:fflush(stdin);
		scanf("%f",&withdr);
		
	minus = currentM - withdr;
	
	if(withdr == false){
		withdr=0;
		printf(" Accept only numeric!\nRe-Enter the amount: ");
		goto flag;
	}
	else if(withdr<=1000){
		withdr=0;
		printf("\n Withdraw aleast >1000\nRe-Enter the amount: ");
		goto flag;
	}
	else if(minus < 0){
		minus = 0; withdr=0;
		printf("\n  Not enough money! Try to bruteforce to get other user's ID and password to get the money :)\n Re-Enter amount:");
		goto flag;
	}
	a[m].balances = minus;
	printf("\nYou withdrawn %.2f",withdr);
	printf("\nYour current amount: %.2f",a[m].balances);
	printf("\n Withdraw Successfuly!");
	
	withdrawLog(a,m,b,withdr);
}

void readTransferLog(accountLog a[], int &z){
	FILE* f=fopen("Transfer_Log.txt","r");
	if (feof(f) || f==NULL) {
		fclose(f);
	}
	fscanf(f,"%d\n",&z);
	fflush(stdin);
	
	for(int i=0; i<z;i++){
		fscanf(f,"%[^\n]%*c\n",&a[i].transfer);
		fflush(stdin);
	}
	
	fclose(f);
}

void writeTransferLog(accountLog a[],int z){
	FILE* f=fopen("Transfer_Log.txt","w");
	fprintf(f,"%d\n",z);
	for (int i=0;i<z;i++){
		fprintf(f,"%s\n",a[i].transfer);
	}
	fclose(f);
}

void transferLog(account a[], int m, accountLog b[], float k, int i,float amount){
	int z;
	z=0;
	readTransferLog(b,z);
	sprintf(b[z].transfer,"No. %d: -%0.2f %s && No.%d: +%0.2f %s",a[m].accountCode,k,a[m].moneyType,a[i].accountCode,amount,a[i].moneyType);
	z++;
	writeTransferLog(b,z);
}

void transferMoney(account a[],int i, int m){
	accountLog b[100];
	char vnd[4]="VND";
	char usd[4]="USD";
	float amount, haveM,getM;
	char *z,*y,*x,j,k;
	
	z = strstr(vnd,a[m].moneyType);
	haveM = a[m].balances;
	getM = a[i].balances;
			
	if(z){
		y = strstr(vnd,a[i].moneyType);
		
		if(y){
			printf("\n Enter amount you wana transfer: ");
				flag:fflush(stdin);
				scanf("%f",&amount);
				if(amount == 0){
					printf("\n False to enter the amount!\n Re-Enter it: ");
					goto flag;
				}

			haveM -= amount;
			if(haveM < 0){
				haveM = a[m].balances;
				amount = 0;
				printf("\n Not enough money!(Your current money: %.2f)",a[m].balances);
				goto flag;
			}
			
			k = amount;
			getM += amount;
			a[m].balances = haveM;
			a[i].balances = getM;
			j = i;

			printf("\n  Transfer successfuly! (- %.2f)",amount);
			printf("\n  Your money now have %.2f",haveM);
		}

		else{
			printf("\n The Account: %s is using USD(1 USD = 23 000 VND)",a[i].name);
			printf("\n Do you want to continue?(Y/N)");
				flag0:fflush(stdin);
				int op = getch();
				op = toupper(op);

			if(op == 'Y'){
				printf("\n Enter amount you wana transfer: ");
				flag5:fflush(stdin);
				scanf("%f%*c",&amount);
				if(amount == 0){
					printf("\n False to enter the amount!\n Re-Enter it: ");
					goto flag5;
				}

				haveM -= amount;
				a[m].balances = haveM;
				if(haveM < 0){
					haveM = a[m].balances;
					amount = 0;
					printf("\n Not enough money!(Your current money: %.2f)",a[m].balances);
					goto flag5;
				}
				k = amount;
				amount = amount / 23000;
				getM += amount;
				j = i;
				a[i].balances = getM;
				
				printf("\n  Transfer successfuly! (- %.2f)",amount);
				printf("\n  Your current money: %.2f",haveM);						
			}
			else if(op == 'N'){
				printf("\n Okie! Your choice: No(N).");
			}
			else{
				printf("\n  Just Y or N!");
				goto flag0;
			}
		}
	}
		
	else{
		y = strstr(usd,a[i].moneyType);
		
		if(y){
			printf("\n Enter amount you wana transfer: $ ");
				flag2:fflush(stdin);
				scanf("%f%*c",&amount);
				if(amount == 0){
					printf("\n False to enter the amount!\n Re-Enter it: ");
					goto flag2;
				}
				
			haveM -= amount;
			if(haveM < 0){
				haveM = a[m].balances;
				amount = 0;
				printf("\n Not enough money!(Your current money: %.2f)",a[m].balances);
				goto flag2;
			}
			k = amount;
			getM += amount;
			a[m].balances = haveM;
			a[i].balances = getM;
			j = i;
			
			printf("\n  Transfer successfuly! (- %.2f)",amount);
			printf("\n  Your money now have %.2f",haveM);
		}
		
		else{
			printf("\n The Account: %s is using VND(1 USD = 23 000 VND)",a[i].name);
			printf("\n Do you want to continue?(Y/N)");
				flag3:fflush(stdin);
				int op = getch();
				op = toupper(op);
			
			if(op == 'Y'){
				printf("\n Enter amount you wanna transfer: ");
				flag4:fflush(stdin);
				scanf("%f%*c",&amount);
				if(amount == 0){
					printf("\n False to enter the amount!\n Re-Enter it: ");
					goto flag4;
				}
				
				haveM -= amount;
				a[m].balances = haveM;
				if(haveM < 0){
					haveM = a[m].balances;
					amount = 0;
					printf("\n Not enough money!(Your current money: %.2f)",a[m].balances);
					goto flag4;
				}
				k = amount;
				amount = amount * 23000;
				getM += amount;
				j = i;
				a[i].balances = getM;
				
				printf("\n  Transfer successfuly! (- %.2f)",amount);
				printf("\n  Your current money: %.2f",haveM);						
			}
			else if(op == 'N'){
				printf("\n Okie! Your choice: No(N).");
			}
			else{
				printf("\n  Just Y or N!");
				goto flag3;
			}
		}
	}
	//if n = n1
	transferLog(a,m,b,k,j,amount);
}

void transfer(account a[],int n, int m){
	char ID[16];
	char vnd[4]="VND";
	char usd[4]="USD";
	int z;
	char choice;
	
	system("cls");
	printf("=============== Transfer_Menu ===============");
	flag:printf("\nEnter user's ID to transfer: ");
		fflush(stdin);
		gets(ID);
		
	for(int i=0; i<n;i++){
		z = strcmp(a[i].ID,ID);
		if(z==0){
			transferMoney(a,i,m);
			break;
		}
	}
	if(z!=0){
		printf("\nFalse!");
		printf(" Wanna try again?(Y/N)\n");
			flag0:fflush(stdin);
			choice = getch();
			choice = toupper(choice);
			if(choice == 'Y'){
				goto flag;
			}
			else if(choice == 'N');
			else{
				printf("Wrong!\t");
				goto flag0;
			}
	}	
}

void loginMenu(account a[],int m,int n){
	int op;

	do{
		system("cls");
		printf("=============== ACCOUNT ===============\n");
		printf("ID: %2d\n",a[m].accountCode); 
		printf("Owner name: %s\n",a[m].name);
		printf("Your balances: %.2f %s\n\n",a[m].balances,a[m].moneyType);
		printf("1. Withdraw.\n");
		printf("2. Transfer money.\n");
		printf("3. Exit.");
			fflush(stdin);
			op = getch();
		switch(op){
			case '1':	withdraw(a,m);
				break;
			case '2':	transfer(a,n,m);
				break;
			case '3':	printf("\nLogging-Out....");
				break;
		}
		delay(2);
	}while(op != '3');
	system("cls");
	
}

int main(){
	account info[100];
	int op;
	int n,n1; 
	int m; //m de get num cua n quang qua thang function login menu
	n = 0;
	int count;
	
	readLog(info,n);
	readInfo(info,n);

	n1 = n;
	
	do{
		system("cls");
		menu:printf("================== ATM_Machine ==================\n");
		printf("1. Login.\n");
		printf("2. Register.\n");
		printf("ESC to exit the program.");
		flag: fflush(stdin);
			op = getch();
		
		switch(op){
			case '1':
				if(login(info,n,m) == 1){
					printf("Login successfully!\n");
					delay(1);
					loginMenu(info,m,n);
				}
				else
					printf("Fail to login!\n");
					delay(1);
				break;
			case '2':	reg(info,n);
					delay(1);
				break;
			case ESC: printf("\nExitting the program...");
				break;
			default:	count++;
				printf("\nError! Re-enter the right option!");
				
				if(count==5){
					count = 0;
					system("cls");
					goto menu;
				}
				goto flag;
				break;
		}
	}while(op!=ESC);
	
	if(n1!=n){
		writeLog(info,n);
		writeInfo(info,n);
	}
	
	delay(5);
}
