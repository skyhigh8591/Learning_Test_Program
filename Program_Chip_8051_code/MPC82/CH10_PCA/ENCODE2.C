/********** ENCODE2.c ********四倍解析編碼器實習範例***************
*動作：將ENCODE旋轉時所產生的A、B相信號，送到捕捉器CEX4(P16)
       及CEX5(P17)作為觸發輸入信號，在LED顯示馬達正反轉數值
*硬體：SW1-3(P0LED)ON。由P12及P13模擬ENCODE信號，
*       連接(或反接)P16及P17，可改變LED上/下數，SW1-3(P0LED)ON。
*      或在J9連接ENCODE，正/反旋轉，可改變LED上/下數
***********************************************************/
#include "..\MPC82.H"  //暫存器及組態定義
unsigned int count=0;
main()          
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  EA = 1; AUXIE = EPCA; //致能PCA中斷
  CCF4 = 0;	   //清除模組4的比較旗標
  CCAPM4 = CCAPM5 = ECCF+CAPN; //CEX4(P16)及CEX5(P17)負緣中斷
  CR = 1;       //啟動PCA計數 
  LED=~count;   //計數由LED輸出

  P1_2=P1_3=0;  //模擬ENCODE的動作
  while(1)
  {
   P1_2=1; Delay_ms(500);
   P1_3=1; Delay_ms(500);
   P1_2=0; Delay_ms(500);
   P1_3=0; Delay_ms(500);
  }  
}
/***********************************************************
*函數名稱: PCA中斷函數
*功能描述: 自動令CEX0反相
************************************************************/
void PCA_Interrupt() interrupt 10
{
  CF=0;		 //清除PCA計數溢位旗標
  if(CCF4)	 //若是模組4的比較旗標
   {
     CCF4 = 0; //清除模組4的比較旗標
	 if(CCAPM4 & CAPN) 	//檢查CEX4是否為負緣輸入
	   {
	    CCAPM4 = ECCF+CAPP; //若是負緣下次改為正緣
   	   	if(P1_7) count++;   //若正轉，計數遞加
          else count--;     //若反轉，計數遞減
	   	}
	    else 	  //檢查CEX4為正緣輸入
		 {
		  CCAPM4 = ECCF+CAPN; //若是正緣下次改為負緣 
	 	  if(!P1_7) count++;  //若正轉，計數遞加
            else count--;     //若反轉，計數遞減
		 }
   }

   if(CCF5)	 //若是模組5的比較旗標
   {
     CCF5 = 0;	  //清除模組5的比較旗標
	 if(CCAPM5 & CAPN) 	 	//檢查CEX5是否為負緣輸入
	   {
	    CCAPM5 = ECCF+CAPP; //若是負緣下次改為正緣
   	   	if(P1_6) count--;   //若反轉，計數遞減
          else count++;     //若正轉，計數遞加
	   	}
	    else 	 //檢查CEX5為正緣輸入
		 {
		  CCAPM5 = ECCF+CAPN; //若是正緣下次改為負緣 
	 	  if(!P1_6) count--;  //若反轉，計數遞減
            else count++;     //若正轉，計數遞加
		 }
   }
  LED=~count;       //計數由LED輸出
}