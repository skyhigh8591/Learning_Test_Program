#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int i = 0;
	char str[40];
	printf("Please input a string:");
	gets(str);
	while(str[i]!='\0')
	{
		if(str[i]>=65&&str[i]<=90)
		{
			str[i]+=32;
		}
		i++;
	}
	printf("Uppercase converted to lowercase: %s\n" ,str);
	
	
	system("pause");
	return 0;		
}

