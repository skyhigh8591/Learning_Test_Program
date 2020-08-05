#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,b;
	
		printf("輸入攝氏溫度\n");	
		scanf("%d",&a);	
		fflush(stdin);
		b=1.8*a+32;
		printf("華氏溫度為%d度\n",b);	
		
		
	system("pause");
	return 0;	
}	                           
