/*********** 3_5.c ******************************************
*動作：由RAM讀取陣列資料由LED輸出
*硬體：SW1-3(P0LED)ON
*************************************************************/
#include "..\MPC82.H"  //暫存器及組態設定
unsigned char TABLE[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
main()
{  
    P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  loop:
    LED=~TABLE[0];Delay_ms(100); //LED=0x01
    LED=~TABLE[1];Delay_ms(100); //LED=0x02
    LED=~TABLE[2];Delay_ms(100); //LED=0x04
    LED=~TABLE[3];Delay_ms(100); //LED=0x08
    LED=~TABLE[4];Delay_ms(100); //LED=0x10
    LED=~TABLE[5];Delay_ms(100); //LED=0x20
    LED=~TABLE[6];Delay_ms(100); //LED=0x40
    LED=~TABLE[7];Delay_ms(100); //LED=0x80
   goto loop;  
}