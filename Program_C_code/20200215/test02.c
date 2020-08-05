#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int  i;
	struct data
	{
		char CPU[10];
		char OS[20];
		int RAM;
		int SSD;
	}COMP;

		printf("CPU: ");
		gets(COMP.CPU);
		printf("OS: ");
		gets(COMP.OS);
		printf("RAM: ");
		scanf("%d",&COMP.RAM);
		printf("SSD: ");
		scanf("%d",&COMP.SSD);

		printf(" CPU: %s OS: %s\n",COMP.CPU,COMP.OS);
		printf(" RAM: %dG SSD: %dG\n",COMP.RAM,COMP.SSD);
	
	

	
	
	
	system("pause");
	return 0;
}
