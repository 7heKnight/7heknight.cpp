#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

struct memcache{
	char key[100];
	char data[100];
	int second;
	clock_t start_time;
};

void reset_string(char a[]){
	for(int i =0; i<strlen(a);i++){
		a[i]=0;
	}
}

void cpystr(char a[],int n,int i){
	for(int j=i; j<n;j++){
		a[j]=a[j+1];
	}
}

void store(memcache a[], int &n){
	int z=0;
	
	system("cls");
	printf("Enter your key: ");
		flag:fflush(stdin);
		gets(a[n].key);
		
	for(int i =0;i<n-1;i++){
		z = strcmp(a[i].key,a[n].key);
		if(z == 0){
			reset_string(a[n].key);
			printf("\n This key has already existed!\nRe-Enter key: ");
			goto flag;
		}
	}
			
	for(int i=0; i<strlen(a[n].key); i++){
		if( !((a[n].key[i] >= 65) && (a[n].key[i] <= 90)) && !((a[n].key[i] >= 97) && (a[n].key[i] <= 122)) && !(a[n].key[i] == 95) || !(strlen(a[n].key)>0) ){
			reset_string(a[n].key);
			printf("\n Ko thich cho so va ky tu  dac biet (ngoai tru \"_\")");
			goto flag;
		}
	}
	printf("Enter your variable:");
		fflush(stdin);
		gets(a[n].data);
	printf("Enter expiry time: ");
		fflush(stdin);
		scanf("%d%*c",&a[n].second);
		
	if(a[n].second != 0){
		a[n].start_time = clock();
	}
	
	else
		printf("\n Your key and variable will never expiried(except you remove it)!");

	printf("\n Added Successfuly!\n");
	
	n++;
}

int retrie(memcache a[], int &n){
	char b[100];
	int z=0;
	clock_t clockk = clock();
	
	printf("\nEnter your key: ");
		fflush(stdin);
		gets(b);
	for(int i = 0; i < n; i++){
		if(a[i].second != 0){
			int milisec = 1000 * a[i].second;
			if(clockk > a[i].start_time + milisec){
				reset_string(a[i].key);
				reset_string(a[i].data);
				a[i].second = 0;
				a[i].start_time = 0;
				cpystr(a[i].key,n,i);
				cpystr(a[i].data,n,i);
				for(int j = i+1; j<n;j++){
					a[i].second = a[j].second;
					a[i].start_time = a[j].start_time;
				}
			}
			n--;
		}
		z = strcmp(a[i].key,b);
		if(z == 0){
			return printf("\n Your data is: %s",a[i].data);
		}
	}
	return printf(" Invalid key!");
}

int delete_item(memcache a[], int &n){	//sai
	char b[100];
	int z=0;
	clock_t clockk = clock();
	
	printf("\nEnter your key: ");
		fflush(stdin);
		gets(b);
	for(int i = 0; i < n; i++){
		z = strcmp(a[i].key,b);
		if(z==0){
			for(int j=i; j<=n; j++){
				strcpy(a[j].key,a[j+1].key);
				strcpy(a[j].data,a[j+1].data);
				a[j].second=a[j+1].second;
				a[j].start_time = a[j+1].start_time;
			}
			n--;
			return printf("\n Deleted item successfuly!");
		}
//		if(z == 0){
//			reset_string(a[i].key);
//			reset_string(a[i].data);
//			a[i].second = 0;
//			a[i].start_time = 0;
//			cpystr(a[i].key,n,i);
//			cpystr(a[i].data,n,i);
//			for(int j = i+1; j<n;j++){
//				a[i].second = a[j].second;
//				a[i].start_time = a[j].start_time;
//			}
//			return printf("\n Deleted item successfuly!");	
//			n--;
//		}
	}
	return printf("\n Item not found!");
}

int flush_item(memcache a[], int &n){
	for(int i = 0; i < n; i++){
		reset_string(a[i].key);
		reset_string(a[i].data);
		a[i].second = 0;
		a[i].start_time = 0;
		cpystr(a[i].key,n,i);
		cpystr(a[i].data,n,i);
		for(int j = i+1; j<n;j++){
			a[i].second = a[j].second;
			a[i].start_time = a[j].start_time;
		}
	}
	n = 0;
	return printf("\n Flushed all the items.");
}

int main()
{
	int count =0;
	memcache info[100];
	int n = 0;
	int op=0;
	
	do{
		Reset:fflush(stdin);
		system("cls");
		printf("1. Store data.\n");
		printf("2. Retrie item.\n");
		printf("3. Delete item.\n");
		printf("4. Flush all the item.\n");
		printf("5. Exit the program.");
			flag:fflush(stdin);
			op = getch();
		
		switch(op){
			case '1':	store(info,n);				
				break;
			case '2':	retrie(info,n);
				break;
			case '3':	delete_item(info,n);
				break;
			case '4':	flush_item(info,n);
				break;
			case '5': printf("\n\nLeaving....\n");
				break;
			default:	printf("\nWrong format!");
				count++;
				if(count == 5){
					count=0;
					goto Reset;
				}
				goto flag;
				break;
		}
		getch();	
	}
	while(op != '5');
}
