#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	struct data
	{
		char name[20];
		int math;
	}student;
	printf("Please type in your name :");
	gets(student.name);
	printf("Please input a score:");
	scanf("%d",&student.math);
	printf("Name: %s\n",student.name);
	printf("Score: %d\n",student.math);
	
	system("pause");
	return 0;
}

