#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,r;
	while(1)
	{
		do
		{
		printf("input an integer:");	
		scanf("%d",&a);	
		fflush(stdin);
		}while(a<=0)
		printf("The reverse is ");
		while(a!=0)
		{
			r=a%10;
			a/=10;
			printf("%d",r);	
		}
		printf("n\n",r);
	}
	printf("Congratulations! you got it!\n");	
	system("pause");
	return 0;	
}	                           
