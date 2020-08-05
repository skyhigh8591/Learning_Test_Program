#include<stdio.h>
#include<stdlib.h>


	struct data{
		char name[15];
		int math;
	};
	void display(struct data);
	
	int main(void)
	{
		struct data s1={"Jenny",88};
		display(s1);
		system("pause");
		return 0;
	}
	void display(struct data st)
	{
		printf("Name: %s\n",st.name);
		printf("Math: %d\n",st.math);
	}
	
