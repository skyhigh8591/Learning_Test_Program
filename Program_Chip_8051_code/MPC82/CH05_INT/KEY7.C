/******** KEY7.C******************************************
*動作：按鍵由LCD顯示4位數四則運算
*操作：按鍵A=(+),B=(-),C=(*),D=(/),E=(=),F=(CLR) 
**********************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
void dataout(uint8 keyout); //按鍵資料輸出
void LCD_Disp8(unsigned long disp);//LCD顯示8位數十進制數字
unsigned char i=0; 
unsigned long lcd_count;
unsigned long lcd_count1;
void main()
{
 char count=0;   //按鍵計數=0
 unsigned char scan=0xEF;  //按鍵掃描令ROW0=0，其餘為1
 LCD_init();     	// 重置及清除LCD
 LCD_Cmd(0x80);     //游標由第一行開始顯示  
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
  LCD_Cmd(0x01);LCD_Cmd(0x02); //清除顯示幕,游標回原位  
  //LCD_init();     
  if(keyout==10) {i=1;LCD_Disp8(lcd_count); LCD_Data('+');}	
  if(keyout==11) {i=2;LCD_Disp8(lcd_count); LCD_Data('-');}
  if(keyout==12) {i=3;LCD_Disp8(lcd_count); LCD_Data('*');}
  if(keyout==13) {i=4;LCD_Disp8(lcd_count); LCD_Data('/');};
  if(keyout<=9) //限制輸入0~9鍵
   { 
     if(i==0)
	 {
      lcd_count=(lcd_count*10)+keyout; //數字進位
                       //若計數超過9999僅顯示後四碼
      if(lcd_count>9999) lcd_count=lcd_count % 10000; 
      LCD_Disp8(lcd_count); //LCD顯示4位數十進制數字
	  }
	 else
	   {
	    lcd_count1=(lcd_count1*10)+keyout;  //數字進位
        //若計數超過9999僅顯示後四碼
        if(lcd_count1>9999) lcd_count1=lcd_count1 % 10000; 
	if(i==1) {LCD_Disp8(lcd_count); LCD_Data('+');}	
        if(i==2) {LCD_Disp8(lcd_count); LCD_Data('-');}
        if(i==3) {LCD_Disp8(lcd_count); LCD_Data('*');}
        if(i==4) {LCD_Disp8(lcd_count); LCD_Data('/');}
        LCD_Disp8(lcd_count1); //LCD顯示4位數十進制數字
       }
   }

   if(keyout==14)
   {          
		if(i==1) {
				 LCD_Disp8(lcd_count); 
				 LCD_Data('+');
				 LCD_Disp8(lcd_count1);
				 LCD_Data('=');
				 lcd_count1=lcd_count + lcd_count1; }													
        if(i==2) {
				 LCD_Disp8(lcd_count);
				  LCD_Data('-');
				  LCD_Disp8(lcd_count1);
				  LCD_Data('='); 
				  lcd_count1=lcd_count - lcd_count1;}
        if(i==3) {
				 LCD_Disp8(lcd_count); 
				 LCD_Data('*');
				 LCD_Disp8(lcd_count1);
				 LCD_Data('=');
				 lcd_count1=lcd_count * lcd_count1; }
        if(i==4) {
				  LCD_Disp8(lcd_count);
				  LCD_Data('/');
				  LCD_Disp8(lcd_count1);
				  LCD_Data('=');
				 lcd_count1=lcd_count / lcd_count1; }
        i=0;
        LCD_Disp8(lcd_count1);  
        lcd_count=0;	
        lcd_count1=0;
   	  }
   
  if(keyout==15)   //CLR
   {
      LCD_init();     	// 重置及清除LCD
      LCD_Cmd(0x80);     //游標由第一行開始顯示
   }

  Delay_ms(1);       	//處理按鍵跳動之延遲
  while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
  Delay_ms(1);       //處理按鍵跳動之延遲
}
/*****************************************************
* 函數名稱: LCD_Disp8(unsigned int disp)
* 功能描述: LCD顯示8位數十進制數字
* 輸入參數：disp
*******************************************************/
void LCD_Disp8(unsigned long disp)  // LCD顯示8位數十進制數字
{
 if(disp>9999999) LCD_Data(disp / 10000000+'0');
 if(disp>999999) LCD_Data(disp % 10000000/1000000+'0');
 if(disp>99999) LCD_Data(disp % 1000000/100000+'0');
 if(disp>9999) LCD_Data(disp % 100000/10000+'0');
 if(disp>999) LCD_Data(disp % 10000/1000+'0');
 if(disp>99) LCD_Data(disp % 1000/100+'0');
 if(disp>9)LCD_Data(disp % 100/10+'0');
 LCD_Data(disp % 10+'0');
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
