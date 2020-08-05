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
		
		printf("輸入你的數字\n");
		scanf("%d",&z);
		
		if(z%2==0)
		{
			
				while(i<=z)
				{
					
					num = num + i;
					i+=2;
				}
				
			printf("總和%d\n",num);	
			flag=flag+1;
			
		}
		else
		{
			printf("輸入錯誤 請輸入正偶數\n");		
		}		
	}while(flag<=0);
	
	
	///////////////////////////////////////
	system("pause");
	return 0;
	
}
