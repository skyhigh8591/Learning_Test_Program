#include<stdlib.h>
#include<stdio.h>
#define PASSWD 1234

int main(void)
{
	int i;
	for(i=1;i<=13;i++)
	{
		if(i%2==0)
		{
			continue;
		}
		else if(i==11)
		{
			break;
		}
		printf("i=%d\n",i);
	 } 
	

	///////////////////////////////////////
	system("pause");
	return 0;
	
	
	
	
	
	
	
}

