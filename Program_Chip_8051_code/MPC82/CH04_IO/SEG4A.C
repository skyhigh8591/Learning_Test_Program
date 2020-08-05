/*********** SEG4A.C ***************************
*動作：由四位數七段顯示器顯示電子鐘的時、分及秒為閃爍
*接線：Data=七段顯示器低電位輸出=Pgfedcba
*      低電位掃描：S3~0=千、百、十、個位數 
*硬體：SW1-1(SEG7)ON                            
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
code unsigned char Table[] //七段顯示器0~9數碼資料
={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

char hor=23,min=58,sec=52; //設定時、分、秒時間
void Display(char scan); //七段顯示器顯示時間值

main()
{   
  char scan=100;  //七段顯示器掃描次數，決時延時時間
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  while(1)
   {
    Display(scan); //七段顯示器顯示時間
		 if(KEY1==0) hor++;
		 if(KEY2==0) min++;
		 if(min>59){min=0;hor++;}
		 if(hor>23)hor=0;
		 
		 
		 
		 
		 
    sec++;               //秒加一
    if (sec < 60) continue; //若秒小於60到loop處   
    sec=0; min++;        //秒等於60則令秒=0，分加一
    if (min < 60) continue; //若分小於60到loop處   
    min=0; hor++;        //若分等於60則令分=0，時加一
    if (hor <24) continue; //若時小於24到loop處
    hor=0;min=0; sec=0; //若時等於24則令時、分、秒=0
   }
}
//***************************************************	 
void Display(char scan) //四位數七段顯示器顯示步數	 
{  
	
  while(scan--) //重覆掃描次數 
   {
     S0=S1=S2=S3=1; //遮沒 
     Data=~Table[min%10];//讀取分個位數數碼資料輸出
     S0=0;      //選擇個位數顯示器
     Delay_ms(1);   //掃描延時  
       
     S0=S1=S2=S3=1; //遮沒          
     Data=~Table[min/10];//讀取分十位數數碼資料輸出
     S1=0;      //選擇十位數顯示器
     Delay_ms(1);   //掃描延時
       
     S0=S1=S2=S3=1; //遮沒                     
     if(scan<50) Data=~Table[hor%10];//讀取時個數及秒閃爍輸出
     	else Data=~(Table[hor%10] | 0x80);//讀取時十數及秒閃爍輸出
	 S2=0;      //選擇百位數顯示器
     Delay_ms(1);   //掃描延時
       
     S0=S1=S2=S3=1; //遮沒
     Data=~Table[hor/10];//讀取分十位數數碼資料輸出
     S3=0;      //選擇千位數顯示器
     Delay_ms(1);   //掃描延時
   }	   
}