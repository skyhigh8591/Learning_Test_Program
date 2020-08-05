#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int main(void)
{
	
	
	struct employee
	{
		char id[7];
		char name[20];
		int salary;
	};
	struct employee manager={"A54321","William",35000};
	struct employee *ptr;
	ptr=&manager;
	printf("&ptr = %p\n",&ptr);
	printf("ptr= %p\n",ptr);
	printf("&manager= %p\n",&manager);
	printf("ID: %s\n",ptr->id);
	printf("Name: %s\n",ptr->name);
	printf("salary: %d\n",ptr->salary);
	system("pause");
	return 0;
}
