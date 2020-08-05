#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	struct data
	{
		char name[20];
		int math;
	}student;
	printf("sizeof(student)=%d\n",sizeof(student));	
	system("pause");
	return 0;
}

