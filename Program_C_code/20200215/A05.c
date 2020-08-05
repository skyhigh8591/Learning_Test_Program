#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	struct data
	{
		char name[15];
		int sex;
		int age;
	}stu1={"john",1,18};
	struct data stu;
	stu=stu1;
	printf("stu1.name = %s,	stu1.sex = %d,	stu1.age = %d\n",stu1.name,stu1.sex,stu1.age);
	printf("stu.name  = %s,	stu.sex = %d,	stu.age = %d\n",stu.name,stu.sex,stu.age);
	

	system("pause");
	return 0;
}
