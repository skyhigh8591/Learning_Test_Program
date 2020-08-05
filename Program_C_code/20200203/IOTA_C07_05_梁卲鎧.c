#include <stdio.h>
#include <stdlib.h>
float bill(float);
float bill2(float);

int main(void)
{
	float a,i;
	float max,max2;		
	printf("輸入使用里程");
	scanf("%f",&i);	
	a = i;
	max = bill(a);	
	printf("輸入使用時間");
	scanf("%f",&i);	
	a = i;
	max2 = bill2(a);	
	max = max + max2; 
 	printf("應繳金額%4.2f元\n",max);	
	system("pause");
	return 0;
}

float bill(float a)
{
	float x,z;
	int q;
	
	if(a<1250)
	{
		return 70;
	}
	else
	{
		q = (int)a;
		q = q-1250;
		if (q%200 ==0)
		{
		 	q = q/200;
		 	z=70+q*5;
		 	return z;
		 }
		 else
		 {
		 	q = q/200;
		 	q = q+1;
			z=70+q*5;
			return z;
		 }			
	}		
}
float bill2(float a)
{
	float x,z;
	int q = 0;		
	q = (int)a;
		if (q%80 ==0)
		{
		 	q = q/80;
		 	z=q*5;
		 	return z;
		 }
		else
		{
			q = q/80;
			q = q;
			z=q*5;
			return z;
		 }			
			
}
