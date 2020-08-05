/************** LCD2.C *****************************
*動作：在LCD顯示"COUNT="，再重覆顯示00000~65535
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
char code  Table[]="COUNT="; //第一行陣列字元
void LCD_Disp(unsigned int disp); // LCD 十進制5位數顯示

void main(void)
{
   unsigned int count=12345; //顯示計數十進制初值
   char i;   		  //陣列資料計數
   LCD_init();        //重置及清除LCD    
   LCD_Cmd(0x80);     //游標由第一行開始顯示  
   for(i=0; i<6; i++) //讀取陣列"COUNT= "字元到LCD顯示出來 
      LCD_Data(Table[i]);   
   while(1)         //重覆執行
   {
     LCD_Cmd(0x86);    //游標由第一行第6字開始顯示  
     LCD_Disp(count++);//顯示5位數十進制計數及計數遞加
     Delay_ms(300);
   }
 }
/********************************************************
*函數名稱: LCD_Disp(unsigned int disp)
*功能描述: LCD顯示5位數十進制數字
*輸入參數：disp
*******************************************************/
void LCD_Disp(unsigned int disp)  // LCD 十進制5位數顯示
{
 if(disp>9999) LCD_Data(disp /10000+'0');      //顯示萬位數
 if(disp>999)  LCD_Data(disp % 10000/1000+'0');//顯示千位數
 if(disp>99)   LCD_Data(disp % 1000/100+'0');  //顯示百位數
 if(disp>9)    LCD_Data(disp % 100/10+'0');    //顯示十位數
               LCD_Data(disp % 10+'0');        //顯示個位數
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
