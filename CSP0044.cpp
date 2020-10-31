#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define MAX 100

void menu(int &op)
{
	printf("1- Add a value.\n");
	printf("2- Search a value.\n");
	printf("3- Print out the array.\n");
	printf("4- Print out values in a range of inputted min and max values, inclusively.\n");
	printf("5- Sort the array in ascending order.\n");
	printf("Others- Quit.");
		op = getch();
		fflush(stdin);
}

void addArray(int a[], int &n, int &count)
{
	int m;
	if(count == '0')
		goto flag0;
	else if(count != '0'){
		m = count;
		count+=n;
		n = count;
		goto flag0;
	}
	
	flag0: for(int i = m; i<n; i++)
	{
			printf("Enter the element [%d]: ",i+1);
				scanf("%d",&a[i]);
	}
}

int search(int a[],int n)
{
	int z;
	printf("Input the search value: ");
		scanf("%d",&z);
	for(int i = 0; i<n;i++)
	{
		if(z == a[i])
			return printf("Valid value");
	}
	
	return printf("Invalid value");
}

void printArray(int a[], int n)
{
	system("cls");
	for(int i=0; i<n;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
}

int maxValue(int a[],int n)
{
	int maxed = 0;
	for(int i=0; i<n;i++)
	{
		if(maxed<a[i])
			maxed = a[i];
	}
	return maxed;
}

int minValue(int a[],int n)
{
	int min = a[0];
	for(int i=0; i<n;i++)
	{
		if(min>a[i])
			min = a[i];
	}
	return min;
}

void printRange(int a[], int n)
{
	int min, max;
	min = minValue(a,n);
	max = maxValue(a,n);
	
	system("cls");
	printf("\n%d (Min Value) < ",min);
	for(int i=0; i<n; i++)
	{
		if(a[i] > min && a[i] < max)
			printf("%-3d",a[i]);
	}
	printf("< %d (Max Value)\n",max);
}

void ascending(int a[], int n)
{
	system("cls");
	printf("\nThe array is ascended!\n");
	printf("Here is your new array: ");
	for(int i=0; i<n; i++)
	{
		for(int j = i + 1; j <n; j++)
		{
			if(a[i]>a[j])
			{
				int b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
		printf("%-4d",a[i]);
	}
}

int main()
{
	int op;
	int a[MAX];
	int n = 0,count = 0;
	do
	{
		system("cls");
		menu(op);
		switch(op)
		{
			case '1':
				system("cls");
				printf("Enter the number of array: ");
					scanf("%d",&n);
				addArray(a,n,count);
				break;
			case '2': search(a,n);
				break;
			case '3':	printArray(a,n);
				break;
			case '4':	printRange(a,n);
				break;
			case '5':	ascending(a,n);
				break;
			default:	printf("\nLeaving...\n");
				break;
		}
		getch();
	}
	while(op >= '1' && op <= '5' );
}
