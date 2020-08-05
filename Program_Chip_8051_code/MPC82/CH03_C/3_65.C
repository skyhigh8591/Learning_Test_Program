//*********3_65.C********多檔案程式範例********************
//功能︰令LED遞加輸出延時
//附加：io.c或io.lib
//硬體：SW1-3(P0LED)ON
//********************************************************
#include "..\MPC82.H"  //暫存器及組態定義
extern void Delay(unsigned int dly) ; //宣告Delay函數在外面
main()
{       
  unsigned char i=0;
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  while(1) //重覆執行
  { 
    LED=~i++;     //遞加輸出
    Delay(200);   //延時 
  }
}