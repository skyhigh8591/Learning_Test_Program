#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int num;
	
	printf("Please input an integer:");
	scanf("%d",&num);
		if(num>0)
		{
			printf("You enter an integer than 0\n");	
		}
		else if(num<=0)
		{	
		printf("You enter an integer less than or equal to 0\n");		
		}	
	system("pause");
	return 0;
	
	
	
	
	
	
	
	
	 
}
