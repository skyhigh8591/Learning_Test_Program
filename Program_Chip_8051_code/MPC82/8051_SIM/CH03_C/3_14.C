/***** 3_14.c ****16-bit陣列輸出動作範例********
*動作：由LED0-1輸出16-bit陣列動作
*硬體：SW1-3(P0LED)及SW1-4(P1LED)ON
************************************************/
#include "..\MPC82.H"  //暫存器及組態設定
#include "TABLE16.H"  //定義ROM內256筆16-bit陣列資料
main()
{
    unsigned char i;  //宣告資料計數變數
    P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  loop:
    LED0=~TABLE[i];        //讀取陣列資料，低8-bit輸出
    LED1=~(TABLE[i] >> 8); //讀取陣列資料，高8-bit輸出
    Delay_ms(100);    //延時
    i++;              //資料計數加1
    goto loop;
}