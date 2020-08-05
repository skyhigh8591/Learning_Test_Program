#include<stdio.h>
#include<stdlib.h>
#define MAX 3

	union paid{
		char creditCard[21];
		char bankAccount[16];
		int iCash;
	};
	
	
	int main(void)
	{
		union paid money;
		printf("sizeof(money)=%2d\n",sizeof(money));
		printf("Please enter a bank account number: ");
		scanf("%s",&money.bankAccount);
		printf("Bank:%s\n",money.bankAccount);
		printf("Please enter a Credit card number: ");
		scanf("%s",&money.creditCard);
		printf("Card: %s\n",money.creditCard);
		printf("Please enter a cash amount: ");
		scanf("%s",&money.iCash);
		printf("Casd:%4d\n",money.iCash);
		system("pause");
		return 0;
	}
	
