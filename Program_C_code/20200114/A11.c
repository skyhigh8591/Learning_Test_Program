#include<stdio.h>
#include<stdlib.h>
int main(void)
{

    char grade;
    printf("Please input a grade:(A or a)");
    scanf("%c",&grade);
    switch(grade)
    {
    	case'A':
    	case'a':
    	{
    		printf("Excellent!\n");
    		break;
		}
		case'B':
		case'b':
    	{
    		printf("Good!\n");
    		break;
		}
		case'C':
		case'c':
    	{
    		printf("Be study hard!\n");
    		break;
		}
		default:
		{
			printf("Fail\n");
		}	
	}	
	system("pause");
	return 0;	
}	
