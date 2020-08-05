#include<stdio.h>
#include<stdlib.h>
#define MAX 3
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
			if((key=='R')||(key=='G')||(key=='B'))
			{
				key = key+32;
			}
			
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
