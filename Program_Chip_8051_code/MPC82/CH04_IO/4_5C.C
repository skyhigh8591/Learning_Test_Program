/********** 4_5C.C ****************************
*動作：每按一次按鍵，令LED有6種變化
*硬體：SW1-3(P0LED)ON, 按KEY1 
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
char flag=0;    //設定變數 
 #define F     600	//定義音頻常數
#define T     600	//定義音長常數
#define STOP  1000	//定義停止時間常數
unsigned int i,dly;
main() 
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  while(1)       //重覆執行 
   {		     //若flag=0，直接跳到此處
     if(KEY1==0)      //若有按鍵，flag反相
	  {
        Delay_ms(1); //延時，防止機械彈跳	   
        flag++; if(flag>5) flag=0;   
	    while(KEY1==0); //若未放開鍵，空轉 
	  }
		switch (flag)
    {
    	case  0:
				
				for(i=0;i<700;i++) //輸出反相次數，決定音長
        {
	        SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
		      dly=700; while(dly--);  //音頻延時
        }
	     SPEAK=0; Delay_ms(STOP); //喇叭停止，間隔時間
    	break;
			
    	case  1:
				
    		for(i=0;i<100;i++) //輸出反相次數，決定音長
        {
	        SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
		      dly=100; while(dly--);  //音頻延時
        }
	     SPEAK=0; Delay_ms(STOP); //喇叭停止，間隔時間
    	break;
	
    	case  2:
				
    		for(i=0;i<400;i++) //輸出反相次數，決定音長
        {
	        SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
		      dly=400; while(dly--);  //音頻延時
        }
	     SPEAK=0; Delay_ms(STOP); //喇叭停止，間隔時間
    	break;
	
    	case  3:
				
    		for(i=0;i<200;i++) //輸出反相次數，決定音長
        {
	        SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
		      dly=550; while(dly--);  //音頻延時
        }
	     SPEAK=0; Delay_ms(STOP); //喇叭停止，間隔時間
    	break;
	
    	case  4:
				
    		for(i=0;i<800;i++) //輸出反相次數，決定音長
        {
	        SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
		      dly=320; while(dly--);  //音頻延時
        }
	     SPEAK=0; Delay_ms(STOP); //喇叭停止，間隔時間
    	break;
				
    	default:
				 
    		break;
    }
		
	 Delay_ms(100); //延時             
   }
}