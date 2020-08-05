#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	char ss[3][10] = {"Tom","Lily","Bruce Lee"};
	int i ;
	for(i=0;i<3;i++)
	{
		printf("ss[%d]=%s\n",i,ss[i]);
	}
	printf("\n");
	
	
	
	
	system("pause");
	return 0;		
}

