//
//  配合"文字型LCD實習板"
//   在文字型LCD上顯示"Hello!!"(用延遲的方式和LCD同步) 
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
	Command(0x3f) ;         // 採用8位元資料存取/雙列字/5*10點矩陣字型
	Command(0xe) ;          //顯示器ON/游標被顯示在位址計數器
	Command(0x1) ;          // 清除全螢幕
	delay2ms() ;
	Command(0x80) ;         // 設定DD RAM位址為0
	for(; *pp !=0 ;){
	    Data(*pp++);
	}
	for(;;) ;
}
