//
//  配合"文字型LCD實習板"
//   在文字型LCD上做雙列字左(右)移
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit RS=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
char code mes1[]="          111111111122222222223333333333" ;
char code mes2[]="0123456789012345678901234567890123456789" ;
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
	Command(0x3f) ;   // 採用8位元資料存取/雙列字/5*10點矩陣字型
	Command(0xe) ;    //顯示器ON/游標被顯示在位址計數器
	Command(0x1) ;    // 清除全螢幕
	delay2ms() ;
	Command(0x80) ;   // 設定DD RAM位址為0
	for(; *pp !=0 ;){
	    Data(*pp++);
	}
	Command(0xC0) ;   // 設定DD RAM位址為40H(第二行) 
	pp=mes2 ;
	for(; *pp !=0 ;){
	    Data(*pp++);
	}
	for(;;){
	    Command(0x18) ;// 0x18---左移/0x1c----右移
	    Delay1s() ;
	}
}
