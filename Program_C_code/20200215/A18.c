#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	int main(void)
	{
		char key;
		enum color
		{
			red=114,
			green=103,
			blue=98
		}shirt;
		do{
			printf("Please input (r,g,b): ");
			scanf("%c",&key);
			fflush(stdin);
		}while((key!=red)&&(key!=green)&&(key!=blue));
		shirt=key;
		switch(shirt)
		{
			case red:
				printf("You selected red\n");
				break;
			case green:
				printf("You selected green\n");
				break;	
			case blue:
				printf("You selected blue\n");
				break;	
				
		}
		system("pause");
		return 0;
	}
	
