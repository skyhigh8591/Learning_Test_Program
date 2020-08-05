/************** ADC6A.C *******ADC定時中斷實習範例********
*動作：以定時中斷方式讀取高8-bit數位資料, 轉換1000次後，
*      由UART發射到電腦顯示數值
*硬體：SW3-1(Ain0) ON，SW3-3(TxD1) ON，調整Ain0的VR2
****************************************************/
#include "..\MPC82.H"
#include <stdio.h>   //加入基本輸出入函數
#define ch 0;
unsigned char xdata table[1000]; //儲存ADC轉換後的數位資料
unsigned int i=0; //資料計數

//Fosc=22.1184MHz，Timer時脈=Fosc/12=1.8432MHz
#define T  18432  //Timer延時時間=(1/1.8432MHz)*18432=0.01秒
void main(void)
{
  UART_init(9600); //UART啟始程式，設定串列環境及鮑率
  TI=1;
  TMOD =TMOD | 0x01;//設定TIMER0為MODE1
  EA=1;         //致能所有中斷   
  AUXIE = EADC; //致能ADC中斷
  ET0=1;        //致能Timer0中斷
  TR0=1;        //啟動Timer0開始計時
  while(1);     //空轉，等待Timer0中斷
}
/************************************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
  {
    TL0=65536-T; TH0=(65536-T)>>8; //重新設定Timer0計數值
    ADCTL=ADCON + ADCS + ch ; //由Ain0進行ADC轉換
  }
/***********************************************************
*函數名稱: output(unsigned long Data)
*功能描述: 將數位資料轉成電壓值發射到電腦
*輸入參數：temp數位資料
************************************************************/
void output(unsigned char Data)
{
 putchar(Data/100+'0');     //發射資料的百位數
 putchar(Data%100/10+'0');  //發射資料的十位數
 putchar(Data%10+'0');      //發射資料的個位數
 }
 /***********************************************************
*函數名稱: UART_output(void)
************************************************************/
void UART_output(void)
{
  for(i=0;i<1000;i++) output(table[i]);  //發射資料
}
/***********************************************************
*函數名稱: ADC中斷函數
*功能描述: 整合Ain0-1的10-bit數位資料
************************************************************/
void ADC_Interrupt()  interrupt 9 
{ 
   ADCTL= 0;      //停止ADC工作
   table[i++]=ADCH; //Ain0數位資料存入table   
   if(i>=1000)    //若ADC轉換1000後，停止計時，由UART輸出
    {
	  TR0=0;          //停止計時
	  UART_output();  //由UART輸出
	  i=0;TR0=1;	  //UART輸出完畢後，重新計時
	} 
}
/***********************************************************
*函數名稱: UART_init
*功能描述: UART啟始程式
*輸入參數：bps
************************************************************/
void UART_init(unsigned int bps)  //UART啟始程式
{
   SCON = 0x50;     // 設定UART串列傳輸為MODE1及致能接收
   TMOD = TMOD | 0x20; //設定TIMER1為MODE2
   TH1=TL1=256-(57600/bps); //設計時器決定串列傳輸鮑率
   TR1 = 1;         // 開始計時
}
