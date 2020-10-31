#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100

void copy(int source[], int newArray[], int n){
	for(int i=0; i<n;i++){
		newArray[i]=source[i];
	}
}
void resetStr(int array[],int n){
	for(int i=0; i<n;i++){
		array[i]=0;
	}
}

void menu(int &op) {
	printf("=================MENU=================\n");
	printf("1. Add a value.\n");
	printf("2. Search a value.\n");
	printf("3. Remove the first existence of a value.\n");
	printf("4. Remove all existences of a value.\n");
	printf("5. Print out the array.\n");
	printf("6. Sort the array in ascending order (positions of elements are preserved).\n");
	printf("7. Sort the array in descending order (positions of elements are preserved).\n");
	printf("Others: exit the program");
		op = getch();
		fflush(stdin);
}

int addAValue(){
	int a=0;
	bool check=false;
	printf("\n---------- ADD ----------\n");
	while(check!=true){
		printf("Enter A value: ");
		fflush(stdin);
		scanf("%d",&a);
		if(a==0){
			printf("Wrong format!\n");
		}
		else
			return a;
	}
}

int searchvalue(int a[], int inpput2check, int n){
	int z=0;
	for(int i=0 ; i<n ; i++){
		if(inpput2check == a[i])
			z++;
	}
	if(z==0)
		return printf("  Value not found!");
	else
		return printf("  %d Value founded!",z);
}

int rm1stvalue(int a[], int &n){
	int inpput=0;
	bool check = false;
	if(n==0){
		return printf("\n There is not any value to remove");
	}
	
	printf("\nEnter a value to delete: ");
		scanf("%d",&inpput);
	
	for(int i=0; i<n; i++){
		
		if(inpput == a[i]){
			for(int j=i; j<n; j++){
				a[j]=a[j+1];
			}
			n = n-1;
			return printf("\n  Removed first element (%d) in an array!",inpput);
		}
	}
	if (check == false)
		return printf("No value matched to delete");
}

int rma(int a[],int &n){	
	bool check = false;
	int inpput=0;int count=0;
	int b[n]; int c[n];int j=0;
	if(n==0){
		return printf("\n There is nothing to remove");
	}
	
	printf("\nEnter an element to delete all of that element: ");
		scanf("%d",&inpput);
	copy(a,b,n);
	resetStr(a,n);
	for(int i=0; i<n;i++){
		if(inpput==b[i])	count++;
		else if(b[i]!=inpput){
			a[j]=b[i];
			j++;
		}
	}
	n = n-count;
	if(count==0)
		return printf("\n  Non value matched!");
	return printf("\n Removed all of the element (%d) in the array", inpput);
}

int print(int a[], int n){
	printf("\n-------- PRINT LIST --------\n");
	if (n == 0)	return printf(" Nothing in array!");
	
	for(int i=0; i<n;i++)	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
	getch();
}

int ascending(int b[],int n){
	printf("\n------------- SORT (ASCEND) -------------\n");
	int i, j;
	int a[n];
	if(n==0){
		return printf("Nothing to sort!");
	}
	copy(b,a,n);
	for(i=0; i<n; i++){
		for(j = i + 1; j <n; j++){
			if(a[i]>a[j]){
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}printf("%-4d",a[i]);
	}
}

int descending(int b[],int n){
	printf("\n------------- SORT (DESCEND) -------------\n");
	if(n==0){
		return printf("Nothing to sort!");
	}
	int i, j;
	int a[n];
	copy(b,a,n);	
	for(i=0; i<n; i++){
		for(j = i + 1; j <n; j++){
			if(a[i]<a[j]){
				int c = a[j];
				a[j] = a[i];
				a[i] = c;
			}
		}printf("%-4d",a[i]);
	}	
}

int main(){
	int a[MAXSIZE];
	int keyboard;
	int n=0, inpput2check;

	do{
		menu(keyboard);
		switch(keyboard){
			case '1':
				a[n] = addAValue();
				printf("Add value successful!");
				n++;
				getch();
				break;
			case '2':
				printf("\n------------ SEARCH ------------");
				printf("\nEnter the value to search and check (valuable or not): ");
					scanf("%d",&inpput2check);
				searchvalue(a,inpput2check,n);
				getch();
				break;
			case '3':
				printf("\n-------------- Remove the matched value --------------");
				rm1stvalue(a,n);
				getch();
				break;
			case '4':
				printf("\n-------------- Remove all the matched value --------------");
				rma(a,n);
				getch();
				break;
			case '5': print(a,n);
				getch();
				break;
			case '6':
				ascending(a,n);
				getch();
				break;
			case '7':
				descending(a,n);
				getch();
				break;
			default:
				printf("\n\n   Leaving...\n");
				getch();
				break;
		}
		system("cls");
	}while(keyboard>='1' && keyboard<='7');
}
