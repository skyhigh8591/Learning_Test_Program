/********SPI2.C***********SPI主模式發射範例*****************
*功能︰使用SPI界面MOSI發射串列資料
*硬體：SW1-3(P0LED)ON，由J12(SPI)連接另一片實習板的J12(SPI)
************************************************************/
#include "..\MPC82.H"
void main(void)
{
  unsigned char i=0;//計數
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  SPCTL = SSIG+SPEN+MSTR+3;//忽略SS腳、致能為Master，速度Fosc/128
  while(1)
  {	
	SS=0;	        //SS(P14)=0，致能Slave晶片	
	LED=~i;		    //計數由LED輸出
	SPDAT = i++;    //寫入資料開始發射
	while((SPSTAT & SPIF)==0);//若SPIF=0未發射完畢，等待之
	SPSTAT = SPIF; //清除SPI旗標	
	Delay_ms(1000);
	SS=1;		    //SS(P14)=1，禁能Slave晶片
  }
}