#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int arr[2][4]={{2,3,4,5},{6,7,8,9}};
	
	printf("�e%d\n",*(*(arr+1)+1));
	printf("��%d\n",(*(*(arr+1)+1)+3));
	
	
	
	system("pause");
	return 0;
}

