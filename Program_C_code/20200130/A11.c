#include<stdio.h>
#include<stdlib.h>
void display(char,int);

int main(void)
{
	int n;
	char ch;
	printf("Please inpuy a character:");
	scanf("%c",&ch);
	fflush(stdin);
	printf("How many characters do you want to print");	
	scanf("%d",&n);
	fflush(stdin);	
	display(ch,n);	
	system("pause");
	return 0;		
}

void display(char ch , int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%c",ch);
	}
	printf("\n");
}
