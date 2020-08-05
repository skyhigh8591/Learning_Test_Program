//
//
//   Read the content of 93C46 at address 00
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
	//  Setting CS,SK to initial state
EEPROMCS=0 ;
EEPROMSK=0 ;

	EEPROMCS=1 ;
	// start bit
	SEND(1) ;
	// command  10
	SEND(1) ; SEND(0) ;
	// address 000000
	for(i=0 ; i < 6 ; i++){
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
