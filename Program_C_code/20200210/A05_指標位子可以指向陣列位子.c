#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	double a[4]={3,5,7,9};
	printf("a[0]=%.1f,*(a+0)=%.1f\n",a[0],*(a+0));
	printf("a[1]=%.1f,*(a+1)=%.1f\n",a[1],*(a+1));
	printf("a[2]=%.1f,*(a+2)=%.1f\n",a[2],*(a+2));
	printf("a[3]=%.1f,*(a+3)=%.1f\n",a[3],*(a+3));
	system("pause");
	return 0;
}

