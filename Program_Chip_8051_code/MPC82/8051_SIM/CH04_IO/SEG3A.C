/************ SEG3A.C ***************************
*動作：四位數掃描計數器，以十進制顯示-1999~1999
*接線：Data=七段顯示器低電位輸出=Pgfedcba
*      低電位掃描：S3~0=千、百、十、個位數
*硬體：SW1-1(SEG7)ON
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
 unsigned char code Table[] //0~F數碼資料
  ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
 main() 
{
  unsigned char scan;      //掃描次數  
  int count,temp=90; //計數十進制初值 
  unsigned char i;    //擷取計數的個、十、百、千位數 
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
   while(1)     //重覆執行
    {
	 if(temp<0)  count=-temp; 
	 	 else count=temp;
	  for(scan=0;scan<10;scan++) //重覆掃描次數 
      {
       S0=S1=S2=S3=1;      //遮沒
	   i=count % 10;       //取出個位數
       Data=~Table[i];     //讀取個位數碼資料輸出
       S0=0;               //選擇個位數顯示器
       Delay_ms(1);        //掃描延時  
       
	   S0=S1=S2=S3=1;      //遮沒           
       i=(count % 100)/10; //取出十位數 
       Data=~Table[i];     //讀取十位數碼資料輸出
       if(count>9) S1=0;   //若計數>9，顯示十位數
       Delay_ms(1);        //掃描延時
                            
       S0=S1=S2=S3=1;       //遮沒
	   i=(count % 1000)/100;//取出百位數
       Data=~Table[i];      //讀取百位數碼資料輸出
       if(count>99) S2=0;   //若計數>99，顯示百位數
       Delay_ms(1);         //掃描延時
       
	   S0=S1=S2=S3=1;       //遮沒
       //i=count/1000;        //取出千位數
       if(temp>999 | temp<0) 
	   {
	     S3=0;	 
		 if(temp>999) Data=~Table[1];
		 if(temp<0)   Data=~0x40;
		 if(temp<-999)Data=~(Table[1] | 0x40);
	   }
	   Delay_ms(1);         //掃描延時
     }	   
     //temp++;  if(temp>1999) temp=-1999; //若計數超過9999，計數=0
     temp--;  if(temp<-1999) temp=1999;
   } 
}