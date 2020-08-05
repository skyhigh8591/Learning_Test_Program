//
//  配合"文字型LCD實習板"
//   在文字型LCD上顯示"Hello!!"用檢查BF的方式和LCD同步,使用位元運算指令) 
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit RS=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
char code mes[]="Hello!!" ;
void delay5ms()
{
	char i=0 ;
	for(i=0 ; i < 5 ; i++) Delay1ms();
}
void waitlcd()
{
	unsigned char status;

	P0=0xff ; // P0設定為輸入埠
	do{
  	    RS=0;RW=1;E=1;
	    status= P0 ;
	    E=0 ;
	}
	while(status&0x80) ; // wait until BF=0

}
void Command(cmd){
	P0=cmd ;
	RS=0 ; RW=0 ; E=1;E=0 ;RW=1 ;
	waitlcd() ;
}
void Data(char data1){
	P0=data1;
	RS=1 ;RW=0;E=1;E=0 ;RW=1 ;
	waitlcd() ;
}
main()
{
	char code *pp=mes ;

	delay5ms() ;       // wait for LCD Power-on Ready
	Command(0x3f) ;    // 採用8位元資料存取/雙列字/5*10點矩陣字型
	Command(0xe) ;     //顯示器ON/游標被顯示在位址計數器
	Command(0x1) ;     // 清除全螢幕 
	delay2ms() ;
 	Command(0x80) ;    // 設定DD RAM位址為0
	for(; *pp !=0 ;){
	    Data(*pp++);
	}
	for(;;) ;
}
