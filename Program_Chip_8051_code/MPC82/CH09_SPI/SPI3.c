/********SPI3.C**********SPI�������_�d��******************
*�\��J�ϥ�SPI�ɭ����_�������J��ơA�P�ɥ�LED��X�C
*�w��GSW1-3(P0LED)ON�A��J12(SPI)�s���t�@����ߪO��J12(SPI)
********************************************************/
#include "..\MPC82.H"
void main(void)
{
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  SPCTL = SPEN;  // �P�ରSlave
  EA=1; AUXIE = ESPI;	 //�P��SPI���_
  while (1);	 //����A���ݱ�����ơA��ܥi���䥦�u�@
}

void SPI_ISR() interrupt 8	 //SPI���_���
{	
	SPSTAT = SPIF; //�M��SPI�X��
	LED=~SPDAT;     //Ū��SPI�����쪺��ƨ�LED���
}  

		

			 
			 