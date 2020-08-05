#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	int hour;
	
	
	
	printf("Please input the 24-hour system => ");
	scanf("%d",&hour);
	hour = (hour>=12)?hour-12:hour;
	printf("Present time: %d\n",hour);
	

	system("pause");
	return 0;
	
}
