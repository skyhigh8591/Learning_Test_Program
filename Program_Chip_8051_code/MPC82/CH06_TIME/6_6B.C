/********** 6_6B.c ***************************
*動作：以Timer0計時中斷mode1控制電子鐘
*硬體：SW1-1(SEG7)ON
**********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
                  //Fosc=22.1184MHz，Timer時脈=Fosc/12=1.8432MHz
#define T  57600  //Timer延時時間=(1/1.8432MHz)*57600=31250uS
unsigned char i=0;
code unsigned char Table[] //七段顯示器0~9數碼資料
={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

char hor=23,min=58,sec=52; //設定時、分、秒時間
void Display(void); //七段顯示器顯示時間值
main()         
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
 
  TMOD = 0x01; /*0000 0001，設定Timer0為mode1內部計時
                 bit3:GATE=0,不使用外部INT0接腳
  		         bit2:C/T0=0,內部計時 
			     bit1-0:MODE=01,使用模式1工作*/
  TL0=65536-T; TH0=(65536-T)>>8; //設定Timer0計數值
  EA=1;ET0=1;    //致能Timer0中斷
  TR0=1;         //啟動Timer0開始計時
  while(1)
   {
    Display(); //七段顯示器顯示時間
    if (sec < 60) continue; //若秒小於60到loop處   
    sec=0; min++;        //秒等於60則令秒=0，分加一
    if (min < 60) continue; //若分小於60到loop處   
    min=0; hor++;        //若分等於60則令分=0，時加一
    if (hor <24) continue; //若時小於24到loop處
    hor=0;min=0; sec=0; //若時等於24則令時、分、秒=0
   }
}
/************************************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
  {
    TL0=65536-T; TH0=(65536-T)>>8; //重新設定Timer0計數值
	i++;
	if(i>31)  
	  {i=0;sec++;}    //秒遞加
  }

void Display(void) //四位數七段顯示器顯示步數	 
{  
     S0=S1=S2=S3=1; //遮沒 
     Data=~Table[min%10];//讀取分個位數數碼資料輸出
     S0=0;          //選擇個位數顯示器
     Delay_ms(1);   //掃描延時  
       
     S0=S1=S2=S3=1; //遮沒          
     Data=~Table[min/10];//讀取分十位數數碼資料輸出
     S1=0;      //選擇十位數顯示器
     Delay_ms(1);   //掃描延時
       
     S0=S1=S2=S3=1; //遮沒                     
     if(i<16)Data=~Table[hor%10];//讀取時個數數碼資料輸出
	    else Data=~(Table[hor%10] | 0x80);  //小數點亮
     S2=0;      //選擇百位數顯示器
     Delay_ms(1);   //掃描延時
       
     S0=S1=S2=S3=1; //遮沒
     Data=~Table[hor/10];//讀取時十位數數碼資料輸出
     S3=0;      //選擇千位數顯示器
     Delay_ms(1);   //掃描延時
}