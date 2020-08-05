/********** CAP3.c ********捕捉器中斷實習範例***************
*動作：令Timer2由T2CKO(P10)輸出方波,送到CEX0(P12)捕捉輸入
*      ，在LED顯示時間差
*硬體：SW1-3(P0LED)ON，將T2CKO(P10)連接到CEX0(P12)
***********************************************************/
#include "..\MPC82.H"  //暫存器及組態定義
#define T 0x56 //T2CKO頻率=Fosc/4/(65536-T2)=22118400/4/T			    
  unsigned int old=0;	//第一次CCAP0捕捉時間

main()          
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  T2CON=0x00; /* 0000 0000，設定為內部計時，溢位重新載入
                 bit3:EXEN2=0,不使用外部T2EX接腳
			     bit1:C/T2=0,內部計時 */
  RCAP2=T2R=65536-T; //設定Timer2及重新載入時間
  TR2=1;        //啟動Timer2開始計時
  T2MOD=T2CKOE; //致能T2CKO(P10)輸出方波
  
  EA = 1; AUXIE = EPCA; //致能PCA中斷
  CCF0 = 0;	   //清除模組0的比較旗標
  CMOD = CPS0; //PCA時脈來源:CPS1-0:01=Fosc/2,配合T2CKO=Fosc/4/(65536-T2)
  CCAPM0 = CAPP+CAPN+ECCF; //CAPP=1，正緣觸發輸入時，CCAP0<--CH:CL)
  CR = 1;        //啟動PCA計數 
  while(1);
}
/***********************************************************
*函數名稱: PCA中斷函數
*功能描述: 自動令CEX0反相
************************************************************/
void PCA_Interrupt() interrupt 10
{
  CF=0;			//清除PCA計數溢位旗標
  CCF0 = 0;	    //清除模組0的比較旗標
  if((CCAP0L-old)>0) //捕捉CPA計數值
    LED=~(CCAP0L-old) ; //將兩次CPA計數值的時間差(T)由LED輸出
  old=CCAP0L;

}