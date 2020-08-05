#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int main(void)
{
	int i , m , index=0;
	struct data{
		char name[10];
		int math;
	}student[MAX]={{"Mary",87},{"Flora",73},{"Jenny",94}};
	m=student->math;
	for(i=0;i<MAX;i++)
	{
		if((student+i)->math>m)
		{
			m=(student+i)->math;
			index=i;
		}
	}
	printf("Name: %s\n",(student+index)->name);
	printf("Name: %d\n",(student+index)->math);
	
	
	

	
	system("pause");
	return 0;
}
