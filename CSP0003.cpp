#include<stdio.h>
#include<string.h>

int add(int a[], int &n){
	for(int i =0; i<n ; i++ ){
		printf("Enter element [%d]: ",i+1);
			scanf("%d",&a[i]);
	}
}

int bubblesort(int a[], int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j = i + 1; j <n; j++){
			if(a[i]>a[j]){
				int b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
		printf("%-4d",a[i]);
	}
}

int main(){
	int a[100];
	int i,z;
	int checknum, newchecknum;
	int newvalue;
	
	printf("Enter number input: ");
		scanf("%d",&checknum);
	
	add(a,checknum);
	bubblesort(a,checknum);
	
	newchecknum = checknum + 1;
		
	printf("\nEnter an element: ");
		scanf("%d",&newvalue);
	
	for(int i=checknum; i>=0; i--){
		if(i == 0){
			a[i] = newvalue;
			break;
		}
		a[i]=a[i-1];
		if(newvalue > a[i-1]){
			a[i] = newvalue;
			break;
		}
	}
	for(int i=0; i<newchecknum;i++){
		printf("%-4d",a[i]);
	}
}
