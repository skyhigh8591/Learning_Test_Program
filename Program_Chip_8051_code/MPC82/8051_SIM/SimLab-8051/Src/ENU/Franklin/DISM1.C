//
//
//   Get keycode from keyboard ,then display on Text LCD
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit RS=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
void delay20ms() ;
unsigned char code IdxCol[]= {
	0 , 1 , 0 , 2 ,
	0 , 1 , 0 , 3 ,
	0 , 1 , 0 , 2 ,
	0 , 1 , 0 , 4
} ;
char code *keycode[]= {
	"0","1","2","3" ,
	"4","5","6","7" ,
	"8","9","A","B" ,
	"C","D","E","F" ,
	"F1","F2","F3","CR" ,
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
	RS=0 ; RW=0 ; E=1;E=0 ; RW=1 ;
	waitlcd() ;
}
void Data(char data1){
	P0=data1;
	RS=1 ;RW=0;E=1;E=0 ; RW=1 ;
	waitlcd() ;
}
main()
{
	unsigned char row ;
	char keyflag ;
	char tP1 ;
	char key ;
	char code *ptr ;

	delay5ms() ;       // wait for LCD Power-on Ready
	Command(0x3f) ;    // 8 bits data length/2 lines/5*10 dots
	Command(0xe) ;     // display ON
	Command(0x1) ;     // clear display
	Command(0x80) ;    // DD RAM address  is  0
	for(;;){
	    do{
		for(P1=tP1=0xf7,row=0 ,keyflag=0 ; (row < 5);row++){
		    if((P2&0xf) != 0xf){
			keyflag=1 ;
			break ;
		    }
		    tP1 <<=1 ;
		    tP1 |=0x7 ;
		    P1=tP1 ;
		}
		if(keyflag== 1){
		    delay20ms() ;
		    if((P2&0xf) ==0xf){
			keyflag= 0 ;
		    }
		}
	    }
	    while(keyflag==0) ;
	    key=row*4+IdxCol[P2&0xf];
	    do{
		while((P2&0xf) != 0xf) ;
		delay20ms() ;
	    }
	    while((P2 &  0xf) != 0xf) ;
	    ptr= keycode[key] ;
	    while(*ptr !=0){
		Data(*ptr++);
	    }
	}
}
void delay20ms()
{
	char i ;
	for(i=0 ; i < 2 ;i++) Delay10ms();
}
