#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int cups=8;
	float discount=0.85f;
	
	printf("Buy %d cups, total %d dollars\n",cups,35*cups);
	printf("Buy %d cups and get a disciunt %4.2f\n",cups+2,discount); //邏輯錯誤 要記得帶入是依照順序 

	
	
	
	system("pause");
	return 0;
	
	
	
	
	
	
	
	
	 
}
