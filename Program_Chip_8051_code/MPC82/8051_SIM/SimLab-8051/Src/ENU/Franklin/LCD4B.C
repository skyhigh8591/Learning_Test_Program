//
//   Display 4 "Hello!!" on Text LCD,
//     at line 1 location 1 , line 1 location 11 ,
//       line 2 location 1 , and line 2 location 11
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit RS=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
char code mes[]="Hello!!" ;
#define DSPSTR(loc)		\
	Command(loc) ;		\
	for(pp=mes; *pp !=0 ;){	\
	    Data(*pp++);		\
	}

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
	char code *pp ;

	delay5ms() ;       // wait for LCD Power-on Ready
	Command(0x3f) ;    // 8 bits data bus/2 lines/5*10 dots
	Command(0xe) ;     // display ON
	Command(0x1) ;     // clear display

	DSPSTR(0x80) ;          // line 1 location 1
	DSPSTR(0x80+10) ;       // line 1 location 11
	DSPSTR(0x80+0x40) ;     // line 2 location 1
	DSPSTR(0x80+0x40+10) ;  // line 2 location 11
	for(;;) ;
}
