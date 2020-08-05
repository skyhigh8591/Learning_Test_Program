#include <stdio.h>
#include <stdlib.h>
int get_int(void);
int find(int,int,int,int,int,int);

int main(void)
{
	int a,b,c,d,e,f,i,z;
	int max;	
	int arr[5];
	for(i=0;i<6;i++)
	{	
	printf("輸入%d個數字",i+1);
	scanf("%d",&z);
	arr[i] = z;
	printf("%d\n",arr[i]);

 	}
	a = arr[0];
	b = arr[1];
	c = arr[2];
	d = arr[3];
	e = arr[4];
	f = arr[5];
	
 	max = find(a,b,c,d,e,f);
 	printf("最大值%d\n",max);
 	
	
	system("pause");
	return 0;
}

int find(int a,int b,int c,int d,int e,int f)
{
	int sup,i;
	sup=f;
	for(i=0;i<20;i++)
	{
	if(a>sup)
		sup = a;
	else if (b>sup)
		sup=b;
	else if (c>sup)
		sup=c;
	else if (d>sup)
		sup=d;
	else if (e>sup)
		sup=e;
	else 		
	}
	return sup;		
}
