/********** UART10.c *****UART2��MODE1��C�o�g****************
*�ʧ@�G�ϥ�UART2�A�}�C�r����TXD2�}�ǿ�ܭӤH�q��
*�w��GSW3-5(TxD2)ON
**************************************************************/
#include "..\MPC82.H"
char code TABLE[]={"�w��i�JMegawin\n\r"};//�}�C�r�������Ƥθ���
void UART2_init(unsigned int bps);  //UART2�ҩl�{��
main()
{
  unsigned char i=0;
  char *s ;		 //�ŧi�����ܼ�
  UART2_init(9600); //UART�ҩl�{���A�]�w��C���Ҥ��j�v
  while(1)
   {
	 S2BUF=i+'0';	//�o�g�p�ƭ�
  	 while((S2CON & S2TI)==0);  //�YS2TI=0��ܥ��o�g�����A�A�~���ˬd
	 S2CON &= ~S2TI;	        //�YS2TI=1��ܤw�o�g�����A�OS2TI=0  
	 
	 for(s=TABLE;*s != '\0' ;)//�}�C�r���p�ƭ�
	  {
	   S2BUF=*s++ ;	//�}�C�r���e��SBUF�A�}�l�o�g
	   while((S2CON & S2TI)==0); //�YS2TI=0��ܥ��o�g�����A�A�~���ˬd
	   S2CON &= ~S2TI ;	        //�YS2TI=1��ܤw�o�g�����A�OS2TI=0
	  }
	 Delay_ms(500);     //����
 	 i++; if(i>9) i=0;	//�p�ƭ�0~9
   }
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
