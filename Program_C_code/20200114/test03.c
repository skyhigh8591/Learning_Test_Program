#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,b,c,max;
	char x;
	
		printf("块计1\n");	
		scanf("%d",&a);	
		fflush(stdin);
		printf("块计2\n");	
		scanf("%d",&b);	
		fflush(stdin);
		printf("块计3\n");	
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

		printf("%d\n%c程\n",max,x);
		
	system("pause");
	return 0;	
}	                           
