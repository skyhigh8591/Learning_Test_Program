#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int main(void)
{
	int  i;
	struct data
	{
		char name[15];
		int age;
		int math;
	}student[MAX];
	for(i=0;i<MAX;i++)
	{
		printf("Name: ");
		gets(student[i].name);
		printf("Age: ");
		scanf("%d",&student[i].age);
		printf("Score: ");
		scanf("%d",&student[i].math);
		fflush(stdin);
	}
	for(i=0;i<MAX;i++)
	{
		printf("%s Age: %d Score: %d\n",student[i].name,student[i].math);
	}
	printf("sizeof(student)=%d\n",sizeof(student));
	
	
	
	system("pause");
	return 0;
}
