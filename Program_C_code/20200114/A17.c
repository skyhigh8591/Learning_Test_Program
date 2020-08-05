#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  int num;
  char ch;
 
  	printf("Please input an integer:");	
	scanf("%d",&num);
	fflush(stdin);
	printf("Please input an character:");
  	scanf("%c",&ch);
  	printf("nu=%d,ASCII oc ch=%d\n",num,ch);
 
	system("pause");
	return 0;	
}	
