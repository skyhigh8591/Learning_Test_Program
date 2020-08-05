/************* 3_54.c ************************
*動作：LED遞加輸出，含延時函數
*硬體：SW1-3(P0LED)ON
**********************************************/
#include "..\MPC82.H"  //暫存器及組態設定
void delay(int count)	//將10000存入count內，但不傳回值
{
   while(count--);  //count遞減到0才退出函數
}

main()  //主程式
{
 unsigned char i=0;//計數值
 P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  loop:
    LED=~i;	   //計數值由LED輸出
    delay(10000); //呼叫自訂延時函數
    i++;	   //計數值遞加
    goto loop;
}

