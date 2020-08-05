#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int tea,coffee,total;
	printf("How many bottles of black tea do you want to buy:");
	scanf("%d",&tea);
	printf("How many bottles of coffee do you want to buy:");
	scanf("%d",&coffee);
	total=tea*25+coffee*35;
	printf("Price %d\n",total);
	
	
	
	system("pause");
	return 0;
	
	
	
	
	
	
	
	
	 
}
