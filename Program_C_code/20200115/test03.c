#include<stdlib.h>
#include<stdio.h>
#define MAX 5

int main(void)
{
	int z;
	int flag=0;
	int num=0;
	int i = 0;
	
	do
	{
		
		printf("��J�A���Ʀr\n");
		scanf("%d",&z);
		
		if(z%2==0)
		{
			
				while(i<=z)
				{
					
					num = num + i;
					i+=2;
				}
				
			printf("�`�M%d\n",num);	
			flag=flag+1;
			
		}
		else
		{
			printf("��J���~ �п�J������\n");		
		}		
	}while(flag<=0);
	
	
	///////////////////////////////////////
	system("pause");
	return 0;
	
}
