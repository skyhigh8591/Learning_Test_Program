//
//
//   Display "1998"nian"10"yue"16"ri"" on Text LCD
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit RS=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
char code mes[]="1998\00010\00116\002" ;
char code CG[]={
	0x10 , 0x1f , 0x02 , 0x0f , 0x0a , 0xff , 0x02 , 0x00 , // "nian"
	0x0f , 0x09 , 0x0f , 0x09 , 0x0f , 0x09 , 0x13 , 0x00 , // "yue"
	0x0f , 0x09 , 0x09 , 0x0f , 0x09 , 0x09 , 0x0f , 0x00 , // "ri"
} ;
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
	char i ;

	delay5ms() ;       // wait for LCD Power-on Ready
	Command(0x3f) ;    // 8 bits data bus/2 lines/5*10 dots
	Command(0xe) ;     // display ON
	Command(0x1) ;     // clear display
	// define font of  "nian" "yue" "ri"
	Command(0x40) ;   // CG RAM address=0
	pp= CG ;
	for(i=0 ; i < 3*8 ; i++){
	    Data(*pp++) ;
	}
	Command(0x80) ;    // DD RAM address=0
	for(pp= mes,i=0; i<11 ;i++){
	    Data(*pp++);
	}
	for(;;) ;
}
