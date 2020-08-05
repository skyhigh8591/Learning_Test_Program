/************** ADC4.C *******ADC中斷實習範例********
*動作：輸入兩通道類比電壓，由UART發射到電腦顯示電壓值
*      顯示"Ain0=x.xxV  Ain1=x.xxV" 
*硬體：SW3-1~2(Ain0-1) ON，SW3-3(TxD1) ON，調整Ain0的VR2
****************************************************/
#include "..\MPC82.H"
#include <stdio.h>   //加入基本輸出入函數
bit ch=0;						 //類比通道
void main(void)
{
	UART_init(9600); //UART啟始程式，設定串列環境及鮑率
    TI=1;
  	EA=1;         //致能所有中斷
    AUXIE = EADC; //致能ADC中斷
    ADCTL=ADCON + ADCS + 0 ; //由Ain0進行ADC轉換
    AUXR = ADRJ;      //數位資料ADCH向右移
    while(1);   //空轉，等待ADC轉換完畢中斷，此時可做其它工作
}
/***********************************************************
*函數名稱: output(unsigned long Data)
*功能描述: 將數位資料轉成電壓值發射到電腦
*輸入參數：temp數位資料
************************************************************/
void output(unsigned long Data)
{
	Data=(Data*5*100)/1023;    //數位資料轉換成電壓值
	putchar(Data/100+'0');     //發射資料的百位數
	putchar('.');              //發射小數點
	putchar(Data%100/10+'0');  //發射資料的十位數
	putchar(Data%10+'0');      //發射資料的個位數
	putchar('V');              //發射電壓
 }
/***********************************************************
*函數名稱: ADC中斷函數
*功能描述: 整合Ain0-1的10-bit數位資料
************************************************************/
void ADC_Interrupt()  interrupt 9 
{ 
   unsigned int value0,value1;		 //數位資料變數
   putchar('A'); putchar('i'); putchar('n'); //串列埠發射字串"Ain"
   if(ch==0)  //若是Ain0類比輸入
    {
	  ADCTL= 1;      //改為Ain1，停止ADC工作
	  value0=(ADCH<<8) + ADCL; //整合Ain0數位資料
	  putchar('0'); putchar('='); //串列埠發射字串"0="
	  output(value0);  //Ain0數位資料轉換成電壓值,發射出去
	  putchar(' ');putchar(',');putchar(' '); //串列埠發射字串" , "
	}
	  else	//若是Ain1類比輸入
       {
		ADCTL= 0;    //改為Ain0，停止ADC工作
		value1=(ADCH<<8) + ADCL ; //整合Ain1數位資料
	    putchar('1'); putchar('='); //串列埠發射字串"1="
	    output(value1); //Ain1數位資料轉換成電壓值,發射出去
	   	putchar('\n');putchar('\r');    //跳行，歸位
	    Delay_ms(1000);	   //延時
	   }
    ch=!ch;  //換另一通道
    ADCTL=ADCTL+ADCON + ADCS; //重新啟動ADC轉換
}
/***********************************************************
*函數名稱: UART_init
*功能描述: UART啟始程式
*輸入參數：bps
************************************************************/
void UART_init(unsigned int bps)  //UART啟始程式
{
   SCON = 0x50;     //設定UART串列傳輸為MODE1及致能接收
   TMOD = 0x20;     //設定TIMER1為MODE2
   TH1=TL1=256-(57600/bps);  //設計時器決定串列傳輸鮑率
   TR1 = 1;          //開始計時
}