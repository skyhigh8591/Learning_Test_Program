#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  
	int a,b,c,e;


		printf("�ï]�����R�X�~\n");	
		scanf("%d",&a);	
		fflush(stdin);
		printf("�Q�s���K�R�X�~\n");	
		scanf("%d",&b);	
		fflush(stdin);
		c=(a*45)+(b*55);		
		if((a + b) > 15)   
		{
			
			if(c>800)
			{
				c = c* 0.9;
				printf("�W�L15�~ �ùF 800�� ��9��\n");
				printf("�ï]�����R%d\n",a);	
				printf("�Q�s���K�R%d\n",b);
				printf("��������%d\n",c);
				
			}
			
		}
	    else
			{
			printf("�ï]�����R%d\n",a);	
			printf("�Q�s���K�R%d\n",b);
			printf("����%d\n",c);
			}
		
	system("pause");
	return 0;	
}	                           
