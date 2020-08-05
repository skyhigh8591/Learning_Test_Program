#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	
	
	
	int i,sum = 0,TALL = 0;
	for(i=1;i<=10;i++)
	{
		
		
		
		
		sum = i * i;
		TALL += sum;
		printf("sum = %d * %d\n",i,i);
		printf("%d\n",sum);
		printf("%d\n",TALL);	
	}
	system("pause");
	return 0; 
}
