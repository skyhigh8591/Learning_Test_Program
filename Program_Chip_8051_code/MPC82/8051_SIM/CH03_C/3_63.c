/********* 3_63.c ***�����ƽd��***************
*�ʧ@�G��KEY1(P32)��Jbit��ơA��P00��X
*�w��GSW1-3(P0LED)ON,��KEY1 
*************************************************/
#include "..\MPC82.H"  //�Ȧs���βպA�]�w
main()
{
   bit flag; //�ŧi�줸�ܼ�
   P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  loop:
    flag=KEY1; //KEY1(P32)��Jbit���
    P0_0=_testbit_(flag);//���զ줸�ܼƤο�X
    Delay_ms(100); //����
    goto loop;
}
