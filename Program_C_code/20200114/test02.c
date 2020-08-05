#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,b;
	
		printf("輸入1-4\n");	
		scanf("%d",&a);	
		fflush(stdin);
		switch(a) 
		{
			case(1):
				{
					printf("春天\n");
					break;
				}
			case(2):
				{
					printf("夏天\n");
					break;
				}
			case(3):
				{
					printf("秋天\n");
					break;
				}
			case(4):
				{
					printf("冬天\n");
					break;
				}
			 default:
			{
				printf("輸入錯誤\n");
			}
		
		}
	system("pause");
	return 0;	
}	                           
