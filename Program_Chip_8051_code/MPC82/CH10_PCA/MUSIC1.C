/*** MUSIC1.C*********PCA高速輸出音樂範例************
*動作：PCA高速輸出，PCA中斷控制CEX0(P12)腳輸出音樂
*硬體：SW2-6(SPK)ON
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#define  T      22118400/12/2 //基本頻率T=Fosc/12/2=921600Hz
#define  DO     T/523   //各種音頻的計時器內容
#define  RE     T/587
#define  MI     T/659
#define  FA     T/698
#define  SO     T/785
#define  LA     T/880
#define  TI     T/998	     

unsigned int  code Table[] //音頻的陣列資料 
        = { DO,RE,MI,FA,SO,LA,TI };
char i;   //資料計數	     
unsigned int  Temp;
main()         
{
  CCAPM0 = ECOM+MAT+TOG+ECCF; //MAT=1，PAC計數與CCAP0匹配時，令CCF0=1
                              //ECOM=1，致能比較器功能
					          //TOG=1，(CH:CL)=CCAP0時，令CEX0腳反相
						      //ECCF=1，致能有匹配(CCF0=1)時，產生中斷
 
  EA = 1;       //致能所有中斷
  AUXIE = EPCA; //致能PCA中斷
  CCF0 = 0;		//清除模組0的比較旗標
  while(1)      //重覆執行
  {
   for(i=0;i<7;i++) //輸出7個音階
    {
      Temp=Table[i];  //讀取陣列音頻資料
      CCAP0L=Temp;	  //設定比較暫存器低位元組
      CCAP0H=Temp>>8; //設定比較暫存器高位元組
      CR = 1;         //啟動PCA計數，開始發音
	  Delay_ms(500);  //延時，發音的時間，等待(CH:CL)=CCAP0產生中斷
      CR = 0;         //停止PCA計數，停止發音
    }
    Delay_ms(1000);   //延時，停止發音的時間
  }
}
/***********************************************************
*函數名稱: PCA中斷函數
*功能描述: 自動令CEX0反相
************************************************************/
void PCA_Interrupt() interrupt 10
{
  CCF0 = 0;	    //清除模組0的比較旗標
  CL = CH =0;   //PCA計數器由0開始上數
}