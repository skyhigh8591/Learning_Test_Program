#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	struct data
	{
		char name[15];
		int math;
	};
	struct data student={"Mary Wang",79
	};
	printf("name : %s\n",student.name);
	printf("Score : %s\n",student.math);
	system("pause");
	return 0;
}
