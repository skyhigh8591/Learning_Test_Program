/********** Timer2_7.C ****************************
*動作：令Timer2由T2CKO(P10)輸出音樂
*硬體：SW2-5(SPK)ON
**********************************************/
#include "..\MPC82.H"  //暫存器及組態定義
#include "music2.h"    //T2CKO音頻定義
unsigned int  code Table[]  //定義音頻陣列資料,0為休止符  
   ={DO3,0,RE3,0,MI3,0,FA3,0,SO3,0,LA3,0,SI3,0,DO4,0};
char i;   //資料計數			    
main()          
{
  T2CON=0x00; /* 0000 0000，設定為內部計時，溢位重新載入
                 bit3:EXEN2=0,不使用外部T2EX接腳
	             bit1:C/T2=0,內部計時 */
  T2MOD=T2CKOE; //致能T2CKO(P10)輸出方波
  while (1)    //不斷循環執行
  {
   for(i=0; i<16; i++)   //陣列計數由0~15遞加  
    {
     if(Table[i]==0) {TR2=0; SPEAK=0;} //若資料=0為停止Timer2計時
	   else
	    {	
	      RCAP2=T2R=Table[i]; //設定Timer2及重新載入時間     
          TR2=1;    //啟動Timer2開始計時
	    }
      Delay_ms(1000); //音長 
      TR2=0;          //停止Timer2計時 
    }
  }
}	

