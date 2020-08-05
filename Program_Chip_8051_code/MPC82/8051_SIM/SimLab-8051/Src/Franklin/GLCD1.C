//
//  配合"繪圖型LCD(橫排)實習板"
//   在繪圖型LCD上方顯示一橫線
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit DI=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
sbit CS1=P1^3 ;
sbit CS2=P1^4 ;
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
  	    DI=0;RW=1;E=1;
	    status= P0 ;
	    E=0 ;
	}
	while(status&0x80) ; // wait until BF=0

}
void Command(cmd){
	P0=cmd ;
	DI=0 ;RW=0; E=1;E=0 ; RW=1 ;
	waitlcd() ;
}
void Data(char data1){
	P0=data1;
	DI=1 ;RW=0; E=1;E=0 ;RW=1 ;
	waitlcd() ;
}
main()
{
	unsigned char i ;

	CS1=CS2=1 ;
	delay5ms() ;       // wait for LCD Power-on Ready
	Command(0x3f) ;    // DISPLAY ON

	Command(0xb8+0) ; // X addr = 0 ;
	Command(0x40+0) ; // Y Addr= 0 ;

	for(i=0; i< 64  ;i++){
	    Data(0x01);
	}
	for(;;) ;
}
