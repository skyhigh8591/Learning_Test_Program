/********** UART11.c ****UART2的mode 1接收及發射中斷********
*動作：使用UART2，個人電腦UART送出字元，由RXD2腳接收，在LED顯示，
*      並由TXD2腳發射回個人電腦
*硬體：SW1-3(P0LED)及SW3-5~6(TxD2,RxD2)ON
***********************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
void UART2_init(unsigned int bps);  //UART啟始程式
main()
{
  UART2_init(9600); //設定UART2串列環境及鮑率
  EA=1; AUXIE=ES2;  //致能UART2串列中斷
  while(1);   //自我空轉，表示可做其它工作
}
//**********************************************************
void SCON_int (void)  interrupt 12  //串列中斷函數 
 {
   if(S2CON & S2RI)  //若為接收所產生的中斷
    {
     S2CON &= ~S2RI;   //清除接收旗標令S2RI=0
     LED = ~S2BUF;     //將接收到的字元由LED輸出
	 S2BUF = ~LED;     //將temp發射出去
	}
	else S2CON &= ~S2TI; //若為發射所產生的中斷，清除發射旗標令S2TI=0
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