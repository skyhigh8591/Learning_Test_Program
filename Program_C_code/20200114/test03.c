#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,b,c,max;
	char x;
	
		printf("��J�Ʀr1\n");	
		scanf("%d",&a);	
		fflush(stdin);
		printf("��J�Ʀr2\n");	
		scanf("%d",&b);	
		fflush(stdin);
		printf("��J�Ʀr3\n");	
		scanf("%d",&c);	
		fflush(stdin);
		
		if(a>b)   
		{
		max=a;
		x ='a';
		}
	    else        
		{
	    max=b;
	    x = 'b';
		}
	    if(c>max) 
		{
	    max = c;
	    x = 'c';
		}

		printf("%d\n%c�̤j\n",max,x);
		
	system("pause");
	return 0;	
}	                           
