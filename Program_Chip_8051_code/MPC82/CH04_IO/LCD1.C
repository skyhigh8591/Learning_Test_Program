/************** LCD1.C **********************************
*動作：由LCD顯示兩行文字,令其閃爍或移位
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
void main(void)
{
   unsigned char i;        //資料計數
   LCD_init();    //重置及清除LCD    
   //LCD_Cmd(0x0F);//0000 1111
                   //bit2:D=1,顯示幕ON
                   //bit1:C=1,顯示游標
	               //bit0:B=1,游標閃爍
  LCD_Cmd(0x04); //0000 0100,
                   //bit1:I/D=0，游標左移反向顯示
    
   LCD_Cmd(0x8F); //游標由第一行第5個字開始顯示  
   for(i=0xB0; i<= 0xB9;i++)//字元0~9 
    {
     LCD_Data(i);  //字元送到LCD顯示   
     //Delay_ms(100);//延時，慢速逐一顯示
	}

   LCD_Cmd(0xCF); //游標由第二行第5個字開始顯示   
   for(i='A'; i<= 'J';i++)//LCD顯示字元A~J 
    {
	 LCD_Data(i);  //字元送到LCD顯示   
     Delay_ms(100);//延時，慢速逐一顯示
	}

	while(1)   //不停的循環執行
     {  //選擇以下其中功能來執行
 	   //LCD_Cmd(0x08); Delay_ms(500);//D=0關閉顯示器
       //LCD_Cmd(0x0c); Delay_ms(500);//D=1開啟顯示器
       //LCD_Cmd(0x1c); Delay_ms(100);//SC=1及RL=1顯示幕右移
       LCD_Cmd(0x18); Delay_ms(100);//SC=1及RL=0顯示幕左移
     }  
}
/***********************************************************
*函數名稱: LCD_Data
*功能描述: 傳送資料到文字型LCD
*輸入參數：dat
************************************************************/
void LCD_Data(unsigned char dat)  //傳送資料到LCD
{
    unsigned char dly=2;
	Data=dat;      //資料送到BUS
    RS=1;RW=0;EN=1;//資料寫入到LCD內
    while(dly--);
	EN=0;          //禁能LCD 
	LCD_wait();    //LCD等待寫入完成  
}
/***************************************************************
*函數名稱: LCD_Cmd
*功能描述: 傳送命令到文字型LCD
*輸入參數：Cmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //傳送命令到LCD
{
    unsigned char dly=2;
	Data=Cmd;       //命令送到BUS
    RS=0;RW=0;EN=1; //命令寫入到LCD內
    while(dly--);
    EN=0;           //禁能LCD
	LCD_wait(); //LCD等待寫入完成 
}
/***************************************************************
*函數名稱: LCD_Cmd
*功能描述: 傳送命令到文字型LCD
*輸入參數：Cmd
************************************************************/
void LCD_Cmd_Init(unsigned char Cmd) //傳送命令到LCD
{
    Data=Cmd;       //命令送到BUS
    RS=0;RW=0;EN=1; //命令寫入到LCD內
    Delay_ms(1);
    EN=0;           //禁能LCD
    Delay_ms(1);
}
/***************************************************************
*函數名稱: LCD_init
*功能描述: 啟始化文字型LCD
*****************************************************************/
void LCD_init(void)    //LCD的啟始程式  
{
    LCD_Cmd_Init(0x38);//0011 1000,8bit傳輸,顯示2行,5*7字型
    LCD_Cmd_Init(0x38);//bit4:DL=1,8bit傳輸,
    LCD_Cmd_Init(0x38);//bit3:N=1,顯示2行
                       //bit2:F=0,5*7字型    
    LCD_Cmd_Init(0x0c);/*0000 1100,顯示幕ON,不顯示游標,游標不閃爍
                    bit2:D=1,顯示幕ON
                    bit1:C=0,不顯示游標
	                bit0:B=0,游標不閃爍*/
    LCD_Cmd_Init(0x06);/*0000 0110,//顯示完游標右移,游標移位禁能 
                    bit1:I/D=1,顯示完游標右移,
                    bit0:S=0,游標移位禁能*/  
    LCD_Cmd_Init(0x01); //清除顯示幕  
    LCD_Cmd_Init(0x02); //游標回原位  
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
    RS=0;RW=1;EN=1;//讀取命令
    status= Data;	//輸入LCD的命令
    EN=0;			//禁能LCD
  }
  while(status & 0x80); //等待忙碌旗標BF=0
}
