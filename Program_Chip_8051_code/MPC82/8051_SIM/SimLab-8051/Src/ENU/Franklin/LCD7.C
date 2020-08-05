//
//
//   Test Text LCD in single-line shift the left(right) mode
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit RS=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
char code mes1[]="0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 " ;
void delay2ms()
{
	Delay1ms() ;
	Delay1ms() ;
}
void delay5ms()
{
	delay2ms() ;
	delay2ms() ;
	Delay1ms() ;
}
void delay40us()
{
	int i ;
	for(i=0 ; i < 5 ;i++) ;
}
void Command(cmd){
	P0=cmd ;
	RS=0 ; RW=0 ; E=1;E=0 ;
	delay40us() ;
}
void Data(char data1){
	P0=data1;
	RS=1 ;RW=0;E=1;E=0 ;
	delay40us() ;
}
main()
{
	char code1 ;
	char i ;
	char code *pp=mes1 ;

	delay5ms() ;      // wait for LCD Power-on Ready
	Command(0x37) ;   // 8 bits data bus/1 lines/5*10 dots
	Command(0xe) ;    // display ON
	Command(0x1) ;    // clear display
	delay2ms() ;
	Command(0x80) ;   // DD RAM address=0
	for(; *pp !=0 ;){
	    Data(*pp++);
	}
	for(;;){
	    Command(0x18) ;// 0x18---left shift/0x1c----right shift
	    Delay1s() ;
	}
}
