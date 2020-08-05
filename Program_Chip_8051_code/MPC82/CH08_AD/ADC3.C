/************** ADC3.C *******ADC中斷實習範例**********
*動作：輸入類比電壓，由UART發射到電腦顯示數值
*硬體：SW3-1(Ain0) ON，SW3-3(TxD1) ON，調整Ain0的VR
****************************************************/
#include "..\MPC82.H"
#define  ch     0 //指定由Ain0進行ADC轉換
unsigned int ADC(char channel);
void output(unsigned char Data);

void main(void)
{
    UART_init(9600); //UART啟始程式，設定串列環境及鮑率
	EA=1;            //致能所有中斷
    AUXIE = EADC;    //致能ADC中斷
    AUXR = ADRJ;     //數位資料ADCH向右移
    ADCTL=ADCON + ADCS + ch; //ADC工作及指定道通進行ADC轉換
	while(1);  //空轉，此時可做其它工作
}
/***********************************************************
*函數名稱: ADC中斷函數
*功能描述: 整合10-bit數位資料
************************************************************/
void ADC_Interrupt()  interrupt 9 
{ 
  unsigned int value;
  ADCTL=0;                  //停止ADC工作
  value=(ADCH<<8) + ADCL;  //整合Ain0數位資料
  output('A'); output('i'); output('n'); output('=');//發射字串
  output(value/1000+'0');     //發射資料的千位數
  output(value%1000/100+'0'); //發射資料的百位數
  output(value%100/10+'0');   //發射資料的十位數
  output(value%10+'0');       //發射資料的個位數
  output('\n'); output('\r'); //跳行及歸位 	
  Delay_ms(300);              //延時
  ADCTL=ADCON + ADCS + ch;    //重新啟動ADC工作
}
/***********************************************************
*函數名稱: void output(unsigned char Data)
*功能描述: 將字元發射出去
*輸入參數：字元資料
************************************************************/
void output(unsigned char Data)
{
  SBUF=Data;  //轉成字元發射出去
  while(TI==0); //若TI=0表示未發射完畢，再繼續檢查
  TI=0 ;	  //若TI=1表示已發射完畢，令TI=0  
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
