#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,b;
	
		printf("��J1-4\n");	
		scanf("%d",&a);	
		fflush(stdin);
		switch(a) 
		{
			case(1):
				{
					printf("�K��\n");
					break;
				}
			case(2):
				{
					printf("�L��\n");
					break;
				}
			case(3):
				{
					printf("���\n");
					break;
				}
			case(4):
				{
					printf("�V��\n");
					break;
				}
			 default:
			{
				printf("��J���~\n");
			}
		
		}
	system("pause");
	return 0;	
}	                           
