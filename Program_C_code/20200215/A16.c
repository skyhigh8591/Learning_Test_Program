#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	union paid{
		char creditCard[21];
		int Cash;
	};
	
	
	int main(void)
	{
		union paid money;
		int Amt=1500,Opt;
		printf("Amounts payable: %d\n",Amt);
		do
		{
			printf("Choose payment method (1) Credit Card(2) Cash :");
			scanf("%d",&Opt);
			fflush(stdin);
			if(Opt==1)
			{
				printf("Please enter tour card number: ");
				gets(money.creditCard);
				if(strlen(money.creditCard)!=16)
				{
					printf("Card umber error! Please re-operate!\n");
					Opt=0;
				}
				else
				{
					printf("Payment completed!\n");
				}
			}
			else if(Opt==2)
			{
				printf("Please enter the amount of cash: ");
				scanf("%d",&money.Cash);
				if(money.Cash<Amt)
				{
					printf("Insufficient amount! Please try agaim\n");
					Opt=0;
				}
				else
				{
					printf("Give change: %3d\n",money.Cash-Amt);
				}	
			}
			else
			{
				printf("Please enter the correct payment mothod \n");
			}
		}while (Opt!=1&&Opt!=2);
		system("pause");
		return 0;
	}
	
