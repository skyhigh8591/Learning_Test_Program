//
//
//   Write the value (5678h) to  93C46 at address 00
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
	// write enable
	EEPROMCS=1 ;
	// start bit
	SEND(1) ;
	// command  00
	SEND(0) ; SEND(0) ;
	// sub-command 11
	SEND(1) ; SEND(1) ;
	// 4-'X' Bit
	for(i=0 ; i < 4 ; i++){
	    SEND(0) ;
	}
	EEPROMCS=0 ;


	//  Write the value (5678h) to  93C46 at address 00
	EEPROMCS=1 ;
	// start bit
	SEND(1) ;
	// command  01
	SEND(0) ; SEND(1) ;
	// address 000000
	for(i=0 ; i < 6 ; i++){
	    SEND(0) ;
	}
	// send out data
	Data=0x5678 ;
	for(i=0 ; i < 16 ; i++){
	    if(Data & 0x8000){
		SEND(1) ;
	    }
	    else{
		SEND(0) ;
	    }
	    Data <<=1 ;
	}
	EEPROMCS=0 ;
	// wait ready
	EEPROMCS=1 ;
	while(!EEPROMDO){
	    CLOCK ;
	}

	//write disable
	EEPROMCS=1 ;
	//Start bit
	SEND(1) ;
	// command 00
	SEND(0) ; SEND(0) ;
	// sub-command 00
	SEND(0) ; SEND(0) ;
	for(i=0 ; i < 4 ; i++){
	    SEND(0) ;
	}
	EEPROMCS=0 ;

	for(;;) ;
}
