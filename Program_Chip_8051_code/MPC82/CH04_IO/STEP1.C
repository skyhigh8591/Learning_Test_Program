/*********** STEP1.C ****************************
*動作：將驅動數碼存在陣列資料，由STEP輸出驅動步進馬達運轉
*接線：步進馬達輸出：P14=A,P15=B,P16=/A,P17=/B
*硬體：SW1-3(P0LED)ON及SW2-1~4(STEP)ON
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義//驅動數碼
//unsigned char run_Table[]={0x1,0x2,0x4,0x8};//單相全步運轉
//unsigned char run_Table[]={0x3,0x6,0xC,0x9};//雙相全步運轉
unsigned char run_Table[]={0x9,0x1,0x3,0x2,0x6,0x4,0xC,0x8};//單雙相半步運轉,改為8步
void main()
{
  char i;     //定義資料計數
  P1M0=0; P1M1=0xF0; //設定P17-4(STEP)為推挽式輸出(M0-1=01)
  STEP=0x00;   //步進馬達初值：P17-4=0000
  while(1) 
   {
       for(i=0;i<sizeof(run_Table);i++)   //資料計數由0-->3,步進馬達正轉
     //for(i=sizeof(run_Table)-1;i>=0;i--) //資料計數由3-->0,步進馬達反轉
       {
       LED=~run_Table[i];     //讀取驅動數碼由LED輸出 
       STEP=run_Table[i]<<4;  //讀取驅動數碼由步進馬達輸出
       Delay_ms(100);  //延時時間  
     } 
  } 
}