#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	struct data
	{
		char name[15];
		int sex;
		int age;
	}stu1={"john",1,18},stu2={"Mary",0,19};	
	printf("%s Gender\n",stu1.name);
	if(stu1.sex==1)
	{
		printf("Male");
	}
	else
	{
		printf("Female");
	}
	printf("\nAge: %2d\n",stu1.age);
	printf("%s Gander: ",stu2.name);
	if(stu2.sex==1)
	{
		printf("Male");
	}
	else
	{
		printf("Female");
	}
	printf("\nAge: %2d\n",stu2.age);
	

	system("pause");
	return 0;
}
