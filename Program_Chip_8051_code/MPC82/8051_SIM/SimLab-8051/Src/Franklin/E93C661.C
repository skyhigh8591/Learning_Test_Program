//
//  配合"EEPROM 93C66實習板"
//   讀取93C66位址00的內容
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
sbit EEPROMCS=P0 ^0 ;
sbit EEPROMSK=P0 ^1 ;
sbit EEPROMDI=P0 ^2 ;
sbit EEPROMDO=P0 ^3 ;
#define CLOCK  EEPROMSK=0 ; EEPROMSK=1 ;
#define SEND(DI)   EEPROMDI=DI ;CLOCK ;
main()
{
	unsigned int Data ;
	unsigned char i ;

	P0=0xff ;
	//  設定 CS,SK 到初值
EEPROMCS=0 ;
EEPROMSK=0 ;

	EEPROMCS=1 ;
	// 啟始位元
	SEND(1) ;
	// 指令  10
	SEND(1) ; SEND(0) ;
	// 位址 00000000
	for(i=0 ; i < 8 ; i++){
	    SEND(0) ;
	}
	if(EEPROMDO==0){
	    Data=0 ;
	    for(i=0 ; i < 16 ; i++){
		CLOCK ;
		Data <<=1 ;
		if(EEPROMDO== 1){
		    Data++ ;
		}
	    }
	}
	EEPROMCS=0 ;
	for(;;) ;
}
