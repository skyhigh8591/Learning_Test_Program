#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	
	
	struct data
	{
		
		char name[15];
		int math;
		int eng;
	}student;
	struct data *ptr;
	ptr=&student;
	printf("Name: ");
	gets(ptr->name);
	printf("Math: ");
	scanf("%d",&ptr->math);
	printf("English: ");
	scanf("%d",&ptr->eng);
	printf("Average= %.2f\n",(ptr->math+ptr->eng)/2.0);

	
	system("pause");
	return 0;
}
