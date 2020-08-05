/********SPI_SD1.C***********SD記憶卡存取範例*****************
*功能︰將陣列資料寫入緩衝器，再藉由SPI界面寫入SD記憶卡內，
*      再讀取SD記憶卡內容存入緩衝器，逐一在LED輸出。
*附加：SD.LIB或SD.C
*硬體：SW1-3(P0LED)ON，將SD卡插入J29
**********************************************************/
#include "..\MPC82.H"
#include "SD.H"
#include "TABLE8.H"	 //256-byte陣列資料
unsigned char xdata buffer[512] = {0}; //在擴充RAM宣告緩衝器

void main( void )
{
  int i;	  //計數值
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  initSD(); //初始化SD卡
  //for(i=0;i<256;i++) buffer[i]=TABLE[i];  //將陣列資料寫入in緩衝器
  
  //SDWriteBlock(1, buffer);	//緩衝器寫入SD記憶區塊1
  //for (i=0;i<256;i++) buffer[i]=0xff;//填滿緩衝器

  SDReadBlock(1, buffer);	//讀取SD記憶區塊1的內容到緩衝器
 
  while (1)  //緩衝器的內容重覆由LED輸出
   {
    for (i = 0; i < 256; i++) 
     {
	   LED=~buffer[i];//緩衝器的內容送到LED顯示
       Delay_ms(100); //延時
	 }
   }
}
