/********SPI1.C***********SPI�ۧڶǿ�d��*****************
*�\��J�ϥ�SPI�ɭ�MOSI�o�g��C��ơA��MISO�����bLED��X�C
*�w��GSW1-3(P0LED)ON�AP15(MOSI)�s��P16(MISO)
**********************************************************/
#include "..\MPC82.H"
void main(void)
{
  unsigned char i=0;//�p��
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  SPCTL = SSIG+SPEN+MSTR+3;  //����SS�}�B�P�ରMaster�A�t��Fosc/128
  while(1)
  {	
	SPDAT = i++;	           //�g�J��C��ơA�OTHRE=1
	while(SPSTAT & WCOL);  //�YWCOL=0�A��ܵo�g��ƽw�ľ��w��(Empty)
	Delay_ms(1000);	    //�}�l��C�o�g��ơA���ɡA�t�@�ݦ�C����
	while((SPSTAT & SPIF)==0); //�YSPIF=0�����������A���ݤ�
	SPSTAT = SPIF;   //�M��SPI�X��	
	LED=~SPDAT;	     //������C��ƥ�LED��X
  }
}
