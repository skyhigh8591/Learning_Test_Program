//
//
//   Display "Hello!!" on Text LCD (synchronize by delay method)
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
char code mes[]="Hello!!" ;
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
	P1=0x4 ;    //E=1 , RW=0 , RS=0
	P1=0;       //E=0 , RW=0 , RS=0
	delay40us() ;
}
void Data(char data1){
	P0=data1;
	P1=0x5;     //E=1 , RW=0 , RS=1
	P1=0x1 ;    //E=0 , RW=0 , RS=1
	delay40us() ;
}
main()
{
	char code1 ;
	char i ;
	char code *pp=mes ;
	delay5ms() ;            // wait for LCD Power-on Ready
	Command(0x3f) ;         // 8 bits data bus/2 lines/5*10 dots
	Command(0xe) ;          // display ON
	Command(0x1) ;          // clear display
	delay2ms() ;
	Command(0x80) ;         // DD RAM address=0
	for(; *pp !=0 ;){
	    Data(*pp++);
	}
	for(;;) ;
}
