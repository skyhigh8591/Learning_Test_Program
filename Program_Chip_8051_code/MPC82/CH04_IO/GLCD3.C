/*****GLCD3.C****繪圖型LCD實習板範例******
*動作：在繪圖型LCD上顯示16個中文字
*步驟：用MatrixFont 20個16x16字型.exe，輸入兩組8個中文字
*      ，再匯出檔案test1及test2。
****************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "test1.h"  //第一組8個中文字型
#include "test2.h"  //第二組8個中文字型

unsigned char i;  //定義計數變數
unsigned x_page; //定義LCD顯示X頁位址
unsigned y_addr; //定義LCD顯示Y軸位址
/********************************************
*函數名稱:FillHWAN
*功能描述:寫入資料到繪圖型LCD的上或下半部，顯示4個中文字
*輸入參數：*pp
**********************************************/
void FillHWAN(unsigned char code *pp,char xp_start)
{
  char y_addr; //定義LCD顯示Y軸位址
  for(y_addr=0; y_addr < 64; y_addr++) //Y軸位址0~63
  {
     LCD_Cmd(0xb8+xp_start+0); //偶數X頁位址
     LCD_Cmd(0x40+y_addr);     //Y軸位址0~63
     LCD_Data(*pp++);  //以指標方式讀取偶數資料，寫入字型
     LCD_Cmd(0xb8+xp_start+1); //奇數X頁位址
     LCD_Cmd(0x40+y_addr);    //Y軸位址0~63
     LCD_Data(*pp++);   //以指標方式讀取奇數資料，寫入字型
  }
}
/**********************************************/
main()
{
  CS1=CS2=1;	 //開啟繪圖型LCD上下半部控制
  Delay_ms(5);   //等待LCD開機時間
  LCD_Cmd(0x3f); //0011111D，D=1開啟螢幕
  LCD_clear();	 //清除繪圖型LCD整個畫面

  CS1=1; CS2=0;     //開啟繪圖型LCD左半部顯示
  FillHWAN(&test1[0],0);//以指標方式讀取資料，寫入前4個字型
  
  CS1=0; CS2=1;	  //開啟繪圖型LCD右半部顯示
  FillHWAN(&test1[128],0);//以指標方式讀取資料，寫入後4個字型
  
  CS1=1; CS2=0;     //開啟繪圖型LCD左半部顯示
  FillHWAN(&test2[0],2);//以指標方式讀取資料，寫入前4個字型
  
  CS1=0; CS2=1;	  //開啟繪圖型LCD右半部顯示
  FillHWAN(&test2[128],2);//以指標方式讀取資料，寫入後4個字型

   while(1);   //停止 
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