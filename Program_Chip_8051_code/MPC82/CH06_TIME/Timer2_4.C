 /********Timer2_4.c *****************************
*動作：T0CKO(P34)輸出脈波，若T2EX(P11)腳輸入負緣觸發
*      捕捉計時器到LCD顯示狀態週期數及頻率
*硬體：T0CKO(P34)連接T2EX(P11) 
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
                //T0CKO頻率=Fosc/24/(256-TH0)
#define T   225 //T0CKO頻率=22118400/24/225=4096Hz 
void LCD_Disp(unsigned int disp); // LCD 十進制5位數顯示			    
char code  Table[]="States="; //第一行陣列字元
char code  Table1[]="Frequency="; //第二行陣列字元

main()
{
   char i;   		  //陣列資料計數
   LCD_init();        //重置及清除LCD    
   LCD_Cmd(0x80);     //游標由第一行開始顯示  
   for(i=0; i<7; i++) //顯示"States= " 
      LCD_Data(Table[i]);

   LCD_Cmd(0xc0);      //游標由第二行開始顯示  
   for(i=0; i<10; i++) //顯示"frequency=" 
      LCD_Data(Table1[i]);      

   AUXR2=T0CKOE; //致能T0CKO(P34)輸出方波
   TMOD=0x02;    //設定Timer0為mode2內部計時
   TH0=256-T;    //將計數值存入TH0
   TR0=1;        //啟動Timer0
   
   T2CON=0x09; /* 0000 1001，T2EX輸入負緣觸發捕捉計時器
                  bit3:EXEN2=1,使用外部T2EX接腳
				  bit1:C/T2=0,內部計時
			      bit0:CP/RL2=1,捕捉計時器 */
   T2R =0;      //設定Timer2=0
   TR2=1;       //啟動Timer2開始計時
   while (1)    //不斷循環執行
   {
     while(EXF2==0); //等待第一次T2EX腳輸入負緣觸發
     EXF2=0;         //清除旗標
     T2R =0;         //設定Timer2=0

	 while(EXF2==0); //等待第二次T2EX腳輸入負緣觸發，捕捉Timer2
     EXF2=0;         //清除旗標
     EXEN2 =0;       //顯示時，停止T2EX腳輸入負緣觸發
	 
	 LCD_Cmd(0x87);     //游標由第一行第7字開始顯示  
	 LCD_Disp(RCAP2+2); //顯示輸入波形的狀態週期數

   	 LCD_Cmd(0xCA);     //游標由第二行第10字開始顯示  
	 LCD_Disp(22118400/12/(RCAP2+2));  //顯示輸入波形的頻率值
	 LCD_Data('H');LCD_Data('z');
	  
	 EXEN2 =1;     //重新開始T2EX腳輸入負緣觸發
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
 if(disp>999) LCD_Data(disp % 10000/1000+'0'); //顯示千位數
 if(disp>99) LCD_Data(disp % 1000/100+'0');    //顯示百位數
 if(disp>9) LCD_Data(disp % 100/10+'0');       //顯示十位數
 LCD_Data(disp % 10+'0');     	               //顯示個位數
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
