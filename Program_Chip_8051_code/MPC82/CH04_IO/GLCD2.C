/*****GLCD2.C****繪圖型LCD實習板範例******
*動作：在繪圖型LCD上顯示"笙泉科技"

*步驟：用MatrixFont 20個16x16字型.exe，輸入四個中文字,匯出檔案test

*************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "test.H"
unsigned char i;  //定義計數變數
unsigned x_page;  //定義LCD顯示X頁位址
unsigned y_addr;  //定義LCD顯示Y軸位址
main()
{
  CS1=1;CS2=1;	    //開啟繪圖型LCD左右半部
  Delay_ms(5);      //等待LCD開機時間
  LCD_Cmd(0x3f);    //0011111D，D=1開啟螢幕
  LCD_clear();	    //清除繪圖型LCD整個畫面

  CS1=1;CS2=1;	    //開啟繪圖型LCD左半部
  LCD_Cmd(0xb8+0); //10111xxx+0~7，X頁位址=0(字的上半部)
  LCD_Cmd(0x40+0); //01xxxxxx+0~63，Y軸位址=0最左邊
  for(i=0; i< 16*4 ;i++) //寫入64筆 
   {
    LCD_Data(test[i*2]);//寫入偶數資料(字的上半部) 
	  Delay_ms(10);
   }
  LCD_Cmd(0xb8+1); //10111xxx+0~7，X頁位址=1(字的下半部)
  LCD_Cmd(0x40+0); //01xxxxxx+0~63，Y軸位址=0最左邊
  for(i=0; i< 16*4 ;i++) //寫入64筆 
   {
	 LCD_Data(test[i*2+1]);//寫入奇數資料(字的下半部)
     Delay_ms(10);
    }
  while(1);	//停止 
}
/*******************************************
*函數名稱: LCD_clear()
*功能描述: 清除繪圖型LCD整個畫面
*********************************************/
void LCD_clear(void)
{ 
 for(x_page=0;x_page<8;x_page++)//X頁位址=0-7
   {  
     LCD_Cmd(0xb8+x_page); //10111xxx+0~7，
     LCD_Cmd(0x40+0); //01xxxxxx+0~63，Y軸位址=0最左邊
     for(i=0; i< 64 ;i++) LCD_Data(0x0);//寫入資料00 
   }
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