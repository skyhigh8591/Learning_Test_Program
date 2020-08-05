#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a=0, b=0, c=0;		
	while(a<=100)
	{
		if(a%2 ==1)
		{
			b=b+a;
			a++;
		}
		else
		{
			c=c+a;
			a++;		
		}
				
	}	
	printf("奇數總和%d\n",b);
	printf("偶數總和%d\n",c);	
	system("pause");
	return 0;
}


