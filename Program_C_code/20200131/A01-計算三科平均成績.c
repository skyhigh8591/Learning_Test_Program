#include <stdio.h>
#include <stdlib.h>
float get_score(void);
char level(float,float,float);

int main(void)
{
	float s1,s2,s3;
	char grade;
	
	s1=get_score();
	s2=get_score();
	s3=get_score();
	
	grade=level(s1,s2,s3);
	
	
	printf("Your score grade is %c\n",grade);
	//---------------	
	system("pause");
	return 0;
}
float get_score(void)
{
	float temp;
	printf("Please input your csore:");
	scanf("%f",&temp);
	return temp; 
}
char level(float s1,float s2,float s3)
{
		float avg;
		printf("\n Score:%.1f %.1f %.1f\n",s1,s2,s3);
		avg=(s1+s2+s3)/3;
		printf("Average=%4.1f\n",avg);
		if (avg>=90)
			return 'A';
		if (avg>=80)
			return 'B';
		if (avg>=70)
			return 'B';
		if (avg>=60)
			return 'D';
		return 'E';
}

