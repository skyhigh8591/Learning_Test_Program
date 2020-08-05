#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	char guess;
	while(guess!='e')
	{
		printf("Please a to z:");	
		scanf("%c",&guess);
		fflush(stdin);
		if(guess!='e')
		{
			printf("You guess wrong,guess again!\n");
		}
		
	}
	printf("Congratulations! you got it!\n");	
	system("pause");
	return 0;	
}	
