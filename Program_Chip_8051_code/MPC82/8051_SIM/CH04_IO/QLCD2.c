/************** QLCD2.C ***********************
*動作：由LCD顯示兩行文字
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
char code  Table[]="歡迎使用"; //第一行陣列字元
void main(void)
{
  unsigned char i;        //資料計數
  Delay_ms(10);	 //初始化SETUP
  LCD_Cmd(0x30); //功能設定
  LCD_Cmd(0x02); //DDRAM設定到00
  LCD_Cmd(0x04);
  LCD_Cmd(0x0c); //顯示幕ON
  LCD_Cmd(0x01); //清除畫面
  LCD_Cmd(0x80); //設定DDRAM位址在第一行
  for(i=0; i<8; i=i+2)
  {
    LCD_Data(0x01);					 
    LCD_Data(Table[i]);
    //LCD_Data(Table[i+1]);
  }
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
