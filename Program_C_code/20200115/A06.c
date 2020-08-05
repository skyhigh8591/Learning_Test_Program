#include<stdlib.h>
#include<stdio.h>
#define PASSWD 1234

int main(void)
{
	int i;
	for(i=1;i<=10;i++)
	{
		if(i%4==0)
		{
			break;
		}
		printf("i=%d\n",i);
	 } 
	

	///////////////////////////////////////
	system("pause");
	return 0;
	
	
	
	
	
	
	
}

