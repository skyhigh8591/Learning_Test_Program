/******** KEY4.C******4*4鍵盤實習範例***************
*動作：在LCD顯示"KEY="，按鍵由LCD顯示4位數移位動作
*硬體：按S1~S16
*****************************************/
#include "..\MPC82.H"   //暫存器及組態定義
char code  Table[]="KEY="; //第一行陣列字元
void LCD_Disp(unsigned int disp);  // LCD顯示4位數
void dataout(uint8 keyout); //按鍵資料輸出
unsigned char i=0;      //LCD顯示位置
unsigned long lcd_count;	//LCD顯示數字
void main()
{
 char count=0;   //按鍵計數=0
 unsigned char scan=0xEF; //按鍵掃描令ROW0=0，其餘為1
 LCD_init();     	//重置及清除LCD
 LCD_Cmd(0x80);     //游標由第一行開始顯示  
 for(i=0; i<4; i++) //讀取陣列"KEY= "字元到LCD顯示出來 
   LCD_Data(Table[i]);   
 LCD_Disp(lcd_count); //LCD顯示4位數十進制數字
 while(1)   //重覆執行
  {
    if(count>15){scan=0xEF;count=0;}//若計數>15，從頭開始
    ROW=scan;		  //掃描輸出
    if(COL0==0) dataout(count);//檢查COL0列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL1==0) dataout(count);//檢查COL1列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL2==0) dataout(count);//檢查COL2列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL3==0) dataout(count);//檢查COL3列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    scan=RL8(scan); //左旋轉，換掃下一列,令ROW0~3輪流為0
   }
}
/***********************************************************
*函數名稱: dataout
*功能描述: 按鍵輸出資料送到LCD顯示數字，檢查是否放開按鍵
*輸入參數：keyout
************************************************************/
void dataout(char keyout) 
{   
  LCD_Cmd(0x84);
  if(keyout<=9) //限制輸入0~9鍵
   {  
    lcd_count=(lcd_count*10)+keyout;  //數字進位
                  //若計數超過9999僅顯示後四碼
    if(lcd_count>9999) lcd_count=lcd_count % 10000; 
    LCD_Disp(lcd_count); //LCD顯示4位數十進制數字
   }
  Delay_ms(1);       	//處理按鍵跳動之延遲
  while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
  Delay_ms(1);       //處理按鍵跳動之延遲
}
/*****************************************************
* 函數名稱: LCD_Disp(unsigned int disp)
* 功能描述: LCD顯示4位數十進制數字
* 輸入參數：disp
*******************************************************/
void LCD_Disp(unsigned int disp)  // LCD顯示4位數十進制數字
{
 if(disp>999) LCD_Data(disp /1000+'0');   //顯示千位數
 if(disp>99)  LCD_Data(disp%1000/100+'0');//顯示百位數
 if(disp>9)   LCD_Data(disp%100/10+'0');  //顯示十位數
              LCD_Data(disp % 10+'0');    //顯示個位數
}
/***********************************************************
*函數名稱: LCD_Data
*功能描述: 傳送資料到文字型LCD
*輸入參數：dat
************************************************************/
void LCD_Data(char dat)  //傳送資料到LCD
{
    Data=dat;      //資料送到BUS
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
    Data=Cmd;       //命令送到BUS
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
    LCD_Cmd(0x38);//0011 1000,8bit傳輸,顯示2行,5*7字型
    LCD_Cmd(0x38);//bit4:DL=1,8bit傳輸,
    LCD_Cmd(0x38);//bit3:N=1,顯示2行
                  //bit2:F=0,5*7字型    
    LCD_Cmd(0x0f);/*0000 1100,顯示幕ON,顯示游標,游標閃爍
                    bit2:D=1,顯示幕ON
                    bit1:C=1,顯示游標
	                bit0:B=1,游標閃爍*/
    LCD_Cmd(0x06);/*0000 0110,//顯示完游標右移,游標移位禁能 
                    bit1:I/D=1,顯示完游標右移,
                    bit0:S=0,游標移位禁能*/  
    LCD_Cmd(0x01); //清除顯示幕  
    LCD_Cmd(0x02); //游標回原位  
}
