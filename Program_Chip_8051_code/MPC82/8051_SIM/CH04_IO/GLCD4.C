/*****GLCD4.C****繪圖型LCD(橫排)實習板範例******
*動作：在繪圖型LCD上顯示小畫家圖形
****************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "qq.h"	 //圖形資料
unsigned char i;  //定義計數變數
unsigned x_page;  //定義LCD顯示X頁位址
int main(void)
{
  RST=0; Delay_ms(1);RST=1; //重置繪圖型LCD
  LCD_Cmd(0x3f);   //0011111D，D=1開啟螢幕
  CS1=1;CS2=1;LCD_Cmd(0xC0+0); //第0行開始顯示
  CS1=1; CS2=0; 		       //選擇左半部
  for(x_page=0; x_page<8 ;x_page++) //寫入8頁資料
   {
    LCD_Cmd(0x40+0);    //Y位址	
    LCD_Cmd(0xb8+x_page);	          //寫入第0~7頁
     for(i=0; i< 16*4 ;i++)         //寫入32筆資料
	   LCD_Data(qq[i*8+x_page]);     //寫入圖形
   }

  CS2=1; CS1=0;              //選擇右半部
  for(x_page=0; x_page<8 ;x_page++)  //寫入8頁資料
   {
     LCD_Cmd(0x40+0);				 
     LCD_Cmd(0xb8+x_page);		     //寫入第0~7頁
     for(i=0; i< 16*4 ;i++)          //寫入32筆資料
	   LCD_Data(qq[i*8+512+x_page]); //寫入圖形
   }
  while(1);
}
/*******************************************
*函數名稱: LCD_Cmd
*功能描述: 寫入命令到繪圖型LCD
*輸入參數：cmd
*********************************************/
void LCD_Cmd(unsigned char cmd)
{
	unsigned char dly=40;
	Data=cmd;	//輸出命令	
	D_I=0;RW=0;EN=1;while(dly--);EN=0; //寫入命令
	LCD_wait();	//等待忙碌旗標BF
}
/********************************************
*函數名稱: LCD_Data
*功能描述: 寫入資料到繪圖型LCD
*輸入參數：dat
*********************************************/
void LCD_Data(char dat)
{
	unsigned char dly=40;
	Data=dat;  	 //輸出資料
	D_I=1;RW=0;EN=1;while(dly--);EN=0;//寫入資料
	LCD_wait();	//等待忙碌旗標BF
}
/**************************************************
*函數名稱: LCD_wait
*功能描述: LCD等待忙碌旗標BF
****************************************************/
void LCD_wait(void)
{
  unsigned char status;  //定義LCD讀取狀態
  Data=0xff; //P0設定為輸入埠
  do
  {
    D_I=0;RW=1;EN=1;//讀取命令
    status= Data;	//輸入LCD的命令
    EN=0;			//禁能LCD
  }
  while(status & 0x80); //等待忙碌旗標BF=0
}