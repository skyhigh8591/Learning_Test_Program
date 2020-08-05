//
//  配合"文字型LCD實習板"
//   在文字型LCD上顯示"1998年10月16日"
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit RS=P1 ^0 ;
sbit RW=P1 ^1 ;
sbit E=P1 ^2 ;
char code mes[]="1998\00010\00116\002" ;
char code CG[]={
	0x10 , 0x1f , 0x02 , 0x0f , 0x0a , 0xff , 0x02 , 0x00 , // 年
	0x0f , 0x09 , 0x0f , 0x09 , 0x0f , 0x09 , 0x13 , 0x00 , // 月
	0x0f , 0x09 , 0x09 , 0x0f , 0x09 , 0x09 , 0x0f , 0x00 , // 日
} ;
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
	char code *pp ;
	char i ;

	delay5ms() ;       // wait for LCD Power-on Ready
	Command(0x3f) ;    // 採用8位元資料存取/雙列字/5*10點矩陣字型
	Command(0xe) ;     //顯示器ON/游標被顯示在位址計數器
	Command(0x1) ;     // 清除全螢幕
	// 設定自定字型 年,月,日
	Command(0x40) ;   //設定CG RAM位址為0
	pp= CG ;
	for(i=0 ; i < 3*8 ; i++){
	    Data(*pp++) ;
	}
	Command(0x80) ;    // 設定DD RAM位址為0
	for(pp= mes,i=0; i<11 ;i++){
	    Data(*pp++);
	}
	for(;;) ;
}
