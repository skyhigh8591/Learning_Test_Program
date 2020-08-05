/********SPI3.C**********SPI接收中斷範例******************
*功能︰使用SPI界面中斷接收串輸入資料，同時由LED輸出。
*硬體：SW1-3(P0LED)ON，由J12(SPI)連接另一片實習板的J12(SPI)
********************************************************/
#include "..\MPC82.H"
void main(void)
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  SPCTL = SPEN;  // 致能為Slave
  EA=1; AUXIE = ESPI;	 //致能SPI中斷
  while (1);	 //空轉，等待接收資料，表示可做其它工作
}

void SPI_ISR() interrupt 8	 //SPI中斷函數
{	
	SPSTAT = SPIF; //清除SPI旗標
	LED=~SPDAT;     //讀取SPI接收到的資料到LED顯示
}  

		

			 
			 