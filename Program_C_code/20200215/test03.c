#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int main(void)
{
	struct data
	{
		char name[15];
		int age;
		int math;
	}student[MAX];
	struct data *ptr;
	ptr=&student;
	
	
		printf("Name: ");
		gets(ptr->name);
		printf("Age: ");
		scanf("%d",&ptr->age);
		printf("Math: ");
		scanf("%d",&ptr->math);
		fflush(stdin);
		printf("\n");
		
		printf("Name =%s\n",ptr->name);
		printf("Age =%d\n",ptr->age);
		printf("Math =%d\n",ptr->math);
		
	
	
	
	system("pause");
	return 0;
}
