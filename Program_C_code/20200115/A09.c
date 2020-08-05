#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double data[5];
	printf("Array: %d\n",sizeof(data));  //double is 8 bytes
	
//	int score[5];
//	score[0]=55;
//	score[1]=66;
//	score[2]=65;
//	score[3]=98;
//	score[4]=74;
//	for (i=0;i<5;i++)
//		printf("score[%d]=%d\n",i,score[i]);
	
	int d1;	
	do{
		printf("¼Æ¦r:");
		fflush(stdin);
	}while(scanf("%d", &d1) != 1);			
   		
	


	system("pause");
	return 0;
}
