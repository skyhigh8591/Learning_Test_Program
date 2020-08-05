/************* 3_55.c ***********************
*動作：LED遞加輸出，含延時函數
*硬體：SW1-3(P0LED)ON
********************************************/
#include "..\MPC82.H"  //暫存器及組態設定
void delay(int count);  //宣告自訂函數
main()
{
   unsigned char i=0;  //計數值
   int dly=10000;      //空轉次數
   P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)  
 loop:
    LED=~i;  
    delay(dly); //呼叫自訂延時函數，將整數變數送入函數內
    i++;
    goto loop;
}
//***************************************************
void  delay(int count) //有傳入引數count，不回傳資料
 {
    while (count>0)   //空轉count(dly)次
     count--;
 }