#include<stdio.h>
#include<stdlib.h>


int main(void)
{
		int i,n;
		float sum;
		int str1[7];
		
		for( i = 1 ; i <= 7 ; i++)
		{	
		printf("��J��%d���Ʀr",i);
		scanf("%d",&n);
		str1[i] = n;
		
		sum = (float) str1[i] + (float) sum;
		
		}
				
		sum= sum/7;
		printf("�����Ƶ���%f\n",sum);
		
	system("pause");
	return 0;		
}

