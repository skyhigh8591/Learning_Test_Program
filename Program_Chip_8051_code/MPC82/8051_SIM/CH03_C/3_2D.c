//******** 3_2D.c *********************************
//*�ʧ@�G�ϥμȦs���W�٩w�q��
//*�w��GSW1-3(P0LED)��SW1-4(P1LED)ON
//*************************************************
#include "..\MPC82.H"  //�Ȧs���βպA�]�w
void main()
{  
   unsigned char i=0;
   P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
   loop:
   P0=~i;  Delay_ms(100);
   i=i+1;

   P1_1=0;  Delay_ms(100);
   P1_1=1;  Delay_ms(100); 
   goto loop;  //����loop�B 
}
