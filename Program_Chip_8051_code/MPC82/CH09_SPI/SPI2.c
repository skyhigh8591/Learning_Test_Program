/********SPI2.C***********SPI�D�Ҧ��o�g�d��*****************
*�\��J�ϥ�SPI�ɭ�MOSI�o�g��C���
*�w��GSW1-3(P0LED)ON�A��J12(SPI)�s���t�@����ߪO��J12(SPI)
************************************************************/
#include "..\MPC82.H"
void main(void)
{
  unsigned char i=0;//�p��
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  SPCTL = SSIG+SPEN+MSTR+3;//����SS�}�B�P�ରMaster�A�t��Fosc/128
  while(1)
  {	
	SS=0;	        //SS(P14)=0�A�P��Slave����	
	LED=~i;		    //�p�ƥ�LED��X
	SPDAT = i++;    //�g�J��ƶ}�l�o�g
	while((SPSTAT & SPIF)==0);//�YSPIF=0���o�g�����A���ݤ�
	SPSTAT = SPIF; //�M��SPI�X��	
	Delay_ms(1000);
	SS=1;		    //SS(P14)=1�A�T��Slave����
  }
}