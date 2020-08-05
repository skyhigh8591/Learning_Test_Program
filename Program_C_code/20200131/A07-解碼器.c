#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char str[50];
	int i;
	scanf("%s",str);
	
	if(str[0]=='+')
	{
		for(i=1;i<strlen(str);i++) // strlen(str) ¦r¦êªø«× 
		{
			str[i]+=2;
			if(str[i]>'Z')
			{
				str[i]-=26;
			}
		}
	}
	
	if(str[0]=='-')
	{
		for(i=1;i<strlen(str);i++)
		{
			str[i]-=2;
			if(str[i]<'A')
			{
				str[i]+=26;
			}
		}
	}
	
	printf("%s\n",str+1);
		
	system("pause");
	return 0;
}

