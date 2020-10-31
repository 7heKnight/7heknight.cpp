#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

int comparevalue(int a[], int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (a[i]==a[j])
			{
				for(int k=j;k<n;k++)
				{
					a[k] = a[k+1];
				}
				n--;
				j--;
			}
		}
		printf("%-4d",a[i]);
	}	
}

int main()
{
	int a[100];
	int n, i;
	
	printf("Please enter size of array: ");
		fflush(stdin);
		scanf("%d",&n);
		fflush(stdin);
	
	for(i=0;i<n;i++)
	{
		flag:
		printf("Element[%d] = ",i);
			fflush(stdin);
			scanf("%d",&a[i]);
			fflush(stdin);
		if(a[i]==false){
			goto flag;
		}
	}
	
	printf("\n\nThe original array:\n");
	for(i=0;i<n;i++)	printf("%-4d",a[i]);
	
		
	printf("\n\nThe array after removing duplicate elements:\n");
	comparevalue(a,n);
	
	printf("\n\n");
	getch();
}
