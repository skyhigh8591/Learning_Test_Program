#include <stdio.h>
#include <stdlib.h>
#define PASSWD 1234

int main(void)
{
	int passwd;
	int flag=0;
	int retry=1;
	do
	{
		printf ("²Ä%d¦¸ enter your password:\n",retry++);
		scanf("%d",&passwd);
		fflush(stdin);
		if (passwd==PASSWD)
			flag=1;
	}while(!flag&&(retry<=3));
	
	if (flag==1)
		printf("congulation!\n");
	else
		printf("You are rejected!\n");
	
	system("pause");
	return 0;
}
