#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	int x=65;
	char A='A',B='B';
	float fx=65.0f;
	
	
	printf("%d==%c =%d\n",x,A,x==A);
	printf("%d>%c =%d\n",x,B,x>B);
	printf("%c>%c =%d\n",B,A,B>A);
	printf("%.1f==%c =%d\n",fx,A,fx==A);
	printf("%.1f>%c =%d\n",fx,B,fx==B);


	system("pause");
	return 0;
	
}
