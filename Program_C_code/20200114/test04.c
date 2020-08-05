#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,b,c,e;


		printf("珍珠奶茶買幾瓶\n");	
		scanf("%d",&a);	
		fflush(stdin);
		printf("烏龍拿鐵買幾瓶\n");	
		scanf("%d",&b);	
		fflush(stdin);
		c=(a*45)+(b*55);		
		if((a + b) > 15)   
		{
			
			if(c>800)
			{
				c = c* 0.9;
				printf("超過15瓶 並達 800元 打9折\n");
				printf("珍珠奶茶買%d\n",a);	
				printf("烏龍拿鐵買%d\n",b);
				printf("打折後價格%d\n",c);
				
			}
			
		}
	    else
			{
			printf("珍珠奶茶買%d\n",a);	
			printf("烏龍拿鐵買%d\n",b);
			printf("價格%d\n",c);
			}
		
	system("pause");
	return 0;	
}	                           
