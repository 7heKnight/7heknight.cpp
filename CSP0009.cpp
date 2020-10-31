#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int keyboard;
	int n, min, place, i;
	int a[100];
	do
	{
		system("cls");
		printf("Please enter size of array: ");
			scanf("%d",&n);	
		
		for(i=1; i<=n; i++)
		{
			printf("Element[%d]=",i);
				scanf("%d",&a[i]);
		}
		
		min = a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<min)
			{
				min = a[i];
				place = i ;
			}
		}
		printf("\nThe smallest element: %d - Its position: %d %d\n",min,place,min);
		
		printf("Enter to continue. Esc to exit.\n");
			flag: keyboard = getch();
			switch(keyboard){
				case 27: printf("\nLeaving...\n");
					break;
				case 13:
					break;
				default: goto flag;
					break;
			}
	}
	while(keyboard != 27);
}
