#include <stdio.h>
#include <stdlib.h>
void peri(double);
void area(double);
const double pi=3.14;

int main(void)
{
	double r=1.0;
	printf("pi=%.2f\n",pi);
	printf("radius=%.2f\n",r);
	peri(r);
	system("pause");
	return 0;
}

void peri(double r)
{

	printf("Circumference=%.2f\n",2*pi*r);
}

void area(double r)
{
	printf("Circular area=%.2f\n",pi*r*r);
}
