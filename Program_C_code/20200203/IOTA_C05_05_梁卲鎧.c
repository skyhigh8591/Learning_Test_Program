#include <stdio.h>
#include <stdlib.h>
float bill(float);
int main(void){
	float a,i;
	float max;		
	printf("輸入使用分鐘");
	scanf("%f",&i);	
	a = i;
	max = bill(a);
 	printf("應繳金額%4.2f元\n",max);	
	system("pause");
	return 0;
}

float bill(float a){
	float x,z;
	int q;	
	if(a<30){
		printf("不滿30分免費\n");
		}
	else if(a>30) {
		if(a>450){
			return 240;
		}
		else{
		 	q = (int)a;
		 	q = q-60;		 	
		 	if (q%30 ==0){
		 		q = q/30;
		 		z=30+q*15;
		 		return z;
			 }
			 else{
			 	q = q/30;
			 	q = q+1;
				z=30+q*15;
				return z;
			 }			 			
		}			
	}			
}
