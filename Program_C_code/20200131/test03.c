#include <stdio.h>
#include <stdlib.h>

float bill(float);

int main(void)
{
	float a,i;
	float max;	

	
	printf("��J�ϥΤp��");
	scanf("%f",&i);	
	a = i;

	max = bill(a);
 
 	printf("���B����%4.2f��\n",max);	
	system("pause");
	return 0;
}

float bill(float a)
{
	float x;
	if(a<50)
	{
		x = a*0.1;
		}
	else
	{
		x=a*0.2	;	
	}
	return x;
		
}
