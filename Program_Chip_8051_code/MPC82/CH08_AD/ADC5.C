/************** ADC5.C *******ADC中斷實習範例********
*動作：輸入兩通道類比電壓，在LCD顯示電壓值
*硬體：SW3-1~2(Ain0-1)ON，調整Ain0-1的VR
****************************************************/
#include "..\MPC82.H"
unsigned int ADC(char channel);  //將類比電壓轉換成數位資料
void LCD_Disp(unsigned int disp); //LCD顯示電壓值

unsigned int value=0; //數位資料變數
unsigned long temp;	  //暫存值
unsigned long sum=0;  //累加值

char ch=0;  //類比通道
char i=0;   //轉換次數

void main(void)
{
  LCD_init();        //重置及清除LCD   
    
  LCD_Cmd(0x80);     //游標由第一行開始顯示字元  
  LCD_Data('A'); LCD_Data('i'); LCD_Data('n');
  LCD_Data('0'); LCD_Data('=');

  LCD_Cmd(0xC0);     //游標由第二行開始顯示字元  
  LCD_Data('A'); LCD_Data('i'); LCD_Data('n');
  LCD_Data('1'); LCD_Data('=');
	
  EA=1; AUXIE = EADC; //致能ADC中斷
  ADCTL=ADCON + ADCS + 0 ; //由Ain0進行ADC轉換
  AUXR = ADRJ;      //數位資料ADCH向右移
  while(1);         //空轉，表示可做其它工作
}
/***********************************************************
*函數名稱: ADC中斷函數
*功能描述: 整合Ain0-1的10-bit數位資料
************************************************************/
void ADC_Interrupt()  interrupt 9 
{ 
  ADCTL=0;  //停止ADC工作
  temp=(ADCH<<8) + ADCL;  //整合Ain0數位資料
  sum=sum+temp;   //類加數位資料
  i++; 
  if(i>9)   //檢查是否已轉換10次
	 {
	   if(ch==0){LCD_Cmd(0x85); ch=1; } //Ain0在第一行顯示，改為Ain1
	     else 	{LCD_Cmd(0xC5); ch=0; } //Ain1在第二行顯示，改為Ain0
	   value=(sum/10)*5*100/1023;	   //累積取平均值轉換成電壓
	   LCD_Disp(value);          //顯示類比電壓值
	   i=0; value=0; sum=0;      //恢復各參數
	 }
  ADCTL=ADCON + ADCS + ch;  //重新進行ADC轉換
}
/********************************************************
*函數名稱: LCD_Disp(unsigned int disp)
*功能描述: LCD顯示電壓值
*輸入參數：disp
*******************************************************/
void LCD_Disp(unsigned int disp) // LCD顯示電壓值 
{
  LCD_Data(disp /100+'0');    //取出百位數字元到LCD顯示
  LCD_Data('.');				  //顯示小數點
  LCD_Data(disp % 100/10+'0'); //取出十位數字元到LCD顯示
  LCD_Data(disp % 10+'0');     //取出個位數字元到LCD顯示
  LCD_Data('V');				  //顯示V
} 
/***********************************************************
*函數名稱: LCD_Data
*功能描述: 傳送資料到文字型LCD
*輸入參數：dat
************************************************************/
void LCD_Data(char dat)  //傳送資料到LCD
{
    Data=dat; //資料送到BUS
    RS=1;RW=0;EN=1;//資料寫入到LCD內
    Delay_ms(1);   //LCD等待寫入完成
    EN=0;          //禁能LCD    
}
/***************************************************************
*函數名稱: LCD_Cmd
*功能描述: 傳送命令到文字型LCD
*輸入參數：Cmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //傳送命令到LCD
{
    Data=Cmd;  //命令送到BUS
    RS=0;RW=0;EN=1; //命令寫入到LCD內
    Delay_ms(1);    //LCD等待寫入完成     
    EN=0;           //禁能LCD
}
/***************************************************************
*函數名稱: LCD_init
*功能描述: 啟始化文字型LCD
*****************************************************************/
void LCD_init(void)    //LCD的啟始程式  
{
    LCD_Cmd(0x38);/*0011 1000,8bit傳輸,顯示2行,5*7字型
                    bit4:DL=1,8bit傳輸,
                    bit3:N=1,顯示2行
                    bit2:F=0,5*7字型*/    
    LCD_Cmd(0x0c);/*0000 1100,顯示幕ON,不顯示游標,游標不閃爍
                    bit2:D=1,顯示幕ON
                    bit1:C=0,不顯示游標
	                bit0:B=0,游標不閃爍*/
    LCD_Cmd(0x06);/*0000 0110,//顯示完游標右移,游標移位禁能 
                    bit1:I/D=1,顯示完游標右移,
                    bit0:S=0,游標移位禁能*/  
    LCD_Cmd(0x01); //清除顯示幕  
    LCD_Cmd(0x02); //游標回原位  
}
