/********SPI1.C***********SPI自我傳輸範例*****************
*功能︰使用SPI界面MOSI發射串列資料，由MISO接收在LED輸出。
*硬體：SW1-3(P0LED)ON，P15(MOSI)連接P16(MISO)
**********************************************************/
#include "..\MPC82.H"
void main(void)
{
  unsigned char i=0;//計數
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  SPCTL = SSIG+SPEN+MSTR+3;  //忽略SS腳、致能為Master，速度Fosc/128
  while(1)
  {	
	SPDAT = i++;	           //寫入串列資料，令THRE=1
	while(SPSTAT & WCOL);  //若WCOL=0，表示發射資料緩衝器已空(Empty)
	Delay_ms(1000);	    //開始串列發射資料，延時，另一端串列接收
	while((SPSTAT & SPIF)==0); //若SPIF=0未接收完畢，等待之
	SPSTAT = SPIF;   //清除SPI旗標	
	LED=~SPDAT;	     //接收串列資料由LED輸出
  }
}
