/********** UART11.c ****UART2��mode 1�����εo�g���_********
*�ʧ@�G�ϥ�UART2�A�ӤH�q��UART�e�X�r���A��RXD2�}�����A�bLED��ܡA
*      �å�TXD2�}�o�g�^�ӤH�q��
*�w��GSW1-3(P0LED)��SW3-5~6(TxD2,RxD2)ON
***********************************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
void UART2_init(unsigned int bps);  //UART�ҩl�{��
main()
{
  UART2_init(9600); //�]�wUART2��C���Ҥ��j�v
  EA=1; AUXIE=ES2;  //�P��UART2��C���_
  while(1);   //�ۧڪ���A��ܥi���䥦�u�@
}
//**********************************************************
void SCON_int (void)  interrupt 12  //��C���_��� 
 {
   if(S2CON & S2RI)  //�Y�������Ҳ��ͪ����_
    {
     S2CON &= ~S2RI;   //�M�������X�ХOS2RI=0
     LED = ~S2BUF;     //�N�����쪺�r����LED��X
	 S2BUF = ~LED;     //�Ntemp�o�g�X�h
	}
	else S2CON &= ~S2TI; //�Y���o�g�Ҳ��ͪ����_�A�M���o�g�X�ХOS2TI=0
 }
/***********************************************************
*��ƦW��: UART2_init
*�\��y�z: UART2�ҩl�{��
*��J�ѼơGbps
************************************************************/
void UART2_init(unsigned int bps)  //UART�ҩl�{��
{  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
   S2CON=0x50;     //�]�wUART2��C�ǿ鬰MODE1�έP�౵��
   S2BRT=256-(57600/bps);  //�]�wUART2�ǿ�t�v
   AUXR2=S2TR;      //UART2�Ұ�
}