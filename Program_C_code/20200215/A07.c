#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	struct data
	{
		char name[10];
		int math;
	}student[15];
	printf("sizeof(student)=%d\n",sizeof(student));
	
	
	
	system("pause");
	return 0;
}
