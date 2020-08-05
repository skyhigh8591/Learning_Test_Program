//
//
//   Display "Hello!!" on Text LCD ( synchronize by checking BF method , and bit operation instruction)
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

	P0=0xff ; // P0 set to input port
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
	Command(0x3f) ;    // 8 bits data bus/2 lines/5*10 dots
	Command(0xe) ;     // display ON
	Command(0x1) ;     // clear display
	delay2ms() ;
 	Command(0x80) ;    // DD RAM address=0
	for(; *pp !=0 ;){
	    Data(*pp++);
	}
	for(;;) ;
}
