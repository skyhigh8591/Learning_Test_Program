#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int z;
  char c;
  char arr[50];

  int a=0,e=0,i=0,o=0,u=0;  

  printf("Input a string: ");
  gets(arr);
	
  for(z=0;z<50;z++) {
                          
    switch(arr[z]) { 

      case 'a': a++; break;
      
      case 'e': e++; break;

      case 'i': i++; break;

      case 'o': o++; break;

      case 'u': u++; break;

      default: break;       

    }                        

  }

  printf("a:%d e:%d i:%d o:%d u:%d\n",a,e,i,o,u);

}
