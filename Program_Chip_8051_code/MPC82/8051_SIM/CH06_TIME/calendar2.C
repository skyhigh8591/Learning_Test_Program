//************* calendar2.c *************************************
//以Timer2計時中斷，進行萬年曆電子鐘顯示年、月、日、時、分、秒、星期
//年、月、日、時、分、秒可自由設定，星期由程式判斷自行產生
//作者:游景翔(青輔會青年職訓中心100期電子應用班)
//*************************************************************
#include "..\MPC82.H"   //暫存器及組態定義

                  //Fosc=22.1184MHz，Timer時脈=Fosc/12=1.8432MHz
#define T  57600  //Timer延時時間=(1/1.8432MHz)*57600=31250uS
 unsigned char dly_sec=32; //設定計時重覆次數，時間=31250uS*32=1秒
 unsigned char sec=55; //設定秒初值	

char code mes[]="\000\001\002";//0=年、1=月、2=日
char code Table[]={
  0x10,0x1f,0x02,0x0f,0x0a,0xff,0x02,0x00, //年
  0x0f,0x09,0x0f,0x09,0x0f,0x09,0x13,0x00, //月
  0x0f,0x09,0x09,0x0f,0x09,0x09,0x0f,0x00};//日

main()
{
   int year=2009;      //設定年
   char mon=1,day=20;  //設定月、日
   char hor=13,min=32; //設定時、分值
   char i;		       //變數宣告
   int y,m,d;		   //陣列資料計數
   
   EA=1; ET2=1; //致能Timet2計時溢位中斷
   T2CON=0x00; //設定為內部計時，溢位重新載入
   RCAP2=T2R=65536-T; //設定Timer2及重新載入時間
   TR2=1;      //啟動Timet2
   					    
   LCD_init();           //重置及清除LCD 
   for(i=0x0;i<=0x3f;i++) //寫入年月日字型 
   {
     LCD_Cmd(0x40+i);    //指定CGRAM位址  
     LCD_Data(Table[i]); //寫入CGRAM資料  
   } 
   while(1)	  //開始顯示及計算萬年曆
   {	
   	LCD_Cmd(0x80);	//顯示第一行位置
	LCD_Data(year/1000+'0');  //年的千位數到LCD顯示
	LCD_Data(year%1000/100+'0'); //年的百位數到LCD顯示
	LCD_Data(year%100/10+'0'); //年的十位數到LCD顯示
    LCD_Data(year%10+'0'); //年的個位數到LCD顯示
	for(i=0;i<1;i++) LCD_Data(mes[i]); //顯示年
	LCD_Data(' '); 	LCD_Data(' '); //空格
	
    LCD_Data(mon/10+'0'); //月的十位數到LCD顯示
    LCD_Data(mon%10+'0'); //月的個位數到LCD顯示
    for(i=1;i<2;i++) LCD_Data(mes[i]); //顯示月
	LCD_Data(' ');	LCD_Data(' ');	//空格

    LCD_Data(day/10+'0'); //日的十位數到LCD顯示
    LCD_Data(day%10+'0'); //日的個位數到LCD顯示
	for(i=2;i<3;i++) LCD_Data(mes[i]); //顯示日
    
	LCD_Cmd(0xc0); //顯示第二行位置
	if(hor==12) //12時上午轉下午
 	 { LCD_Data('P'); LCD_Data('M'); LCD_Data(' ');} //顯示PM
	if(hor==24) //24時下午轉上午 
	 { LCD_Data('A'); LCD_Data('M'); LCD_Data(' ');}//顯示AM
	 
   	if(hor<12) //時小於12
	{ LCD_Data('A'); LCD_Data('M'); LCD_Data(' ');}  //顯示AM
	  else if(hor>12 && hor<=23) //小時介於12-23之間
	   { LCD_Data('P');  LCD_Data('M');  LCD_Data(' ');} //顯示PM
   	
	if(hor<=12)	 	//時小於/等於12
	  {
        LCD_Data(hor/10+'0');LCD_Data(hor%10+'0'); //顯示時
        LCD_Data(':');
       } 
	   else	   //時大於12
	   { 	   
	     LCD_Data((hor-12)/10+'0'); LCD_Data((hor-12)%10+'0');//顯示時
         LCD_Data(':');
	    }
          
		  LCD_Data(min/10+'0');LCD_Data(min%10+'0'); //顯示分
          LCD_Data(':');
    
          LCD_Data(sec/10+'0'); LCD_Data(sec%10+'0');//顯示秒
          LCD_Data(' ');

	if(year%4==0) //閏年
	{
		y=((year-1)+(year-1)/4-(year-1)/100+(year-1)/400); 
		switch (mon)   //逢4年閏年,逢百不閏,逢400年閏年
		{
			case 1:	 m=day; break;	     //1月
			case 2:	 m=(day+31); break;  //2月
			case 3:	 m=(day+60); break;  //3月
			case 4:	 m=(day+91); break;  //4月
			case 5:	 m=(day+121); break; //5月
			case 6:	 m=(day+152); break; //6月
			case 7:	 m=(day+182); break; //7月
			case 8:	 m=(day+213); break; //8月
			case 9:	 m=(day+244); break; //9月
			case 10: m=(day+274); break; //10月
			case 11: m=(day+305); break; //11月
			case 12: m=(day+335); break; //12月
		  }
	 }
	else if(year%4==1||2||3)	//非閏年
	 {
		y=((year-1)+(year-1)/4-(year-1)/100+(year-1)/400);
		switch (mon)
		{
			case 1:  m=day;       break; //1月
			case 2:  m=(day+31);  break; //2月
			case 3:  m=(day+59);  break; //3月
			case 4:  m=(day+90);  break; //4月
			case 5:  m=(day+120); break; //5月
			case 6:  m=(day+151); break; //6月
			case 7:  m=(day+187); break; //7月
			case 8:  m=(day+212); break; //8月
			case 9:  m=(day+243); break; //9月
			case 10: m=(day+273); break; //10月
			case 11: m=(day+304); break; //11月
			case 12: m=(day+334); break; //12月
		}
	}
	d=(y+m)%7;	//總天數除以7的餘數
	if(d==1) //星期一
	  { LCD_Data('M');LCD_Data('o');LCD_Data('n');} //顯示Mon
	
	if(d==2) //星期二
	  { LCD_Data('T');LCD_Data('u');LCD_Data('e');} //顯示Tue
	
	if(d==3) //星期三
	  { LCD_Data('W');LCD_Data('e');LCD_Data('d');} //顯示Wed
	
	if(d==4) //星期四
	  { LCD_Data('T');LCD_Data('h');LCD_Data('u');} //顯示Thu
	
	if(d==5) //星期五
	  { LCD_Data('F');LCD_Data('r');LCD_Data('i');} //顯示Fri
	
	if(d==6)  //星期六
	  { LCD_Data('S');LCD_Data('a');LCD_Data('t');} //顯示Sat
	
	if(d==0)  //星期日
	  { LCD_Data('S');LCD_Data('u');LCD_Data('n');} //顯示Sun

    if (sec < 60) continue; //若秒小於60到while(1)處   
    sec=0; min++;           //秒等於60則令秒=0，分加一
    if (min < 60) continue; //若分小於60到while(1)處   
    min=0; hor++;           //若分等於60則令分=0，時加一
	if(hor==24) 
	 {
	  switch (day)	//檢查日
	   {
	  	case 28:   //日=28
		 if(year%4==0 && mon==2) day++;//29天//閏年2月
		  else if(mon==2) { day=0; mon++;}//28天
		        else day++;	 break;
		
		case 29: //日=29
		  if(year%4==0 && mon==2) { day=0;mon++; }
		    else day++;	 break;
		
		case 30: //日=30
		  if(mon==4 || mon==6 || mon==9 || mon==11) 
			{day=0;mon++;}	//4.6.9.11月30天
			  else day++; break;
			
		case 31: //日=31
		  if(mon==1||mon==3||mon==5||mon==7||mon==8||mon==10) 
			{ day=0;mon++; }   //1.3.5.7.8.10月31天
			   else if(mon==12)
				{ day=0; mon=1;year++;}	 //過年
			break;
	   }
 	  if(day<28) day++;	//日<28
	 }
    if (hor <25)  continue; //若時小於24到while(1)處
    hor=1;min=0; sec=0;//若時等於24則令時、分、秒=0 
  }
}
/*******************************************************/ 
void T2_int(void) interrupt 5  //Timer2中斷函數
{
  dly_sec--;	        //計時重覆次數遞減
  if(dly_sec==0)        //若秒時間到
   { sec++; dly_sec=32;}//秒遞加及重覆次數(設中斷點)
  TF2=0;                //清除計時溢位TF2=0
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
