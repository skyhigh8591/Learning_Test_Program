/******* PCA1.C*********PCA溢位計時器範例********
*動作：由PCA計數溢位進行延時，令SPEAK(P10)反相輸出
*硬體：高頻SW2-5(SPK)ON,低頻SW1-4(P1LED)ON
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
//Fosc=22.1184MHz，PCA計數時脈=Fosc/12=1.8432MHz
#define T  14400  //PCA延時時間=(1/1.8432MHz)*14400=7812.5uS
main()         
{
  PCON2=7; //Fosc=Fosc/128，PCA延時時間=7812.5uS*128=1秒
  CMOD=0;      //PCA計數時脈來源CPS1-0:00=Fosc/12
 
  CR=1;       //啟動PCA計數
  CF=0;       //清除PCA溢位旗標0    
  while (1)   //不斷循環執行
   {
     SPEAK=!SPEAK;         //SPEAK反相
     CL= (65536-T) % 256; //將低8-bit計數值存入CL 
     CH= (65536-T) / 256; //將高8-bit計數值存入CH
     while(CF==0);        //等待溢位，若CF=0自我循環
     CF=0;                //若計時溢位CF=1，清除CF=0  
   }
}
