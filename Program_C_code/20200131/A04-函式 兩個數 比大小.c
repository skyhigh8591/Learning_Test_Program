#include <stdio.h>
#include <stdlib.h>
int get_int(void);
int find(int,int);

int main(void)
{
	int a,b;
	int max;
	a=get_int();
	b=get_int();
	
	max=find(a,b);
	printf("\n max(%d %d) is %d.\n",a,b,max);
	
	system("pause");
	return 0;
}

int get_int(void)
{
	int num;
	printf("Please input an integer: ");
	while(scanf("%d",&num)!=1)
	{
		while(getchar()!='\n')
		{
			continue; //程式如果只有一行 可以省略括號 
		}
		printf("Input error! Please input again: ");	
	}
	return num;
}
int find(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
