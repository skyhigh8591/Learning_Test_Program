#include<stdio.h>
#include<stdlib.h>
int main(void)
{

   int i = 1 , sum = 0;
   while(i<=10)
   {
   	sum+=i;
   	i=i+1;
   }
   printf("Accumulate %2d\n",sum);
	system("pause");
	return 0;	
}	
