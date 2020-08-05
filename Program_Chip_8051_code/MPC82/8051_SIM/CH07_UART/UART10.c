/********** UART10.c *****UART2的MODE1串列發射****************
*動作：使用UART2，陣列字元由TXD2腳傳輸至個人電腦
*硬體：SW3-5(TxD2)ON
**************************************************************/
#include "..\MPC82.H"
char code TABLE[]={"歡迎進入Megawin\n\r"};//陣列字元中文資料及跳行
void UART2_init(unsigned int bps);  //UART2啟始程式
main()
{
  unsigned char i=0;
  char *s ;		 //宣告指標變數
  UART2_init(9600); //UART啟始程式，設定串列環境及鮑率
  while(1)
   {
	 S2BUF=i+'0';	//發射計數值
  	 while((S2CON & S2TI)==0);  //若S2TI=0表示未發射完畢，再繼續檢查
	 S2CON &= ~S2TI;	        //若S2TI=1表示已發射完畢，令S2TI=0  
	 
	 for(s=TABLE;*s != '\0' ;)//陣列字元計數值
	  {
	   S2BUF=*s++ ;	//陣列字元送到SBUF，開始發射
	   while((S2CON & S2TI)==0); //若S2TI=0表示未發射完畢，再繼續檢查
	   S2CON &= ~S2TI ;	        //若S2TI=1表示已發射完畢，令S2TI=0
	  }
	 Delay_ms(500);     //延時
 	 i++; if(i>9) i=0;	//計數值0~9
   }
}
/***********************************************************
*函數名稱: UART2_init
*功能描述: UART2啟始程式
*輸入參數：bps
************************************************************/
void UART2_init(unsigned int bps)  //UART啟始程式
{  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
   S2CON=0x50;     //設定UART2串列傳輸為MODE1及致能接收
   S2BRT=256-(57600/bps);  //設定UART2傳輸速率
   AUXR2=S2TR;      //UART2啟動
}
